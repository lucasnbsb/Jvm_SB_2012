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


void dup(pilhaFrames *p);// 0x59
void dup_x1(pilhaFrames *p); // 0x5A
void dup_x2(pilhaFrames *p); // 0x5B
void dup2(pilhaFrames *p); // 0x5C
void dup2_x1(pilhaFrames *p); // 0x5D
void dup2_x2(pilhaFrames *p); // 0x5E
void swap(pilhaFrames *p);  //0x5F

void (*vetInstr[])(pilhaFrames *p) ;

#endif /* INSTRUCOES_H_ */
