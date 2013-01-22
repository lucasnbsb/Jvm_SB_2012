/*
 * PilhaOperandos.h
 *
 *  Created on: 22/01/2013
 *      Author: Vitor
 */

#ifndef PILHAOPERANDOS_H_
#define PILHAOPERANDOS_H_

/*
 * A pilha só mantem operandos de 32 ou 64 bits, os outros sao promovidos a estes tamanhos.
 *
 */
typedef union _tipoOperando{

	int tipoInt;
	long tipoLong;
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
 * Checa se a pilha está vazia. Retorna 1, se sim, 0 se não.
 */
int pilhaVazia (pilhaOperandos *topoPilha);

/*
 * Dados um ponteiro de pilha e um operando, atualiza o topo dessa pilha com o operando passado
 */
void pushOperando(pilhaOperandos **endTopoPilha, tipoOperando operandoPassado);

/*
 * Sempre que uma pilha for iniciada, chame essa função.
 */
void inicializaPilha(pilhaOperandos **endPilha);

/*
 * Retorna o operando do topo da pilha e libera a memória antes utilizada por ele.
 */
tipoOperando popOperando(pilhaOperandos **endTopoPilha);

#endif /* PILHAOPERANDOS_H_ */
