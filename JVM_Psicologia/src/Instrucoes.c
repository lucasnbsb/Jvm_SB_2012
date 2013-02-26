/*
 * Instrucoes.c
 *
 *  Created on: 08/02/2013
 *      Author: Vitor
 *
 *  Arquivo das instruções da JVM. Inclui as de alocação.
 */
#include "Instrucoes.h"
#include "math.h"

int nop(execucao *p) {
	return 0;
}

int aconst_null(execucao *p){ // empty -> value (NULL) op: 0x01

	tipoOperando op;

	op.tipoReferencia = NULL;

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);

	return 0;
}

//const --------------------------------------------------------------------------------------------------------------------------------------------------------------------
int iconst_m1(execucao *p) {

	tipoOperando op;

	op.tipoInt = -1;

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);
	return 0;
}

int iconst_0(execucao *p) {

	tipoOperando op;

	op.tipoInt = 0;

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);
	return 0;
}

int iconst_1(execucao *p) {

	tipoOperando op;

	op.tipoInt = 1;

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);
	return 0;
}

int iconst_2(execucao *p) {

	tipoOperando op;

	op.tipoInt = 2;

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);
	return 0;
}

int iconst_3(execucao *p) {

	tipoOperando op;

	op.tipoInt = 3;

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);
	return 0;
}

int iconst_4(execucao *p) {

	tipoOperando op;

	op.tipoInt = 4;

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);
	return 0;
}

int iconst_5(execucao *p) {

	tipoOperando op;

	op.tipoInt = 5;

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);
	return 0;
}

int lconst_0(execucao *p) { // Insere na pilha a constante long 0 op: 0x9
	tipoOperando op;
	op.tipoLong = 0;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO2);
	return 0;
}

int lconst_1(execucao *p) { // Insere na pilha a constante long 1 op: 0xA

	tipoOperando op;
	op.tipoLong = 1;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO2);
	return 0;

}

int fconst_0(execucao *p) { // Insere na pilha a constante float 0.0 op: 0xB
	tipoOperando op;
	op.tipoFloat = 0.0;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);
	return 0;
}

int fconst_1(execucao *p) { // Insere na pilha a constante float 1.0 op: 0xC
	tipoOperando op;
	op.tipoFloat = 1.0;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);
	return 0;
}

int fconst_2(execucao *p) { // Insere na pilha a constante long 2.0 op: 0xD
	tipoOperando op;
	op.tipoFloat = 2.0;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);
	return 0;
}

int dconst_0(execucao *p) { // Insere na pilha a constante float 0.0 op: 0xE
	tipoOperando op;
	op.tipoDouble = 0.0;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO2);
	return 0;
}

int dconst_1(execucao *p) { // Insere na pilha a constante float 0.0 op: 0xF
	tipoOperando op;
	op.tipoDouble = 1.0;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO2);
	return 0;
}

//Push --------------------------------------------------------------------------------------------------------------------------------------------------------------------
int bipush(execucao *p){ //insere na pilha o valor lido do índice op: 0x10

	tipoOperando op;
	u1 byteLido;

	byteLido = lerU1Codigo(p->frameAtual);
	op.tipoInt = byteLido;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);

	return 0;
}

int sipush(execucao *p){ //insere na pilha o valor (u2) lido do índice op: 0x11

	tipoOperando op;
	u2 shortLido;

	shortLido = lerU2Codigo(p->frameAtual);
	op.tipoInt = shortLido;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);

	return 0;
}

//Load --------------------------------------------------------------------------------------------------------------------------------------------------------------------
int iload(execucao *p){ //insere na pilha o valor da posicao apontada por um indice do vetor de variáveis locais op: 0x15 , 0x16 , 0x17 ,0x18 , 0x19
	u1 index;
	tipoOperando op;
	index = lerU1Codigo(p->frameAtual);
	op = p->frameAtual->arrayLocal[index];
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);
	return 0;
}

int iload_0(execucao *p){ //insere na pilha o valor da posicao 0 do vetor de variáveis locais op: 0x1A , 0X1E ,0X22 , 0X26 ,0X2A
	u1 index;
	tipoOperando op;
	index = 0;
	op = p->frameAtual->arrayLocal[index];
	pushOperando(&(p->frameAtual->topoPilhaOperandos) , op, TIPO1);
	return 0;
}

