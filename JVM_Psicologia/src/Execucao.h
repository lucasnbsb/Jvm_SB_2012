/*
 * Execucao.h
 *
 *  Created on: 21/02/2013
 *      Author: Vitor
 */

#ifndef EXECUCAO_H_
#define EXECUCAO_H_

#include "Frame.h"
#include "ClassFile.h"

typedef struct _listaClasses{
	ClassFile cf;
	struct _listaClasses *proxClasse;
} listaClasses;

typedef struct EXECUCAO{
	frame* frameAtual;
	listaClasses* pInicioLista;
}execucao;

void insereClassFileLista(listaClasses** endInicioLista, ClassFile cf);

ClassFile* buscaClassFileNome(listaClasses* inicioLista, char* nomeClasse);

void executaMetodo (char* nomeClasse, char* nomeMetodo, char* descriptor, execucao *p);

#endif /* EXECUCAO_H_ */
