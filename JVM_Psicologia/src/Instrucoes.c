/*
 * Instrucoes.c
 *
 *  Created on: 08/02/2013
 *      Author: Vitor
 *
 *  Arquivo das instruções da JVM. Inclui as de alocação.
 */
#include "Instrucoes.h"

void nop(pilhaFrames *p) {
}

void iconst_m1(pilhaFrames *p) {

	tipoOperando op;

	op.tipoInt = -1;

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
}

void iconst_0(pilhaFrames *p) {

	tipoOperando op;

	op.tipoInt = 0;

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
}

void iconst_1(pilhaFrames *p) {

	tipoOperando op;

	op.tipoInt = 1;

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
}

void iconst_2(pilhaFrames *p) {

	tipoOperando op;

	op.tipoInt = 2;

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
}

void iconst_3(pilhaFrames *p) {

	tipoOperando op;

	op.tipoInt = 3;

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
}

void iconst_4(pilhaFrames *p) {

	tipoOperando op;

	op.tipoInt = 4;

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
}

void iconst_5(pilhaFrames *p) {

	tipoOperando op;

	op.tipoInt = 5;

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
}

void lconst_0(pilhaFrames *p) { // Insere na pilha a constante long 0 op: 0x9
	tipoOperando op;
	op.tipoLong = 0;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
}

void lconst_1(pilhaFrames *p) { // Insere na pilha a constante long 1 op: 0xA

	tipoOperando op;
	op.tipoLong = 1;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);

}

void fconst_0(pilhaFrames *p) { // Insere na pilha a constante float 0.0 op: 0xB
	tipoOperando op;
	op.tipoFloat = 0.0;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
}

void fconst_1(pilhaFrames *p) { // Insere na pilha a constante float 1.0 op: 0xC
	tipoOperando op;
	op.tipoFloat = 1.0;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
}

void fconst_2(pilhaFrames *p) { // Insere na pilha a constante long 2.0 op: 0xD
	tipoOperando op;
	op.tipoFloat = 2.0;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
}

void dconst_0(pilhaFrames *p) { // Insere na pilha a constante float 0.0 op: 0xE
	tipoOperando op;
	op.tipoDouble = 0.0;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
}

void dconst_1(pilhaFrames *p) { // Insere na pilha a constante float 0.0 op: 0xF
	tipoOperando op;
	op.tipoDouble = 1.0;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
}

void dup(pilhaFrames *p) { // duplica o elemento no topo da pilha op: 0x59
	tipoOperando op;
	op = popOperando(&(p->frameAtual->topoPilhaOperandos));
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
}

void dup_x1(pilhaFrames *p) { // duplica o elemento no topo da pilha , dois elementos a baixo  op: 0x5A
	tipoOperando op, op1;
	op = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1);
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
}

void dup_x2(pilhaFrames *p) { // duplica o elemento no topo da pilha tres a baixo op: 0x5B
	tipoOperando op, op1, op2;
	op = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op2);
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1);
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
}

void dup2(pilhaFrames *p) { // duplica o elemento no topo da pilha , dois elementos a baixo  op: 0x5C
	tipoOperando op, op1;
	op = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1);
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1);
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
}

void dup2_x1(pilhaFrames *p) { //duplica os dois primeiros elementos da pilha a baixo do terceiro 0x5D
	tipoOperando op, op1, op2;
	op = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1);
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op2);
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1);
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
}

void dup2_x2(pilhaFrames *p) { //duplica os dois primeiros elementos da pilha a baixo do quarto 0x5E
	tipoOperando op, op1, op2, op3;
	op = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op3 = popOperando(&(p->frameAtual->topoPilhaOperandos));

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1);
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op3);
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op2);
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1);
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
}

void swap(pilhaFrames *p) { //troca os dois elementos do topo da pilha op:0x5F
	tipoOperando op1, op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1);
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op2);
}

void iadd(pilhaFrames *p){ // v1 , v2 -> v1+v2 op: 0x60
	tipoOperando op1, op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoInt = op1.tipoInt +  op2.tipoInt;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1);
}

