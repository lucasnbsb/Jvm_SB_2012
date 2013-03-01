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
		if(strcmp((char*) buscaUTF8ConstPool(cf.constant_pool, cf.methods[i].nameIndex), nomeMetodo) == 0
				&& strcmp((char*) buscaUTF8ConstPool(cf.constant_pool, cf.methods[i].descriptorIndex), descriptor) == 0){
			return &(cf.methods[i]);
		}
	}

	return NULL;

}

// Função que verifica se uma determinada classe já está carregada
// A busca é feita pela constant pool de cada classe,
// vendo cada membro this_class.
ClassFile* buscaClassFileNome(listaClasses* inicioLista, char* nomeClasse){

	listaClasses* p1;
	u2 indiceClassInfo;

	p1 = inicioLista;

	if (p1 != NULL){
		indiceClassInfo = p1->cf.this_class;
	}
	while (p1 != NULL){
		if (strcmp(buscaUTF8ConstPool(p1->cf.constant_pool, p1->cf.constant_pool[indiceClassInfo].info.classInfo.nameIndex), nomeClasse) == 0){
			return &(p1->cf);
		}
		p1 = p1->proxClasse;
	}

	return NULL;

}
//retorna um byte referente ao pc da frame dada
//le o byte do pc da frame e incrementa o pc
u1 lerU1Codigo(frame *fr){
	u1 retorno;
	retorno = *(fr->pc);
	fr->pc++;
	return retorno;
}

//retorna os dois bytes referentes ao pc da frame dada
//le os proximos dois bytes do pc da frame e incrementa em 2 o pc
u2 lerU2Codigo(frame *fr){
	u2 retorno;

	retorno = *(fr->pc);
	fr->pc++;

	retorno = retorno << 8 | *(fr->pc);
	fr->pc++;

	return retorno;

}

//dado o descritor do metodo conta-se quantos argumentos sao passados para ele
//É feita uma varredura no descritor e ao chegar na ')' encerra a varredura
//Duarante a varredura um contador conta os argumentos que forem aparecendo
int contaArgumentosMetodo(u1* descriptor){

	u1* varredor;
	int i = 0;
	int numArgs = 0;

	varredor = descriptor;

	// Varre o descritor até achar o ')', que indica final dos parametros.
	while (varredor[i] != ')'){
		if (varredor[i] != '(' && varredor[i] != '['){
			numArgs++;
			if (varredor[i] == 'L'){
				while (varredor[i] != ';'){
					i++;
				}
			}
		}

		i++;

	}

	return numArgs;

}

// Função que retorna o field estático dados o nome da classe e o nome do field
field* buscaStaticFieldNome(listaClasses* inicioLista, char* nomeClasse, char* nomeField){

	u2 indiceClassInfo;
	listaClasses *p1;
	int i;

	p1 = inicioLista;

	while (p1 != NULL){

		indiceClassInfo = p1->cf.this_class;

		if (strcmp(nomeClasse, buscaUTF8ConstPool(p1->cf.constant_pool, p1->cf.constant_pool[indiceClassInfo].info.classInfo.nameIndex)) == 0){
			for (i = 0; i < p1->numStaticFields; i++){
				if(strcmp(nomeField, p1->staticFields[i].nome) == 0){
					return (&p1->staticFields[i]);
				}
			}

			// Não há como ter duas classes com o mesmo nome, então
			// se o nome bateu, mas em nenhum dos fields foi encontrado
			// o esperado, então welp, retorne NULL.
			return NULL;
		}

		p1 = p1->proxClasse;
	}

	return NULL;
}

// Função que retorna um atributo UTF8 dado um índice válido
u1* buscaUTF8ConstPool(cpInfo *cp, u2 indice){

	return cp[indice].info.UTF8Info.bytes;

}
