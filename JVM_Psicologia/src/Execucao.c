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

// Função que inicializa a lista com o endereço NULL
void inicializaClassFileLista(listaClasses** endInicioLista){
	*endInicioLista = NULL;
}

// Função que adiciona um novo class file carregado à lista encadeada simples de classes
void insereClassFileLista(listaClasses** endInicioLista, ClassFile cf){

	listaClasses* p1;
	listaClasses* p2;

	p1 = malloc (sizeof(listaClasses));
	p1->cf = cf;

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

// Função que verifica se uma determinada classe já está carregada
// A busca é feita pela constant pool de cada classe,
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

// Função que inicia e executa um método
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