int iload_1(execucao *p){ //insere na pilha um int da constant pool op: 0X1B , 0X1F , 0X23 , 0X27 , 0X2B
	u1 index;
	tipoOperando op;
	index = 1;
	op = p->frameAtual->arrayLocal[index];
	pushOperando(&(p->frameAtual->topoPilhaOperandos) , op, TIPO1);
	return 0;
}

int iload_2(execucao *p){ //insere na pilha um int da constant pool op: 0X1C , 0X20 , 0X24 , 0X28 , OX2C
	u1 index;
	tipoOperando op;
	index = 2;
	op = p->frameAtual->arrayLocal[index];
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);
	return 0;
}

int iload_3(execucao *p){ //insere na pilha um int da constant pool op: 0X1D , 0X21 , 0X25 , 0X29 , 0X2D
	u1 index;
	tipoOperando op;
	index = 3;
	op = p->frameAtual->arrayLocal[index];
	pushOperando(&(p->frameAtual->topoPilhaOperandos) , op, TIPO1);
	return 0;
}

int fload(execucao *p){
	u1 index;
	tipoOperando op;
	index = lerU1Codigo(p->frameAtual);
	op = p->frameAtual->arrayLocal[index];
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);
	return 0;
}

int fload_0(execucao *p){
	u1 index;
	tipoOperando op;
	index = 0;
	op = p->frameAtual->arrayLocal[index];
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);
	return 0;
}

int fload_1(execucao *p){
	u1 index;
	tipoOperando op;
	index = 1;
	op = p->frameAtual->arrayLocal[index];
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);
	return 0;
}

int fload_2(execucao *p){
	u1 index;
	tipoOperando op;
	index = 2;
	op = p->frameAtual->arrayLocal[index];
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);
	return 0;
}

int fload_3(execucao *p){
	u1 index;
	tipoOperando op;
	index = 3;
	op = p->frameAtual->arrayLocal[index];
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);
	return 0;
}

int lload(execucao *p){
	u1 index;
	tipoOperando op;
	index = lerU1Codigo(p->frameAtual);
	op = p->frameAtual->arrayLocal[index];
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO2);
	return 0;
}

int lload_0(execucao *p){
	u1 index;
	tipoOperando op;
	index = 0;
	op = p->frameAtual->arrayLocal[index];
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO2);
	return 0;
}

int lload_1(execucao *p){
	u1 index;
	tipoOperando op;
	index = 1;
	op = p->frameAtual->arrayLocal[index];
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO2);
	return 0;
}

int lload_2(execucao *p){
	u1 index;
	tipoOperando op;
	index = 2;
	op = p->frameAtual->arrayLocal[index];
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO2);
	return 0;
}

int lload_3(execucao *p){
	u1 index;
	tipoOperando op;
	index = 3;
	op = p->frameAtual->arrayLocal[index];
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO2);
	return 0;
}

int dload(execucao *p){
	u1 index;
	tipoOperando op;
	index = lerU1Codigo(p->frameAtual);
	op = p->frameAtual->arrayLocal[index];
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO2);
	return 0;
}

int dload_0(execucao *p){
	u1 index;
	tipoOperando op;
	index = 0;
	op = p->frameAtual->arrayLocal[index];
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO2);
	return 0;
}

int dload_1(execucao *p){
	u1 index;
	tipoOperando op;
	index = 1;
	op = p->frameAtual->arrayLocal[index];
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO2);
	return 0;
}

int dload_2(execucao *p){
	u1 index;
	tipoOperando op;
	index = 2;
	op = p->frameAtual->arrayLocal[index];
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO2);
	return 0;
}

int dload_3(execucao *p){
	u1 index;
	tipoOperando op;
	index = 3;
	op = p->frameAtual->arrayLocal[index];
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO2);
	return 0;
}

int aload(execucao *p){
	u1 index;
	tipoOperando op;
	index = lerU1Codigo(p->frameAtual);
	op = p->frameAtual->arrayLocal[index];
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);
	return 0;
}

int aload_0(execucao *p){
	u1 index;
	tipoOperando op;
	index = 0;
	op = p->frameAtual->arrayLocal[index];
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);
	return 0;
}

int aload_1(execucao *p){
	u1 index;
	tipoOperando op;
	index = 1;
	op = p->frameAtual->arrayLocal[index];
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);
	return 0;
}

