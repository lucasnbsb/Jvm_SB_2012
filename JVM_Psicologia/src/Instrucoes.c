/*
 * Instrucoes.c
 *
 *  Created on: 08/02/2013
 *      Author: Vitor
 *
 *  Arquivo das instruções da JVM. Inclui as de alocação.
 */
#include "Instrucoes.h"

void nop(pilhaFrames *p){
}

void iconst_m1(pilhaFrames *p){

	tipoOperando op;

	op.tipoInt = -1;

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
}

void iconst_0(pilhaFrames *p){

	tipoOperando op;

	op.tipoInt = 0;

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
}

void iconst_1(pilhaFrames *p){

	tipoOperando op;

	op.tipoInt = 1;

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
}

void iconst_2(pilhaFrames *p){

	tipoOperando op;

	op.tipoInt = 2;

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
}

void iconst_3(pilhaFrames *p){

	tipoOperando op;

	op.tipoInt = 3;

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
}

void iconst_4(pilhaFrames *p){

	tipoOperando op;

	op.tipoInt = 4;

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
}

void iconst_5(pilhaFrames *p){

	tipoOperando op;

	op.tipoInt = 5;

	pushOperando(&(p->frameAtual->topoPilhaOperandos), op);
}

void lconst_0(pilhaFrames *p){ // Insere na pilha a constante long 0 op: 0x9
	tipoOperando op;
	op.tipoLong = 0;
	pushOperando(&(p->frameAtual->topoPilhaOperandos) , op);
}

void lconst_1(pilhaFrames *p){ // Insere na pilha a constante long 1 op: 0xA

	tipoOperando op;
	op.tipoLong = 1;
	pushOperando(&(p->frameAtual->topoPilhaOperandos) , op);

}

void fconst_0(pilhaFrames *p){ // Insere na pilha a constante float 0.0 op: 0xB
	tipoOperando op;
	op.tipoFloat = 0.0;
	pushOperando(&(p->frameAtual->topoPilhaOperandos) , op);
}

void fconst_1(pilhaFrames *p){ // Insere na pilha a constante float 1.0 op: 0xC
	tipoOperando op;
	op.tipoFloat = 1.0;
	pushOperando(&(p->frameAtual->topoPilhaOperandos) , op);
}

void fconst_2(pilhaFrames *p){ // Insere na pilha a constante long 2.0 op: 0xD
	tipoOperando op;
	op.tipoFloat = 2.0;
	pushOperando(&(p->frameAtual->topoPilhaOperandos) , op);
}

void dconst_0(pilhaFrames *p){ // Insere na pilha a constante float 0.0 op: 0xE
	tipoOperando op;
	op.tipoDouble = 0.0;
	pushOperando(&(p->frameAtual->topoPilhaOperandos) , op);
}

void dconst_1(pilhaFrames *p){ // Insere na pilha a constante float 0.0 op: 0xF
	tipoOperando op;
	op.tipoDouble = 1.0;
	pushOperando(&(p->frameAtual->topoPilhaOperandos) , op);
}

void dup(pilhaFrames *p){
	tipoOperando op;
	op = popOperando(&(p->frameAtual->topoPilhaOperandos));
	pushOperando(&(p->frameAtual->topoPilhaOperandos) , op);
	pushOperando(&(p->frameAtual->topoPilhaOperandos) , op);
}

