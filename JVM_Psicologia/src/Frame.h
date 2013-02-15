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
 * A pilha s� mantem operandos de 32 ou 64 bits, os outros sao promovidos a estes tamanhos.
 *
 */
typedef union _tipoOperando{

	int tipoInt;
	long tipoLong;
	float tipoFloat;
	double tipoDouble;

} tipoOperando;

/*
 * A pilha mant�m o topo dela como refer�ncia (pilha Homero).
 *
 */
typedef struct _pilhaOperandos{

	tipoOperando operando;
	struct _pilhaOperandos *elementoAbaixo;

} pilhaOperandos;

/*
 * Estrutura de uma frame. Criada quando um m�todo � invocado
 */
typedef struct _frame{
	cpInfo *constantPool;
	ClassFile cf;
	tipoOperando *arrayLocal;	// ATEN��O: Doubles e longs ocupam 2 �ndices!!
	pilhaOperandos *pInicio;
	struct _frame *frameAbaixo;
} frame;

typedef struct EXECUCAO{
	frame* frameAtual;
}pilhaFrames;

/*
 * Checa se a pilha est� vazia. Retorna 1, se sim, 0 se n�o.
 */
int pilhaVazia (pilhaOperandos *topoPilha);

/*
 * Dados um ponteiro de pilha e um operando, atualiza o topo dessa pilha com o operando passado
 */
void pushOperando(pilhaOperandos **endTopoPilha, tipoOperando operandoPassado);

/*
 * Sempre que uma pilha for iniciada, chame essa fun��o.
 */
void inicializaPilha(pilhaOperandos **endPilha);

/*
 * Retorna o operando do topo da pilha e libera a mem�ria antes utilizada por ele.
 */
tipoOperando popOperando(pilhaOperandos **endTopoPilha);

void inicializaFrame (ClassFile cf, frame *frame , char* nomeMetodo, char* descriptor);

void inicializaPilhaFrames ();

#endif /* PILHAOPERANDOS_H_ */