int aload_2(execucao *p){
	u1 index;
	tipoOperando op;
	index = 2;
	op = p->frameAtual->arrayLocal[index];
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);
	return 0;
}

int aload_3(execucao *p){
	u1 index;
	tipoOperando op;
	index = 3;
	op = p->frameAtual->arrayLocal[index];
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);
	return 0;
}

// Lê um índice de 2 bytes e carrega o valor que estiver na constant pool neste índice
// No caso da String, é carregado sua referência
int ldc(execucao *p){

	u2 indice;
	tipoOperando op;

	indice = lerU1Codigo(p->frameAtual);

	switch(p->frameAtual->constantPool[indice].tag){
		case CONSTANT_Integer:
			op.tipoInt = p->frameAtual->constantPool[indice].info.integerInfo.bytes;
			break;
		case CONSTANT_Float:
			op.tipoFloat = p->frameAtual->constantPool[indice].info.floatInfo.f.num;
			break;
		case CONSTANT_String:
			op.tipoReferencia = (char*) buscaUTF8ConstPool(p->frameAtual->constantPool, p->frameAtual->constantPool[indice].info.stringInfo.stringIndex);
			break;
		default:
			printf("\nInstrução ldc sendo utilizado com indice invalido\n");
			exit(1);
	}

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);

	return 0;
}

//Store --------------------------------------------------------------------------------------------------------------------------------------------------------------------
int store(execucao *p){ //recebe um indice e salva o topo da pilha de operandos no indice do vetor de variaveis locais 0x36 , 0X37 , 0X38 , 0X39 , 0X3A
	u1 index;
	tipoOperando op;
	index = lerU1Codigo(p->frameAtual);
	op = popOperando(&(p->frameAtual->topoPilhaOperandos));
	p->frameAtual->arrayLocal[index] = op;
	return 0;
}
//todo - incluir o store na lista de instruçoes ,  fazer store 0,1,2,3
//dup  --------------------------------------------------------------------------------------------------------------------------------------------------------------------
int dup(execucao *p) { // duplica o elemento no topo da pilha op: 0x59
	tipoOperando op;
	int operandoTipo;

	operandoTipo = p->frameAtual->topoPilhaOperandos->operandoTipo1;
	op = popOperando(&(p->frameAtual->topoPilhaOperandos));
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, operandoTipo);
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, operandoTipo);
	return 0;
}

int dup_x1(execucao *p) { // duplica o elemento no topo da pilha , dois elementos a baixo  op: 0x5A
	tipoOperando op, op1;
	int operandoTipoOp, operandoTipoOp1;

	operandoTipoOp = p->frameAtual->topoPilhaOperandos->operandoTipo1;
	op = popOperando(&(p->frameAtual->topoPilhaOperandos));

	operandoTipoOp1 = p->frameAtual->topoPilhaOperandos->operandoTipo1;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, operandoTipoOp);
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, operandoTipoOp1);
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, operandoTipoOp);
	return 0;
}

int dup_x2(execucao *p) { // duplica o elemento no topo da pilha tres a baixo op: 0x5B
	tipoOperando op, op1, op2;
	int operandoTipoOp, operandoTipoOp1, operandoTipoOp2;

	operandoTipoOp = p->frameAtual->topoPilhaOperandos->operandoTipo1;
	op = popOperando(&(p->frameAtual->topoPilhaOperandos));

	operandoTipoOp1 = p->frameAtual->topoPilhaOperandos->operandoTipo1;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));

	operandoTipoOp2 = p->frameAtual->topoPilhaOperandos->operandoTipo1;
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, operandoTipoOp);
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op2, operandoTipoOp2);
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, operandoTipoOp1);
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, operandoTipoOp);
	return 0;
}

int dup2(execucao *p) { // duplica o elemento no topo da pilha , dois elementos a baixo  op: 0x5C
	tipoOperando op, op1;
	int operandoTipoOp, operandoTipoOp1;

	operandoTipoOp = p->frameAtual->topoPilhaOperandos->operandoTipo1;
	op = popOperando(&(p->frameAtual->topoPilhaOperandos));

	if(operandoTipoOp == TIPO1){
		operandoTipoOp1 = p->frameAtual->topoPilhaOperandos->operandoTipo1;
		op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));

		pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, operandoTipoOp1);
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op,  operandoTipoOp);
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, operandoTipoOp1);
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op, operandoTipoOp);
	}
	else{
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op, operandoTipoOp);
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op, operandoTipoOp);
	}

	return 0;
}

