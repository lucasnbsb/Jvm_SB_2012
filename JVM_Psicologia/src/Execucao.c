/*
 * Execucao.c
 *
 *  Created on: 21/02/2013
 *      Author: Vitor
 */

#include "Execucao.h"
#include "ClassLoader.h"
#include "ClassFile.h"
#include "Frame.h"
#include "FuncoesGerais.h"

// Fun��o que inicializa a lista com o endere�o NULL
void inicializaClassFileLista(listaClasses** endInicioLista){
	*endInicioLista = NULL;
}

// Fun��o que adiciona um novo class file carregado � lista encadeada simples de classes
void insereClassFileLista(listaClasses** endInicioLista, ClassFile cf){

	listaClasses* p1;
	listaClasses* p2;
	u2 indiceNomeField;
	u2 indiceDescritorField;
	int i;
	int j;

	p1 = malloc (sizeof(listaClasses));
	p1->cf = cf;
	p1->numStaticFields = 0; // Inicializando para a contagem

	// Primeiro, contamos os static fields
	for(i = 0; i < cf.fields_count; i++){
		// Se a flag static estiver ativa, o field � static
		if ((cf.fields[i].accessFlags & ACC_STATIC) != 0){
			p1->numStaticFields++;
		}
	}

	// Depois, alocamos o espa�o necess�rio para eles
	p1->staticFields = malloc(sizeof(field) * p1->numStaticFields);

	j = 0;

	// E agora, preenchemos com os devidos valores
	for(i = 0; i < cf.fields_count; i++){

		indiceNomeField = cf.fields[i].nameIndex;
		indiceDescritorField = cf.fields[i].descriptorIndex;

		if ((cf.fields[i].accessFlags & ACC_STATIC) != 0){
			p1->staticFields[j].nome = cf.constant_pool[indiceNomeField].info.UTF8Info.bytes;
			p1->staticFields[j].descritor = cf.constant_pool[indiceDescritorField].info.UTF8Info.bytes;
			p1->staticFields[j].valor.tipoLong = 0; // Inicializo o long com 0 pois ele representa o maior membro da Union, preenchendo tudo com 0

			j++;
		}
	}

	p1->listaObjetos = NULL;

	if (*endInicioLista == NULL){
		*endInicioLista = p1;
	}
	else{
		p2 = *endInicioLista;

		while (p2->proxClasse != NULL){
			p2 = p2->proxClasse;
		}
		p2->proxClasse = p1;
	}

	p1->proxClasse = NULL;

}

// Fun��o que inicia e executa um m�todo
void preparaExecucaoMetodo (char* nomeClasse, char* nomeMetodo, char* descriptor, execucao *p, int numArgs){

	ClassFile* cf;
	pilhaOperandos* pilhaAux;
	int i;
	int numIndicesNecessarios = 0;
	int operandoTipo;

	cf = buscaClassFileNome(p->pInicioLista, nomeClasse);

	// Se cf for NULL, isso quer dizer que ainda temos que carregar a classe na mem�ria
	if (cf == NULL){
		cf = malloc (sizeof(ClassFile));
		*cf = carregaClassFile(nomeClasse);
		insereClassFileLista(&(p->pInicioLista), *cf);

		// Executando o bloco que inicializa os par�metros statics
		// Caso ele exista
		if(buscaMetodoNome(*cf, "<clinit>", "()V") != NULL){
			preparaExecucaoMetodo(nomeClasse, "<clinit>", "()V", p, 0);
			executaMetodo(p);
		}
	}

	// Aloca a frame nova e a coloca na pilha de frames
	pushFrame(&(p->frameAtual));

	// Preenche a frame alocada
	// A lista de classes � passada caso o m�todo n�o seja encontrado
	// no ClassFile passado
	inicializaFrame(p->pInicioLista, *cf, p->frameAtual, nomeMetodo, descriptor);

	// Esse bloco se refere a passagem de argumentos para o array local do novo frame
	// Se a frame abaixo for NULL ent�o � o m�todo main que est� passando por essa fun��o
	if (p->frameAtual->frameAbaixo != NULL){

		inicializaPilha(&pilhaAux);

		// Agora, temos que contar quantos �ndices iremos usar no array local
		// Para tal, usaremos uma pilha de operandos auxiliar, que ser� preenchida
		// com os elementos da pilha de operandos da frame abaixo
		for (i = 0; i < numArgs; i++){
			operandoTipo = p->frameAtual->frameAbaixo->topoPilhaOperandos->operandoTipo1;
			pushOperando(&pilhaAux, popOperando(&(p->frameAtual->frameAbaixo->topoPilhaOperandos)), operandoTipo);

			if (operandoTipo == TIPO2){
				numIndicesNecessarios++;
			}
			numIndicesNecessarios++;

		}

		// Agora, temos que devolver os operandos para a pilha original
		for (i = 0; i < numArgs; i++){
			operandoTipo = pilhaAux->operandoTipo1;
			pushOperando(&(p->frameAtual->frameAbaixo->topoPilhaOperandos), popOperando(&pilhaAux), operandoTipo);
		}

		// Passa os argumentos para a nova frame
		for (i = (numIndicesNecessarios - 1); i >= 0; i--){
			// Se o argumento for um double ou um long, pulamos um �ndice
			if (p->frameAtual->frameAbaixo->topoPilhaOperandos->operandoTipo1 == TIPO2){
				i--;
			}
			p->frameAtual->arrayLocal[i] = popOperando(&(p->frameAtual->frameAbaixo->topoPilhaOperandos));
		}
	}

}

void executaMetodo(execucao *p){

	int isRetInstr = 0;
	u1 instrucao;

	while (!isRetInstr){

		instrucao = lerU1Codigo(p->frameAtual);

		isRetInstr = vetInstr[instrucao](p);

	}

}