void (*vetInstr[])(pilhaFrames *p) = {
	nop,
	nop,//aconst_null,
	iconst_m1,//0x2
	iconst_0,//0x3
	iconst_1,//0x4
	iconst_2,//0x5
	iconst_3,//0x6
	iconst_4,//0x7
	iconst_5,//0x8
	lconst_0,//0x9
	lconst_1,//0xA
	fconst_0,//0xB
	fconst_1,//0xC
	fconst_2,//0xD
	dconst_0,//0xE
	dconst_1,//0xF
	nop,//bipush,
	nop,//sipush,
	nop,//ldc,
	nop,//ldc,
	nop,//ldc,
	nop,//iload,
	nop,//lload,
	nop,//fload,
	nop,//dload,
	nop,//aload,
	nop,//iload,
	nop,//iload,
	nop,//iload,
	nop,//iload,
	nop,//lload,
	nop,//lload,
	nop,//lload,
	nop,//lload,
	nop,//fload,
	nop,//fload,
	nop,//fload,
	nop,//fload,
	nop,//dload,
	nop,//dload,
	nop,//dload,
	nop,//dload,
	nop,//aload,
	nop,//aload,
	nop,//aload,
	nop,//aload,
	nop,//iaload,
	nop,//laload,
	nop,//faload,
	nop,//daload,
	nop,//aaload,
	nop,//baload,
	nop,//caload,
	nop,//saload,
	nop,//istore,
	nop,//lstore,
	nop,//fstore,
	nop,//dstore,
	nop,//astore,
	nop,//istore,
	nop,//istore,
	nop,//istore,
	nop,//istore,
	nop,//lstore,
	nop,//lstore,
	nop,//lstore,
	nop,//lstore,
	nop,//fstore,
	nop,//fstore,
	nop,//fstore,
	nop,//fstore,
	nop,//dstore,
	nop,//dstore,
	nop,//dstore,
	nop,//dstore,
	nop,//astore,
	nop,//astore,
	nop,//astore,
	nop,//astore,
	nop,//iastore,
	nop,//lastore,
	nop,//fastore,
	nop,//dastore,
	nop,//aastore,
	nop,//bastore,
	nop,//castore,
	nop,//sastore,
	nop,//pop,
	nop,//pop2,
	dup, //0x59
	nop,//dup_x1,
	nop,//dup_x2,
	nop,//dup2,
	nop,//dup2_x1,
	nop,//dup2_x2,
	nop,//swap,
	nop,//iadd,
	nop,//ladd,
	nop,//fadd,
	nop,//dadd,
	nop,//isub,
	nop,//lsub,
	nop,//fsub,
	nop,//dsub,
	nop,//imul,
	nop,//lmul,
	nop,//fmul,
	nop,//dmul,
	nop,//idiv_,
	nop,//ldiv_,
	nop,//fdiv,
	nop,//ddiv,
	nop,//irem,
	nop,//lrem,
	nop,//frem,
	nop,//drem_,
	nop,//ineg,
	nop,//lneg,
	nop,//fneg,
	nop,//dneg,
	nop,//ishl,
	nop,//lshl,
	nop,//ishr,
	nop,//lshr,
	nop,//iushr,
	nop,//lushr,
	nop,//iand,
	nop,//land,
	nop,//ior,
	nop,//lor,
	nop,//ixor,
	nop,//lxor,
	nop,//iinc,
	nop,//i2l,
	nop,//i2f,
	nop,//i2d,
	nop,//l2i,
	nop,//l2f,
	nop,//l2d,
	nop,//f2i,
	nop,//f2l,
	nop,//f2d,
	nop,//d2i,
	nop,//d2l,
	nop,//d2f,
	nop,//i2b,
	nop,//i2c,
	nop,//i2s,
	nop,//lcmp,
	nop,//fcmpl,
	nop,//fcmpg,
	nop,//dcmpl,
	nop,//dcmpg,
	nop,//ifeq,
	nop,//ifne,
	nop,//iflt,
	nop,//ifge,
	nop,//ifgt,
	nop,//ifle,
	nop,//if_icmpeq,
	nop,//if_icmpne,
	nop,//if_icmplt,
	nop,//if_icmpge,
	nop,//if_icmpgt,
	nop,//if_icmple,
	nop,//if_acmpeq,
	nop,//if_acmpne,
	nop,//goto_,
	nop,//jsr,
	nop,//ret,
	nop,//tableswitch,
	nop,//lookupswitch,
	nop,//return1,
	nop,//return1,
	nop,//return1,
	nop,//return1,
	nop,//return1,
	nop,//return0,
	nop,//getstatic,
	nop,//putstatic,
	nop,//getfield,
	nop,//putfield,
	nop,//invokevirtual,
	nop,//invokespecial,
	nop,//invokestatic,
	nop,//nop,
	nop,//nop,
	nop,//new_,
	nop,//newarray,
	nop,//anewarray,
	nop,//arraylength,
	nop,//athrow,
	nop,//checkcast,
	nop,//instanceof,
	nop,//nop,
	nop,//nop,
	nop,//wide,
	nop,//multianewarray,
	nop,//ifnull,
	nop,//ifnonnull,
	nop,//goto_w,
	nop//jsr_
};