int dup2_x1(execucao *p) { //duplica os dois primeiros elementos da pilha a baixo do terceiro 0x5D
	tipoOperando op, op1, op2;
	int operandoTipoOp, operandoTipoOp1, operandoTipoOp2;

	operandoTipoOp = p->frameAtual->topoPilhaOperandos->operandoTipo1;
	op = popOperando(&(p->frameAtual->topoPilhaOperandos));

	if (operandoTipoOp == TIPO1){
		operandoTipoOp1 = p->frameAtual->topoPilhaOperandos->operandoTipo1;
		op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	}

	operandoTipoOp2 = p->frameAtual->topoPilhaOperandos->operandoTipo1;
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));

	if (operandoTipoOp == TIPO1){
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, operandoTipoOp1);
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op, operandoTipoOp);
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op2, operandoTipoOp2);
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, operandoTipoOp1);
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op, operandoTipoOp);
	}
	else{
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op, operandoTipoOp);
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op2, operandoTipoOp2);
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op, operandoTipoOp);
	}

	return 0;
}

int dup2_x2(execucao *p) { //duplica os dois primeiros elementos da pilha a baixo do quarto 0x5E
	tipoOperando op, op1, op2, op3;
	int operandoTipoOp, operandoTipoOp1, operandoTipoOp2, operandoTipoOp3;

	operandoTipoOp = p->frameAtual->topoPilhaOperandos->operandoTipo1;
	op = popOperando(&(p->frameAtual->topoPilhaOperandos));

	if(operandoTipoOp == TIPO1){
		operandoTipoOp1 = p->frameAtual->topoPilhaOperandos->operandoTipo1;
		op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	}

	operandoTipoOp2 = p->frameAtual->topoPilhaOperandos->operandoTipo1;
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));

	if(operandoTipoOp2 == TIPO1){
		operandoTipoOp3 = p->frameAtual->topoPilhaOperandos->operandoTipo1;
		op3 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	}

	if(operandoTipoOp == TIPO1 && operandoTipoOp2 == TIPO1){
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, operandoTipoOp1);
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op, operandoTipoOp);
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op3, operandoTipoOp3);
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op2, operandoTipoOp2);
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, operandoTipoOp1);
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op, operandoTipoOp);
	}
	else if(operandoTipoOp2 == TIPO1){
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op, operandoTipoOp);
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op3, operandoTipoOp3);
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op2, operandoTipoOp2);
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op, operandoTipoOp);
	}
	else if(operandoTipoOp == TIPO1){
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, operandoTipoOp1);
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op, operandoTipoOp);
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op2, operandoTipoOp2);
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, operandoTipoOp1);
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op, operandoTipoOp);
	}
	else{
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op, operandoTipoOp);
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op2, operandoTipoOp2);
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op, operandoTipoOp);
	}
	return 0;
}

int swap(execucao *p) { //troca os dois elementos do topo da pilha op:0x5F
	tipoOperando op1, op2;
	int operandoTipoOp1, operandoTipoOp2;

	operandoTipoOp1 = p->frameAtual->topoPilhaOperandos->operandoTipo1;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));

	operandoTipoOp2 = p->frameAtual->topoPilhaOperandos->operandoTipo1;
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));

	if (operandoTipoOp1 != TIPO1 || operandoTipoOp2 != TIPO1){
		printf("ERRO em swap: um dos operandos é tipo 2 (double ou long)\n");
		exit(1);
	}

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, operandoTipoOp1);
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op2, operandoTipoOp2);
	return 0;
}


// add --------------------------------------------------------------------------------------
int iadd(execucao *p){ // v1 , v2 -> v1+v2 op: 0x60
	tipoOperando op1, op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoInt = op2.tipoInt +  op1.tipoInt;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO1);
	return 0;
}

int ladd(execucao *p){ // v1 , v2 -> v1+v2 op: 0x61
	tipoOperando op1, op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoLong = op2.tipoLong +  op1.tipoLong;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO2);
	return 0;
}

int fadd(execucao *p){ // v1 , v2 -> v1+v2 op: 0x62
	tipoOperando op1, op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoFloat = op2.tipoFloat +  op1.tipoFloat;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO1);
	return 0;
}