void fadd(pilhaFrames *p){ // v1 , v2 -> v1+v2 op: 0x62
	tipoOperando op1, op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoFloat = op1.tipoFloat +  op2.tipoFloat;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1);
}

void isub(pilhaFrames *p){ // v1 , v2 -> v1-v2 op: 0x64
	tipoOperando op1, op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoInt = op1.tipoInt - op2.tipoInt;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1);
}

void fsub(pilhaFrames *p){ // v1 , v2 -> v1-v2 op: 0x66
	tipoOperando op1, op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoFloat = op1.tipoFloat - op2.tipoFloat;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1);
}

void imul(pilhaFrames *p){ // v1 , v2 -> v1*v2 op: 0x64
	tipoOperando op1, op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoInt = op1.tipoInt * op2.tipoInt;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1);
}

void fmul(pilhaFrames *p){ // v1 , v2 -> v1*v2 op: 0x66
	tipoOperando op1, op2;
	op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op2 = popOperando(&(p->frameAtual->topoPilhaOperandos));
	op1.tipoFloat = op1.tipoFloat * op2.tipoFloat;
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op1);
}

void ireturn(pilhaFrames *p){ // value -> empty , joga value na pilha de operandos  do frame que chamou op: 0xAC
	tipoOperando  op;
	op = popOperando(&(p->frameAtual->topoPilhaOperandos));
	popFrame(&(p->frameAtual));
	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
}

