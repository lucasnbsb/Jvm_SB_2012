/*
 * FuncoesGerais.h
 *
 *  Created on: 15/02/2013
 *      Author: Vitor
 */

#ifndef FUNCOESGERAIS_H_
#define FUNCOESGERAIS_H_

#include "ClassFile.h"

methodInfo* buscaMetodoNome(ClassFile cf, char* nomeMetodo, char* descriptor);

u1* buscaUTF8ConstPool(ClassFile cf, u2 indice);

#endif /* FUNCOESGERAIS_H_ */