int dadd(execucao *p){ // v1 , v2 -> v1+v2 op: 0x63
	tipoOperando op1, op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoDouble = op2.tipoDouble +  op1.tipoDouble;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO2);
	return 0;
}


// sub --------------------------------------------------------------------------------------
int isub(execucao *p){ // v1 , v2 -> v1-v2 op: 0x64
	tipoOperando op1, op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoInt = op2.tipoInt - op1.tipoInt;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO1);
	return 0;
}

int lsub(execucao *p){ // v1 , v2 -> v1-v2 op: 0x65
	tipoOperando op1, op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoFloat = op2.tipoFloat - op1.tipoFloat;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO2);
	return 0;
}

int fsub(execucao *p){ // v1 , v2 -> v1-v2 op: 0x66
	tipoOperando op1, op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoFloat = op2.tipoFloat - op1.tipoFloat;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO1);
	return 0;
}

int dsub(execucao *p){ // v1 , v2 -> v1-v2 op: 0x67
	tipoOperando op1, op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoDouble = op2.tipoDouble - op1.tipoDouble;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO2);
	return 0;
}

// mul --------------------------------------------------------------------------------------
int imul(execucao *p){ // v1 , v2 -> v1*v2 op: 0x68
	tipoOperando op1, op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoInt = op2.tipoInt * op1.tipoInt;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO1);
	return 0;
}

int lmul(execucao *p){ // v1 , v2 -> v1*v2 op: 0x69
	tipoOperando op1, op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoLong = op2.tipoLong * op1.tipoLong;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO2);
	return 0;
}

int fmul(execucao *p){ // v1 , v2 -> v1*v2 op: 0x6A
	tipoOperando op1, op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoFloat = op2.tipoFloat * op1.tipoFloat;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO1);
	return 0;
}

int dmul(execucao *p){ // v1 , v2 -> v1*v2 op: 0x6B
	tipoOperando op1, op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoDouble = op2.tipoDouble * op1.tipoDouble;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO2);
	return 0;
}

// div --------------------------------------------------------------------------------------
int idiv(execucao *p){ // v1 , v2 -> v1/v2 op: 0x6C
	tipoOperando op1, op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoInt = op2.tipoInt / op1.tipoInt;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO1);
	return 0;
}

int ldiv_(execucao *p){ // v1 , v2 -> v1 / v2 op: 0x6D
	tipoOperando op1, op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));

	op1.tipoLong = op2.tipoLong / op1.tipoLong;

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO2);

	return 0;

}

int fdiv(execucao *p){ // v1 , v2 -> v1/v2 op: 0x6E
	tipoOperando op1, op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoFloat = op2.tipoFloat / op1.tipoFloat;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO1);
	return 0;
}

int ddiv(execucao *p){ // v1 , v2 -> v1/v2 op: 0x6F
	tipoOperando op1, op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoDouble = op2.tipoDouble / op1.tipoDouble;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO2);
	return 0;
}

// rem --------------------------------------------------------------------------------------
int irem(execucao *p){ // v1 , v2 -> v1 mod v2 op: 0x70
	tipoOperando op1, op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoInt = op2.tipoInt % op1.tipoInt;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO1);
	return 0;
}

int lrem(execucao *p){ // v1 , v2 -> v1 mod v2 op: 0x71
	tipoOperando op1, op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoLong= op2.tipoLong % op1.tipoLong;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO2);
	return 0;
}

int frem(execucao *p){ // v1 , v2 -> v1 mod v2 op: 0x72
	tipoOperando op1, op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoFloat = (float) fmod(op2.tipoFloat, op1.tipoFloat);
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO1);
	return 0;
}

int drem_(execucao *p){ // v1 , v2 -> v1 mod v2 op: 0x73
	tipoOperando op1, op2;

	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));

	op1.tipoDouble = fmod(op2.tipoDouble, op1.tipoDouble);

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO2);

	return 0;
}


//neg --------------------------------------------------------------------------------------
int ineg(execucao *p){ // v1 -> -v1 op: 0x74
	tipoOperando op1;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoInt = 0 - op1.tipoInt;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO1);
	return 0;
}

int lneg(execucao *p){ // v1 -> -v1 op: 0x74
	tipoOperando op1;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoLong = 0 - op1.tipoLong;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO2);
	return 0;
}

int fneg(execucao *p){ // v1 -> -v1 op: 0x76
	tipoOperando op1;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoFloat = 0 - op1.tipoFloat;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO1);
	return 0;
}

