/*
 * Frame.h
 *
 *  Created on: 22/01/2013
 *      Author: Vitor
 */

#ifndef FRAME_H_
#define FRAME_H_

#include "ClassFile.h"

/*
 * A pilha só mantem operandos de 32 ou 64 bits, os outros sao promovidos a estes tamanhos.
 *
 */
typedef union _tipoOperando{

	int tipoInt;
	long long tipoLong;
	float tipoFloat;
	double tipoDouble;

} tipoOperando;

/*
 * A pilha mantém o topo dela como referência (pilha Homero).
 *
 */
typedef struct _pilhaOperandos{

	tipoOperando operando;
	struct _pilhaOperandos *elementoAbaixo;

} pilhaOperandos;

/*
 * Estrutura de uma frame. Criada quando um método é invocado
 */
typedef struct _frame{
	cpInfo *constantPool;
	ClassFile cf;
	tipoOperando *arrayLocal;	// ATENÇÃO: Doubles e longs ocupam 2 índices!!
	pilhaOperandos *topoPilhaOperandos;
	u1* codigoAExecutar;
	struct _frame *frameAbaixo;
} frame;

typedef struct EXECUCAO{
	frame* frameAtual;
}pilhaFrames;

int pilhaVazia (pilhaOperandos *topoPilha);

void pushOperando(pilhaOperandos **endTopoPilha, tipoOperando operandoPassado);

void inicializaPilha(pilhaOperandos **endPilha);

tipoOperando popOperando(pilhaOperandos **endTopoPilha);

void pilhaVaziaFrame (frame *frameAtual);

void inicializaPilhaFrames (frame **endFrameAtual);

void pushFrame (frame **endFrameAtual);

void popFrame (frame **endFrameAtual);

void inicializaFrame (ClassFile cf, frame *frame , char* nomeMetodo, char* descriptor);

#endif /* PILHAOPERANDOS_H_ */
