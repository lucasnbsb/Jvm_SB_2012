/*
 * FuncoesGerais.c
 *
 *  Created on: 15/02/2013
 *      Author: Vitor
 */

#include "FuncoesGerais.h"
#include "ClassFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fun��o que retorna a refer�ncia descri��o de um m�todo (methodInfo) dado um nome e um descritor
// � retornada a refer�ncia pois podemos validar se n�o encontrou um m�todo
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

// Fun��o que dada uma path para uma classe, filtra-a para ter somente seu nome
void limpaPathClasseParaNome(char* nomeClasseSemPath, char* nomeClasse){

	int i;
	int j = 0;

	i = strlen(nomeClasse) - 1;

	// Pulamos o ".class" com o bloco abaixo, se estiver l�
	if (strstr(nomeClasse, ".class") != NULL){
		while(nomeClasse[i] != '.'){
			i--;
		}
		i--;
	}

	// Agora, pulamos at� encontrarmos o primeiro divisor, se tiver algum
	// ou at� o come�o da String
	while(nomeClasse[i] != '\\' && nomeClasse[i] != '/' && &(nomeClasse[i]) != nomeClasse){
		i--;
	}
	if(nomeClasse[i] == '\\' || nomeClasse[i] == '/'){
		i++;
	}

	// Agora passamos o nome da classe para o nomeClasseSemPath
	while(nomeClasse[i] != '.' && nomeClasse[i] != '\0'){
		nomeClasseSemPath[j] = nomeClasse[i];
		i++;
		j++;
	}
	nomeClasseSemPath[j] = '\0';

}

// Fun��o que verifica se uma determinada classe j� est� carregada
// A busca � feita pela constant pool de cada classe,
// vendo cada membro this_class.
ClassFile* buscaClassFileNome(listaClasses* inicioLista, char* nomeClasse){

	listaClasses* p1;
	u2 indiceClassInfo;
	char nomeClasseSemPath[100];

	p1 = inicioLista;

	limpaPathClasseParaNome(nomeClasseSemPath, nomeClasse);

	while (p1 != NULL){

		indiceClassInfo = p1->cf.this_class;

		if (strcmp(buscaUTF8ConstPool(p1->cf.constant_pool, p1->cf.constant_pool[indiceClassInfo].info.classInfo.nameIndex), nomeClasseSemPath) == 0){
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

u4 lerU4Codigo(frame *fr){
	u4 retorno;
	retorno = *(fr->pc);
	fr->pc++;
	retorno = retorno << 8 | *(fr->pc);
	fr->pc++;
	retorno = retorno << 8 | *(fr->pc);
	fr->pc++;
	retorno = retorno << 8 | *(fr->pc);
	fr->pc++;
	return retorno;
}
//dado o descritor do metodo conta-se quantos argumentos sao passados para ele
//� feita uma varredura no descritor e ao chegar na ')' encerra a varredura
//Duarante a varredura um contador conta os argumentos que forem aparecendo
int contaArgumentosMetodo(u1* descriptor){

	u1* varredor;
	int i = 0;
	int numArgs = 0;

	varredor = descriptor;

	// Varre o descritor at� achar o ')', que indica final dos parametros.
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

// Fun��o que retorna o field est�tico dados o nome da classe e o nome do field
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

			// N�o h� como ter duas classes com o mesmo nome, ent�o
			// se o nome bateu, mas em nenhum dos fields foi encontrado
			// o esperado, ent�o welp, retorne NULL.
			return NULL;
		}

		p1 = p1->proxClasse;
	}

	return NULL;
}

void insereValorStaticField(listaClasses* inicioLista, char* nomeClasse, char* nomeField, tipoOperando op){

	u2 indiceClassInfo;
		listaClasses *p1;
		int i;

		p1 = inicioLista;

		while (p1 != NULL){

			indiceClassInfo = p1->cf.this_class;

			if (strcmp(nomeClasse, buscaUTF8ConstPool(p1->cf.constant_pool, p1->cf.constant_pool[indiceClassInfo].info.classInfo.nameIndex)) == 0){
				for (i = 0; i < p1->numStaticFields; i++){
					if(strcmp(nomeField, p1->staticFields[i].nome) == 0){
						// Como o long long cobre o tamanho da union, uso ele para passar o valor
						p1->staticFields[i].valor.tipoLong = op.tipoLong;
						return;
					}
				}

				// N�o h� como ter duas classes com o mesmo nome, ent�o
				// se o nome bateu, mas em nenhum dos fields foi encontrado
				// o esperado, ent�o welp, retorne.
				return;
			}

			p1 = p1->proxClasse;
		}

}

// Fun��o que retorna um atributo UTF8 dado um �ndice v�lido
u1* buscaUTF8ConstPool(cpInfo *cp, u2 indice){

	return cp[indice].info.UTF8Info.bytes;

}

Vetor* alocaMultiArray(int dimenssoes , int* tamanhos){
	Vetor *aux , *aux2;
	int i;
	int *auxTamanhos;
	if(dimenssoes == 1){ // fun��o recursiva , crit�rio de parada
		aux = malloc(sizeof(Vetor)); // aloca para a parada
		aux->size = tamanhos[0];
		aux->type = T_INT;
		aux->array = calloc(tamanhos[0] , sizeof(tipoOperando));
	}else{
		aux = malloc(sizeof(Vetor));//garante a aloca��o do vetor
		aux->size = tamanhos[0];
		aux->type = T_INT;
		aux->array = calloc(tamanhos[0] , sizeof(tipoOperando));
		//---------------------------------------------------
		auxTamanhos = calloc(dimenssoes -1 , sizeof(int)); // montando o vetor de tamanho para o proximo nivel de recurs�o
		for (i = 1; i < dimenssoes; ++i) { // o proximo n�vel recebe uma posi��o a menos
			auxTamanhos[i-1] = tamanhos[i];
		}
		//---------------------------------------------------
		for (i = 0; i < tamanhos[0]; ++i) {
			aux2 = alocaMultiArray(dimenssoes-1 , auxTamanhos);
			aux->array[i].tipoReferencia = aux2;
		}
	}
	return aux;
}
