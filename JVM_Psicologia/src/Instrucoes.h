/*
 * Instrucoes.h
 *
 *  Created on: 08/02/2013
 *      Author: Vitor
 */

#ifndef INSTRUCOES_H_
#define INSTRUCOES_H_

#include "Frame.h"

void nop(pilhaFrames *p); // 0x00
void iconst_m1(pilhaFrames *p); //0x2
void iconst_0(pilhaFrames *p);// 0x3
void iconst_1(pilhaFrames *p);// 0x4
void iconst_2(pilhaFrames *p);// 0x5
void iconst_3(pilhaFrames *p);// 0x6
void iconst_4(pilhaFrames *p);// 0x7
void iconst_5(pilhaFrames *p);// 0x8
void lconst_0(pilhaFrames *p);// 0x9
void lconst_1(pilhaFrames *p);// 0xA
void fconst_0(pilhaFrames *p);// 0xB
void fconst_1(pilhaFrames *p);// 0xC
void fconst_2(pilhaFrames *p);// 0xD
void dconst_0(pilhaFrames *p);// 0xE
void dconst_1(pilhaFrames *p);// 0xF

// dup ------------------------------------------------------------
void dup(pilhaFrames *p);// 0x59
void dup_x1(pilhaFrames *p); // 0x5A
void dup_x2(pilhaFrames *p); // 0x5B
void dup2(pilhaFrames *p); // 0x5C
void dup2_x1(pilhaFrames *p); // 0x5D
void dup2_x2(pilhaFrames *p); // 0x5E
// swap ----------------------------------------------------------
void swap(pilhaFrames *p);  //0x5F
// add ------------------------------------------------------------

void iadd(pilhaFrames *p);  //0x60
//void ladd(pilhaFrames *p);  //0x61
void fadd(pilhaFrames *p);  //0x62
//void dadd(pilhaFrames *p);  //0x63
// sub ------------------------------------------------------------

void isub(pilhaFrames *p);  //0x64
//void lsub(pilhaFrames *p);  //0x65
void fsub(pilhaFrames *p);  //0x66
//void dsub(pilhaFrames *p);  //0x67

// mul ------------------------------------------------------------
void imul(pilhaFrames *p);  //0x68
//void lmul(pilhaFrames *p);  //0x69
void fmul(pilhaFrames *p);  //0x6A
//void dmul(pilhaFrames *p);  //0x6B

// div-------------------------------------------------------------
void idiv(pilhaFrames *p);  //0x6C
//void ldiv(pilhaFrames *p);  //0x6D
void fdiv(pilhaFrames *p);  //0x6E
//void ddiv(pilhaFrames *p);  //0x6F

// rem -----------------------------------------------------------
void irem(pilhaFrames *p);  //0x70
//void lrem(pilhaFrames *p);  //0x71
void frem(pilhaFrames *p);  //0x72
//void drem(pilhaFrames *p);  //0x73

// neg -----------------------------------------------------------
void ineg(pilhaFrames *p);  //0x74
//void lneg(pilhaFrames *p);  //0x75
void fneg(pilhaFrames *p);  //0x76
//void dneg(pilhaFrames *p);  //0x77

// shl -----------------------------------------------------------
void ishl(pilhaFrames *p);  //0x78
void lshl(pilhaFrames *p);  //0x79

// shr -----------------------------------------------------------
void ishr(pilhaFrames *p);  //0x7A
void lshr(pilhaFrames *p);  //0x7B

void ireturn(pilhaFrames *p);  //0xAC

void (*vetInstr[])(pilhaFrames *p) ;

#endif /* INSTRUCOES_H_ */