int dneg(execucao *p){ // v1 -> -v1 op: 0x74
	tipoOperando op1;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoDouble = 0 - op1.tipoDouble;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO2);
	return 0;
}

// shifts --------------------------------------------------------------------------------
int ishl(execucao *p){ // v1 , v2 -> v1<<5 bits de baixo de v2 op: 0x78
	tipoOperando op1 , op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));	// v2
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));	// v1
	op1.tipoInt = op1.tipoInt & 0x1F;	// isolando os 5 bits menos significativos de v2
	op1.tipoInt = op2.tipoInt<<op1.tipoInt;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO1);
	return 0;
}

int lshl(execucao *p){ // v1 , v2 -> v1<<6 bits de baixo de v2 op: 0x78
	tipoOperando op1 , op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));	// v2
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));	// v1
	op1.tipoLong= op1.tipoLong & 0x3F;	// isolando os 6 bits menos significativos de v2
	op1.tipoLong = op2.tipoLong<<op1.tipoLong;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO2);
	return 0;
}

int ishr(execucao *p){ // v1 , v2 -> v1>>5 bits de baixo de v2 op: 0x7A
	tipoOperando op1 , op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));	// v2
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));	// v1
	op1.tipoInt = op1.tipoInt & 0x1F;	// isolando os 5 bits menos significativos de v2
	op1.tipoInt = op2.tipoInt>>op1.tipoInt;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO1);
	return 0;
}

int lshr(execucao *p){ // v1 , v2 -> v1>>5 bits de baixo de v2 op: 0x7A
	tipoOperando op1 , op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));	// v2
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));	// v1
	op1.tipoLong = op1.tipoLong & 0x3F;	// isolando os 5 bits menos significativos de v2
	op1.tipoLong = op2.tipoLong>>op1.tipoLong;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO2);
	return 0;
}


// bitwise ----------------------------------------------------------------------------------------------
int iand(execucao *p){// V1 , V2 -> V1 AND V2 op: 0x7E
	tipoOperando op1 , op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoInt = op1.tipoInt & op2.tipoInt;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO1);
	return 0;
}

int ior(execucao *p){// V1 , V2 -> V1 OR V2 op: 0x80
	tipoOperando op1 , op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoInt = op1.tipoInt | op2.tipoInt;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO1);
	return 0;
}

int ixor(execucao *p){// V1 , V2 -> V1 OR V2 op: 0x82
	tipoOperando op1 , op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoInt = op1.tipoInt ^ op2.tipoInt;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO1);
	return 0;
}

// retornos ----------------------------------------------------------------------------------------------

int ireturn(execucao *p){ // value -> empty , joga value na pilha de operandos  do frame que chamou op: 0xAC
	tipoOperando  op;
	op = popOperando(&(p->frameAtual->topoPilhaOperandos));
	popFrame(&(p->frameAtual));
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);
	return 1;
}

int lreturn(execucao *p){ // value -> empty op: 0xAD

	tipoOperando op;

	op = popOperando(&(p->frameAtual->topoPilhaOperandos));
	popFrame(&(p->frameAtual));
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO2);

	return 1;
}

int freturn(execucao *p){ // value -> empty op: 0xAE
	tipoOperando  op;
	op = popOperando(&(p->frameAtual->topoPilhaOperandos));
	popFrame(&(p->frameAtual));
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);
	return 1;
}

int dreturn(execucao *p){ // value -> empty op: 0xAF
	tipoOperando op;

	op = popOperando(&(p->frameAtual->topoPilhaOperandos));
	popFrame(&(p->frameAtual));
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO2);

	return 1;
}

int areturn(execucao *p){ // value -> empty op: 0xB0
	tipoOperando  op;
	op = popOperando(&(p->frameAtual->topoPilhaOperandos));
	popFrame(&(p->frameAtual));
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op, TIPO1);
	return 1;
}

int return_(execucao *p){ // -> empty, não retorna nada OP: 0xB1
	popFrame(&(p->frameAtual));
	return 1;
}


