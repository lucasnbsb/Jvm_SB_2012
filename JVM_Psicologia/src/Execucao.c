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
		if (cf.fields[i].accessFlags & ACC_STATIC != 0){
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

		if (cf.fields[i].accessFlags & ACC_STATIC != 0){
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

// Fun��o que verifica se uma determinada classe j� est� carregada
// A busca � feita pela constant pool de cada classe,
// vendo cada membro this_class.
ClassFile* buscaClassFileNome(listaClasses* inicioLista, char* nomeClasse){

	listaClasses* p1;
	u2 indiceClassInfo;

	p1 = inicioLista;

	indiceClassInfo = p1->cf.this_class;

	while (p1 != NULL){
		if (strcmp(buscaUTF8ConstPool(p1->cf.constant_pool, p1->cf.constant_pool[indiceClassInfo].info.classInfo.nameIndex), nomeClasse) == 0){
			return &(p1->cf);
		}
	}

	return NULL;

}

// Fun��o que inicia e executa um m�todo
void preparaExecucaoMetodo (char* nomeClasse, char* nomeMetodo, char* descriptor, execucao *p, int numArgs){

	ClassFile* cf;
	int i;

	cf = buscaClassFileNome(p->pInicioLista, nomeClasse);
	if (cf == NULL){
		cf = malloc (sizeof(ClassFile));
		*cf = carregaClassFile(nomeClasse);
		insereClassFileLista(&(p->pInicioLista), *cf);
	}

	// Aloca a frame nova e a coloca na pilha de frames
	pushFrame(&(p->frameAtual));

	// Preenche a frame alocada
	inicializaFrame(*cf, p->frameAtual, nomeMetodo, descriptor);

	// Passa os argumentos para a nova frame
	if (p->frameAtual->frameAbaixo != NULL){
		for (i = (numArgs - 1); i > 0; i--){
			p->frameAtual->arrayLocal[i] = popOperando(&(p->frameAtual->topoPilhaOperandos));
		}
	}

}

void executaMetodo(execucao *p){

	int isRetInstr = 0;

	while (!isRetInstr){

		isRetInstr = vetInstr[*(p->frameAtual->pc)](p);
		p->frameAtual->pc++;

	}

}
