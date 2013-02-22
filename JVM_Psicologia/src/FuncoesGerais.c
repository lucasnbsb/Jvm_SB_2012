/*
 * FuncoesGerais.c
 *
 *  Created on: 15/02/2013
 *      Author: Vitor
 */

#include "FuncoesGerais.h"
#include "ClassFile.h"
#include <string.h>

// Fun��o que retorna a refer�ncia descri��o de um m�todo (methodInfo) dado um nome e um descritor
// � retornada a refer�ncia pois podemos validar se n�o encontrou um m�todo
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

// Fun��o que retorna um atributo UTF8 dado um �ndice v�lido
u1* buscaUTF8ConstPool(ClassFile cf, u2 indice){

	return cf.constant_pool[indice].info.UTF8Info.bytes;

}