// Instrução que dada uma pilha com os argumentos, invoca um método
// Opcode: 0xB7
int invokespecial(execucao *p){

	int numArgs;
	char* nomeClasse;
	char* nomeMetodo;
	char* descritor;
	u2 indiceMethodRefInfo;
	u2 indiceClassInfo;
	u2 indiceNameAndTypeInfo;
	u2 indiceNomeMetodo;
	u2 indiceTipoMetodo;

	indiceMethodRefInfo = lerU2Codigo(p->frameAtual);

	indiceClassInfo = p->frameAtual->constantPool[indiceMethodRefInfo].info.methodRefInfo.classIndex;
	nomeClasse = (char*) buscaUTF8ConstPool(p->frameAtual->constantPool, p->frameAtual->constantPool[indiceClassInfo].info.classInfo.nameIndex);

	indiceNameAndTypeInfo = p->frameAtual->constantPool[indiceMethodRefInfo].info.methodRefInfo.nameAndTypeIndex;
	indiceNomeMetodo = p->frameAtual->constantPool[indiceNameAndTypeInfo].info.nameAndTypeInfo.nameIndex;
	nomeMetodo = buscaUTF8ConstPool(p->frameAtual->constantPool, indiceNomeMetodo);

	indiceTipoMetodo = p->frameAtual->constantPool[indiceNameAndTypeInfo].info.nameAndTypeInfo.descriptorIndex;
	descritor = buscaUTF8ConstPool(p->frameAtual->constantPool, indiceTipoMetodo);

	numArgs = contaArgumentosMetodo(descritor);

	//numArgs + 1 é para incluir a referência ao objeto
	preparaExecucaoMetodo(nomeClasse, nomeMetodo, descritor, p, numArgs + 1);
	executaMetodo(p);

	return 0;
}

