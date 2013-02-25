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
	long long tipoLong;
	float tipoFloat;
	double tipoDouble;
	void* tipoReferencia;

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
	tipoOperando *arrayLocal;	// ATEN��O: Doubles e longs ocupam 2 �ndices!!
	pilhaOperandos *topoPilhaOperandos;
	u1* codigoAExecutar;
	struct _frame *frameAbaixo;
	u1 *pc;
} frame;

typedef union _tipoField{
	int tipoInt;
	short tipoShort;
	float tipoFloat;
	long long tipoLong;
	double tipoDouble;
	char tipoChar;
	void* tipoReferencia;
} tipoField;

typedef struct _field{
	char* nome;
	char* descritor;
	tipoField valor;
} field;

typedef struct _Object{
	int fieldsCount;
	field* fields;
	methodInfo* methodAreaPointer;
} object;

typedef struct _listaObject{
	object obj;
	struct _listaObject *proxObj;
} listaObject;

typedef struct _listaClasses{
	ClassFile cf;
	int numStaticFields;
	field* staticFields;
	listaObject* listaObjetos;
	struct _listaClasses *proxClasse;
} listaClasses;

typedef struct EXECUCAO{
	frame* frameAtual;
	listaClasses* pInicioLista;
}execucao;

int pilhaVazia (pilhaOperandos *topoPilha);

void pushOperando(pilhaOperandos **endTopoPilha, tipoOperando operandoPassado);

void inicializaPilha(pilhaOperandos **endPilha);

tipoOperando popOperando(pilhaOperandos **endTopoPilha);

void pilhaVaziaFrame (frame *frameAtual);

void inicializaPilhaFrames (frame **endFrameAtual);

void pushFrame (frame **endFrameAtual);

void popFrame (frame **endFrameAtual);

void inicializaFrame (listaClasses *inicioLista, ClassFile cf, frame *frame , char* nomeMetodo, char* descriptor);

#endif /* PILHAOPERANDOS_H_ */
