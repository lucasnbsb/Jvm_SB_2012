/*
 * FuncoesGerais.h
 *
 *  Created on: 15/02/2013
 *      Author: Vitor
 */

#ifndef FUNCOESGERAIS_H_
#define FUNCOESGERAIS_H_

#include "ClassFile.h"
#include "Frame.h"

methodInfo* buscaMetodoNome(ClassFile cf, char* nomeMetodo, char* descriptor);

u1* buscaUTF8ConstPool(cpInfo* cp, u2 indice);

u1 lerU1Codigo(frame*);

u2 lerU2Codigo(frame*);

int contaArgumentosMetodo(u1* descriptor);

#endif /* FUNCOESGERAIS_H_ */