int (*vetInstr[])(execucao *p) = {
	nop, // 0x00
	aconst_null,// 0x1
	iconst_m1,// 0x2
	iconst_0,// 0x3
	iconst_1,// 0x4
	iconst_2,// 0x5
	iconst_3,// 0x6
	iconst_4,// 0x7
	iconst_5,// 0x8
	lconst_0,// 0x9
	lconst_1,// 0xA
	fconst_0,// 0xB
	fconst_1,// 0xC
	fconst_2,// 0xD
	dconst_0,// 0xE
	dconst_1,// 0xF
	bipush,// 0x10
	sipush,// 0x11
	ldc,// 0x12
	nop,//ldc,// 0x13
	nop,//ldc,// 0x14
	iload,// 0x15
	lload,// 0x16
	fload,// 0x17
	dload,// 0x18
	aload,// 0x19
	iload_0,// 0x1A
	iload_1,// 0x1B
	iload_2,// 0x1C
	iload_3,// 0x1D
	lload_0,// 0x1E
	lload_1,// 0x1F
	lload_2,// 0x20
	lload_3,// 0x21
	fload_0,// 0x22
	fload_1,// 0x23
	fload_2,// 0x24
	fload_3,// 0x25
	dload_0,// 0x26
	dload_1,// 0x27
	dload_2,// 0x28
	dload_3,// 0x29
	aload_0,// 0x2A
	aload_1,// 0x2B
	aload_2,// 0x2C
	aload_3,// 0x2D
	nop,//iaload,// 0x2E
	nop,//laload,// 0x2F
	nop,//faload,// 0x30
	nop,//daload,// 0x31
	nop,//aaload,// 0x32
	nop,//baload,// 0x33
	nop,//caload,// 0x34
	nop,//saload,// 0x35
	nop,//istore,// 0x36
	nop,//lstore,// 0x37
	nop,//fstore,// 0x38
	nop,//dstore,// 0x39
	nop,//astore,// 0x3A
	nop,//istore,// 0x3B
	nop,//istore,// 0x3C
	nop,//istore,// 0x3D
	nop,//istore,// 0x3E
	nop,//lstore,// 0x3F
	nop,//lstore,// 0x40
	nop,//lstore,// 0x41
	nop,//lstore,// 0x42
	nop,//fstore,// 0x43
	nop,//fstore,// 0x44
	nop,//fstore,// 0x45
	nop,//fstore,// 0x46
	nop,//dstore,// 0x47
	nop,//dstore,// 0x48
	nop,//dstore,// 0x49
	nop,//dstore,// 0x4A
	nop,//astore,// 0x4B
	nop,//astore,// 0x4C
	nop,//astore,// 0x4D
	nop,//astore,// 0x4E
	nop,//iastore,// 0x4F
	nop,//lastore,// 0x50
	nop,//fastore,// 0x51
	nop,//dastore,// 0x52
	nop,//aastore,// 0x53
	nop,//bastore,// 0x54
	nop,//castore,// 0x55
	nop,//sastore,// 0x56
	nop,//pop,// 0x57
	nop,//pop2,// 0x58
	dup,//0x59
	dup_x1,//0x5A
	dup_x2,//0x5B
	dup2,// 0x5C
	dup2_x1,// 0x5D
	dup2_x2,// 0x5E
	swap,// 0x5F
	iadd,// 0x60
	ladd,// 0x61
	fadd,// 0x62
	dadd,// 0x63
	isub,// 0x64
	lsub,// 0x65
	fsub,// 0x66
	dsub,// 0x67
	imul,// 0x68
	lmul,// 0x69
	fmul,// 0x6A
	dmul,// 0x6B
	idiv,// 0x6C
	ldiv_,// 0x6D
	fdiv,// 0x6E
	ddiv,// 0x6F
	irem,// 0x70
	lrem,// 0x71
	frem,// 0x72
	drem_,// 0x73
	ineg,// 0x74
	lneg,// 0x75
	fneg,// 0x76
	dneg,// 0x77
	ishl,// 0x78
	nop,//lshl,// 0x79
	ishr,// 0x7A
	nop,//lshr,// 0x7B
	nop,//iushr,// 0x7C
	nop,//lushr,// 0x7D
	iand,// 0x7E
	nop,//land,// 0x7F
	ior,// 0x80
	nop,//lor,// 0x81
	ixor,// 0x82
	nop,//lxor,// 0x83
	nop,//iinc,// 0x84
	nop,//i2l,// 0x85
	nop,//i2f,// 0x86
	nop,//i2d,// 0x87
	nop,//l2i,// 0x88
	nop,//l2f,// 0x89
	nop,//l2d,// 0x8A
	nop,//f2i,// 0x8B
	nop,//f2l,// 0x8C
	nop,//f2d,// 0x8D
	nop,//d2i,// 0x8E
	nop,//d2l,// 0x8F
	nop,//d2f,// 0x90
	nop,//i2b,// 0x91
	nop,//i2c,// 0x92
	nop,//i2s,// 0x93
	nop,//lcmp,// 0x94
	nop,//fcmpl,// 0x95
	nop,//fcmpg,// 0x96
	nop,//dcmpl,// 0x97
	nop,//dcmpg,// 0x98
	nop,//ifeq,// 0x99
	nop,//ifne,// 0x9A
	nop,//iflt,// 0x9B
	nop,//ifge,// 0x9C
	nop,//ifgt,// 0x9D
	nop,//ifle,// 0x9E
	nop,//if_icmpeq,// 0x9F
	nop,//if_icmpne,// 0xA0
	nop,//if_icmplt,// 0xA1
	nop,//if_icmpge,// 0xA2
	nop,//if_icmpgt,// 0xA3
	nop,//if_icmple,// 0xA4
	nop,//if_acmpeq,// 0XA5
	nop,//if_acmpne,// 0xA6
	nop,//goto_,// 0xA7
	nop,//jsr,// 0xA8
	nop,//ret,// 0xA9
	nop,//tableswitch,// 0xAA
	nop,//lookupswitch,// 0xAB
	ireturn,// 0xAC
	lreturn,// 0xAD
	freturn,// 0xAE
	dreturn,// 0xAF
	areturn,// 0xB0
	return_,// 0xB1
	nop,//getstatic,// 0xB2
	nop,//putstatic,// 0xB3
	nop,//getfield,// 0xB4
	nop,//putfield,// 0xB5
	nop,//invokevirtual,// 0xB6
	nop,//invokespecial,// 0xB7
	nop,//invokestatic,// 0xB8
	nop,//nop,// 0xB9
	nop,//nop,// 0xBA
	nop,//new_,// 0xBB
	nop,//newarray,// 0xBC
	nop,//anewarray,// 0xBD
	nop,//arraylength,// 0xBE
	nop,//athrow,// 0xBF
	nop,//checkcast,// 0xC0
	nop,//instanceof,// 0xC1
	nop,//nop,// 0xC2
	nop,//nop,// 0xC3
	nop,//wide,// 0xC4
	nop,//multianewarray,// 0xC5
	nop,//ifnull,// 0xC6
	nop,//ifnonnull,// 0xC7
	nop,//goto_w,// 0xC8
	nop//jsr_// 0xC9
};
