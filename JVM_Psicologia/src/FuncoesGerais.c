/*
 * FuncoesGerais.c
 *
 *  Created on: 15/02/2013
 *      Author: Vitor
 */

#include "FuncoesGerais.h"
#include "ClassFile.h"
#include <string.h>

// Função que retorna a referência descrição de um método (methodInfo) dado um nome e um descritor
// É retornada a referência pois podemos validar se não encontrou um método
// simplesmente comparando com NULL
methodInfo* buscaMetodoNome(ClassFile cf, char* nomeMetodo, char* descriptor){

	int i;

	for (i = 0; i < cf.methods_count; i++){
		if(strcmp((char*) buscaUTF8ConstPool(cf, cf.methods[i].nameIndex), nomeMetodo) == 0
				&& strcmp((char*) buscaUTF8ConstPool(cf, cf.methods[i].descriptorIndex), descriptor) == 0){
			return &(cf.methods[i]);
		}
	}

	return NULL;

}

u1 lerU1Codigo(frame *fr){
	u1 retorno;
	retorno = *(fr->pc);
	fr->pc++;
	return retorno;
}

// Função que retorna um atributo UTF8 dado um índice válido
u1* buscaUTF8ConstPool(ClassFile cf, u2 indice){

	return cf.constant_pool[indice].info.UTF8Info.bytes;

}