void (*vetInstr[])(pilhaFrames *p) = {
	nop, // 0x
		nop,//aconst_null,// 0x
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
		nop,//bipush,// 0x
		nop,//sipush,// 0x
		nop,//ldc,// 0x
		nop,//ldc,// 0x
		nop,//ldc,// 0x
		nop,//iload,// 0x
		nop,//lload,// 0x
		nop,//fload,// 0x
		nop,//dload,// 0x
		nop,//aload,// 0x
		nop,//iload,// 0x
		nop,//iload,// 0x
		nop,//iload,// 0x
		nop,//iload,// 0x
		nop,//lload,// 0x
		nop,//lload,// 0x
		nop,//lload,// 0x
		nop,//lload,// 0x
		nop,//fload,// 0x
		nop,//fload,// 0x
		nop,//fload,// 0x
		nop,//fload,// 0x
		nop,//dload,// 0x
		nop,//dload,// 0x
		nop,//dload,// 0x
		nop,//dload,// 0x
		nop,//aload,// 0x
		nop,//aload,// 0x
		nop,//aload,// 0x
		nop,//aload,// 0x
		nop,//iaload,// 0x
		nop,//laload,// 0x
		nop,//faload,// 0x
		nop,//daload,// 0x
		nop,//aaload,// 0x
		nop,//baload,// 0x
		nop,//caload,// 0x
		nop,//saload,// 0x
		nop,//istore,// 0x
		nop,//lstore,// 0x
		nop,//fstore,// 0x
		nop,//dstore,// 0x
		nop,//astore,// 0x
		nop,//istore,// 0x
		nop,//istore,// 0x
		nop,//istore,// 0x
		nop,//istore,// 0x
		nop,//lstore,// 0x
		nop,//lstore,// 0x
		nop,//lstore,// 0x
		nop,//lstore,// 0x
		nop,//fstore,// 0x
		nop,//fstore,// 0x
		nop,//fstore,// 0x
		nop,//fstore,// 0x
		nop,//dstore,// 0x
		nop,//dstore,// 0x
		nop,//dstore,// 0x
		nop,//dstore,// 0x
		nop,//astore,// 0x
		nop,//astore,// 0x
		nop,//astore,// 0x
		nop,//astore,// 0x
		nop,//iastore,// 0x
		nop,//lastore,// 0x
		nop,//fastore,// 0x
		nop,//dastore,// 0x
		nop,//aastore,// 0x
		nop,//bastore,// 0x
		nop,//castore,// 0x
		nop,//sastore,// 0x
		nop,//pop,// 0x
		nop,//pop2,// 0x
		dup,//0x59
		dup_x1,//0x5A
		dup_x2,//0x5B
		dup2,// 0x5C
		dup2_x1,// 0x5D
		dup2_x2,// 0x5E
		swap,// 0x5F
		iadd,// 0x60
		nop,//ladd,// 0x
		fadd,// 0x62
		nop,//dadd,// 0x
		isub,// 0x64
		nop,//lsub,// 0x
		fsub,// 0x64
		nop,//dsub,// 0x
		imul,// 0x68
		nop,//lmul,// 0x
		fmul,// 0x6A
		nop,//dmul,// 0x
		nop,//idiv_,// 0x
		nop,//ldiv_,// 0x
		nop,//fdiv,// 0x
		nop,//ddiv,// 0x
		nop,//irem,// 0x
		nop,//lrem,// 0x
		nop,//frem,// 0x
		nop,//drem_,// 0x
		nop,//ineg,// 0x
		nop,//lneg,// 0x
		nop,//fneg,// 0x
		nop,//dneg,// 0x
		nop,//ishl,// 0x
		nop,//lshl,// 0x
		nop,//ishr,// 0x
		nop,//lshr,// 0x
		nop,//iushr,// 0x
		nop,//lushr,// 0x
		nop,//iand,// 0x
		nop,//land,// 0x
		nop,//ior,// 0x
		nop,//lor,// 0x
		nop,//ixor,// 0x
		nop,//lxor,// 0x
		nop,//iinc,// 0x
		nop,//i2l,// 0x
		nop,//i2f,// 0x
		nop,//i2d,// 0x
		nop,//l2i,// 0x
		nop,//l2f,// 0x
		nop,//l2d,// 0x
		nop,//f2i,// 0x
		nop,//f2l,// 0x
		nop,//f2d,// 0x
		nop,//d2i,// 0x
		nop,//d2l,// 0x
		nop,//d2f,// 0x
		nop,//i2b,// 0x
		nop,//i2c,// 0x
		nop,//i2s,// 0x
		nop,//lcmp,// 0x
		nop,//fcmpl,// 0x
		nop,//fcmpg,// 0x
		nop,//dcmpl,// 0x
		nop,//dcmpg,// 0x
		nop,//ifeq,// 0x
		nop,//ifne,// 0x
		nop,//iflt,// 0x
		nop,//ifge,// 0x
		nop,//ifgt,// 0x
		nop,//ifle,// 0x
		nop,//if_icmpeq,// 0x
		nop,//if_icmpne,// 0x
		nop,//if_icmplt,// 0x
		nop,//if_icmpge,// 0x
		nop,//if_icmpgt,// 0x
		nop,//if_icmple,// 0x
		nop,//if_acmpeq,// 0x
		nop,//if_acmpne,// 0x
		nop,//goto_,// 0x
		nop,//jsr,// 0x
		nop,//ret,// 0x
		nop,//tableswitch,// 0x
		nop,//lookupswitch,// 0x
		ireturn,// 0xAC
		nop,//return1,// 0xAD
		nop,//return1,// 0xAE
		nop,//return1,// 0xAF
		nop,//return1,// 0xB0
		nop,//return0,// 0xB1
		nop,//getstatic,// 0x
		nop,//putstatic,// 0x
		nop,//getfield,// 0x
		nop,//putfield,// 0x
		nop,//invokevirtual,// 0x
		nop,//invokespecial,// 0x
		nop,//invokestatic,// 0x
		nop,//nop,// 0x
		nop,//nop,// 0x
		nop,//new_,// 0x
		nop,//newarray,// 0x
		nop,//anewarray,// 0x
		nop,//arraylength,// 0x
		nop,//athrow,// 0x
		nop,//checkcast,// 0x
		nop,//instanceof,// 0x
		nop,//nop,// 0x
		nop,//nop,// 0x
		nop,//wide,// 0x
		nop,//multianewarray,// 0x
		nop,//ifnull,// 0x
		nop,//ifnonnull,// 0x
		nop,//goto_w,// 0x
		nop//jsr_// 0x
};
