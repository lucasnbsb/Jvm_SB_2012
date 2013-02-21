/*
 * Frame.c
 *
 *  Created on: 22/01/2013
 *      Author: Vitor
 */

#include <stdlib.h>
#include <stdio.h>
#include "Frame.h"
#include "ClassFile.h"
#include "FuncoesGerais.h"
#include <string.h>


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
 * Fun��o que checa se a pilha de frames est� vazia
 */
int pilhaFramesVazia (frame *frameAtual){
	return frameAtual == NULL;
}

/*
 * Fun��o que inicializa a pilha de frames, semelhante � pilha de operandos
 */
void inicializaPilhaFrames (frame **endFrameAtual){
	*endFrameAtual = NULL;
}

/*
 * Fun��o que coloca uma frame nova na pilha.
 *
 * !! ATEN��O !! - Inicializar a frame ap�s dar o push.
 */
void pushFrame (frame **endFrameAtual){

	frame *p1;

	p1 = malloc (sizeof(frame));

	p1->frameAbaixo = *endFrameAtual;
	*endFrameAtual = p1;

}

/*
 * Fun��o que retira uma frame da pilha de frames
 */
void popFrame (frame **endFrameAtual){

	frame *p1;

	if (!pilhaFramesVazia(*endFrameAtual)){
		p1 = *endFrameAtual;
		*endFrameAtual = (*endFrameAtual)->frameAbaixo;
		free (p1);
	}
	else {
		printf("ERRO em popFrame : pilha vazia\n");
		exit (1);
	}

}

/*
 * Fun��o que inicializa uma frame
 */
void inicializaFrame (ClassFile cf, frame *frame , char* nomeMetodo , char* descriptor){
	methodInfo* metodo;
	attributeInfo codigoMetodo;
	int i;

	//achar o m�todo pelo nome
	metodo = buscaMetodoNome(cf , nomeMetodo , descriptor);
	if(metodo == NULL){
		printf("m�todo n�o encontrado: %s\nDescritor: %s", nomeMetodo , descriptor);
		exit(1);
	}else{
		//achar o atributo Code , percorre a lista de atributos buscando o atributo Code
		for (i = 0; i < metodo->attributesCount; i++) {
			if(strcmp( buscaUTF8ConstPool(cf , metodo->attributes[i].attributeNameIndex) , "Code") == 0){
				codigoMetodo = metodo->attributes[i];
				break;
			}
		}
	}
	frame->constantPool = cf.constant_pool;
	//inicializando a pilha de operandos
	inicializaPilha(&(frame->topoPilhaOperandos));
	//Copiando a refer�ncia do c�digo do m�todo a ser executado.
	frame->codigoAExecutar = codigoMetodo.tipoInfo.code.code;
	//inicializando o array de vari�veis locais
	frame->arrayLocal = malloc(codigoMetodo.tipoInfo.code.maxLocals * sizeof(tipoOperando));
}
