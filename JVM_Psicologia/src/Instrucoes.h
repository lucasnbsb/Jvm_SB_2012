/*
 * Instrucoes.h
 *
 *  Created on: 08/02/2013
 *      Author: Vitor
 */

#ifndef INSTRUCOES_H_
#define INSTRUCOES_H_

#include <stdio.h>
#include <stdlib.h>
#include "Frame.h"
#include "Execucao.h"
#include "FuncoesGerais.h"

int nop(execucao *p); // 0x00
int iconst_m1(execucao *p); //0x2
int iconst_0(execucao *p);// 0x3
int iconst_1(execucao *p);// 0x4
int iconst_2(execucao *p);// 0x5
int iconst_3(execucao *p);// 0x6
int iconst_4(execucao *p);// 0x7
int iconst_5(execucao *p);// 0x8
int lconst_0(execucao *p);// 0x9
int lconst_1(execucao *p);// 0xA
int fconst_0(execucao *p);// 0xB
int fconst_1(execucao *p);// 0xC
int fconst_2(execucao *p);// 0xD
int dconst_0(execucao *p);// 0xE
int dconst_1(execucao *p);// 0xF

// load ------------------------------------------------------------
int iload(execucao *p);//0x15
int lload(execucao *p);//0x16
int fload(execucao *p);//0x17
int dload(execucao *p);//0x18
int aload(execucao *p);//0x19
int iload_0(execucao *p); //0x1A
int iload_1(execucao *p); // 0X1B
int iload_2(execucao *p); // 0X1C
int iload_3(execucao *p); // 0X1D
int lload_0(execucao *p); // 0x1E
int lload_1(execucao *p); // 0x1F
int lload_2(execucao *p); // 0x20
int lload_3(execucao *p); // 0x21
int fload_0(execucao *p); // 0x22
int fload_1(execucao *p); // 0x23
int fload_2(execucao *p); // 0x24
int fload_3(execucao *p); // 0x25
int dload_0(execucao *p); // 0x26
int dload_1(execucao *p); // 0x27
int dload_2(execucao *p); // 0x28
int dload_3(execucao *p); // 0x29
int aload_0(execucao *p); // 0x2A
int aload_1(execucao *p); // 0x2B
int aload_2(execucao *p); // 0x2C
int aload_3(execucao *p); // 0x2D
int ldc(execucao *p); // 0x12

// store ------------------------------------------------------------
int store(execucao *p); // 0x36 , 0X37 , 0X38 , 0X39 , 0X3A
// dup ------------------------------------------------------------
int dup(execucao *p);// 0x59
int dup_x1(execucao *p); // 0x5A
int dup_x2(execucao *p); // 0x5B
int dup2(execucao *p); // 0x5C
int dup2_x1(execucao *p); // 0x5D
int dup2_x2(execucao *p); // 0x5E
// swap ----------------------------------------------------------
int swap(execucao *p);  //0x5F
// add ------------------------------------------------------------

int iadd(execucao *p);  //0x60
int ladd(execucao *p);  //0x61
int fadd(execucao *p);  //0x62
int dadd(execucao *p);  //0x63
// sub ------------------------------------------------------------

int isub(execucao *p);  //0x64
int lsub(execucao *p);  //0x65
int fsub(execucao *p);  //0x66
int dsub(execucao *p);  //0x67

// mul ------------------------------------------------------------
int imul(execucao *p);  //0x68
int lmul(execucao *p);  //0x69
int fmul(execucao *p);  //0x6A
int dmul(execucao *p);  //0x6B

// div-------------------------------------------------------------
int idiv(execucao *p);  //0x6C
//int ldiv(execucao *p);  //0x6D
int fdiv(execucao *p);  //0x6E
int ddiv(execucao *p);  //0x6F

// rem -----------------------------------------------------------
int irem(execucao *p);  //0x70
int lrem(execucao *p);  //0x71
int frem(execucao *p);  //0x72
//int drem(execucao *p);  //0x73

// neg -----------------------------------------------------------
int ineg(execucao *p);  //0x74
int lneg(execucao *p);  //0x75
int fneg(execucao *p);  //0x76
int dneg(execucao *p);  //0x77

// shl -----------------------------------------------------------
int ishl(execucao *p);  //0x78
int lshl(execucao *p);  //0x79

// shr -----------------------------------------------------------
int ishr(execucao *p);  //0x7A
int lshr(execucao *p);  //0x7B

int iand(execucao *p);  //0x7E
int ior(execucao *p);  //0x80
int ixor(execucao *p);  //0x82

// retornos ------------------------------------------------------
int ireturn(execucao *p);  //0xAC
int return_(execucao *p);  //0xB1

int invokespecial(execucao *p); // 0xB7

int (*vetInstr[])(execucao *p) ;

#endif /* INSTRUCOES_H_ */
