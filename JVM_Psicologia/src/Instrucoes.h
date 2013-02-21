/*
 * Instrucoes.h
 *
 *  Created on: 08/02/2013
 *      Author: Vitor
 */

#ifndef INSTRUCOES_H_
#define INSTRUCOES_H_

#include "Frame.h"
#include "Execucao.h"

void nop(execucao *p); // 0x00
void iconst_m1(execucao *p); //0x2
void iconst_0(execucao *p);// 0x3
void iconst_1(execucao *p);// 0x4
void iconst_2(execucao *p);// 0x5
void iconst_3(execucao *p);// 0x6
void iconst_4(execucao *p);// 0x7
void iconst_5(execucao *p);// 0x8
void lconst_0(execucao *p);// 0x9
void lconst_1(execucao *p);// 0xA
void fconst_0(execucao *p);// 0xB
void fconst_1(execucao *p);// 0xC
void fconst_2(execucao *p);// 0xD
void dconst_0(execucao *p);// 0xE
void dconst_1(execucao *p);// 0xF

// dup ------------------------------------------------------------
void dup(execucao *p);// 0x59
void dup_x1(execucao *p); // 0x5A
void dup_x2(execucao *p); // 0x5B
void dup2(execucao *p); // 0x5C
void dup2_x1(execucao *p); // 0x5D
void dup2_x2(execucao *p); // 0x5E
// swap ----------------------------------------------------------
void swap(execucao *p);  //0x5F
// add ------------------------------------------------------------

void iadd(execucao *p);  //0x60
//void ladd(execucao *p);  //0x61
void fadd(execucao *p);  //0x62
//void dadd(execucao *p);  //0x63
// sub ------------------------------------------------------------

void isub(execucao *p);  //0x64
//void lsub(execucao *p);  //0x65
void fsub(execucao *p);  //0x66
//void dsub(execucao *p);  //0x67

// mul ------------------------------------------------------------
void imul(execucao *p);  //0x68
//void lmul(execucao *p);  //0x69
void fmul(execucao *p);  //0x6A
//void dmul(execucao *p);  //0x6B

// div-------------------------------------------------------------
void idiv(execucao *p);  //0x6C
//void ldiv(execucao *p);  //0x6D
void fdiv(execucao *p);  //0x6E
//void ddiv(execucao *p);  //0x6F

// rem -----------------------------------------------------------
void irem(execucao *p);  //0x70
//void lrem(execucao *p);  //0x71
void frem(execucao *p);  //0x72
//void drem(execucao *p);  //0x73

// neg -----------------------------------------------------------
void ineg(execucao *p);  //0x74
//void lneg(execucao *p);  //0x75
void fneg(execucao *p);  //0x76
//void dneg(execucao *p);  //0x77

// shl -----------------------------------------------------------
void ishl(execucao *p);  //0x78
void lshl(execucao *p);  //0x79

// shr -----------------------------------------------------------
void ishr(execucao *p);  //0x7A
void lshr(execucao *p);  //0x7B

void ireturn(execucao *p);  //0xAC

void (*vetInstr[])(execucao *p) ;

#endif /* INSTRUCOES_H_ */
