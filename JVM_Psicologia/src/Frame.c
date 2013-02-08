/*
 * Frame.c
 *
 *  Created on: 22/01/2013
 *      Author: Vitor
 */

#include <stdlib.h>
#include <stdio.h>
#include "Frame.h"

// TODO - Criar fun��es de manuseio das frames

/*
 * Checa se a pilha est� vazia. Retorna 1, se sim, 0 se n�o.
 */
int pilhaVazia (pilhaOperandos *topoPilha){

	return topoPilha == NULL;

}

/*
 * Dados um ponteiro de pilha e um operando, atualiza o topo dessa pilha com o operando passado
 */
void pushOperando(pilhaOperandos **endTopoPilha, tipoOperando operandoPassado){

	pilhaOperandos *p1;

	p1 = malloc(sizeof(pilhaOperandos));
	p1->operando = operandoPassado;
	p1->elementoAbaixo = *endTopoPilha;
	*endTopoPilha = p1;

	return;

}

/*
 * Sempre que uma pilha for iniciada, chame essa fun��o.
 */
void inicializaPilha(pilhaOperandos **endPilha){
	*endPilha = NULL;

	return;
}

/*
 * Retorna o operando do topo da pilha e libera a mem�ria antes utilizada por ele.
 */
tipoOperando popOperando(pilhaOperandos **endTopoPilha){

	pilhaOperandos *p1;
	tipoOperando operandoARetornar;

	if (!pilhaVazia(*endTopoPilha)){
		operandoARetornar = (*endTopoPilha)->operando;
		p1 = *endTopoPilha;
		*endTopoPilha = (*endTopoPilha)->elementoAbaixo;
		free (p1);
	}
	else{
		printf("ERRO em popOperando: pilha vazia\n");
		exit(1);
	}

	return operandoARetornar;

}

/*
 * Fun��o que inicializa uma frame
 */
void inicializaFrame (frame **endFrame){
	*endFrame = NULL;
}
