/*
 * ClassFile.h
 *
 *  Created on: 24/01/2013
 *      Author: Vitor
 *      Co-Author: Filipe
 */

#ifndef CLASSFILE_H_
#define CLASSFILE_H_

/*
 * Definição dos tamanhos de bytes lidos do arquivo .class.
 */
typedef unsigned char u1;
typedef unsigned short u2;
typedef unsigned int u4;
typedef unsigned long u8;

/*
 * Union que indica os vários tipos possíveis da pool de constantes
 */
typedef union _tipoConstPool{



} tipoConstPool;

typedef struct _cpInfo{

	u1 tag;
	tipoConstPool constante;

} cpInfo;

typedef struct _classFile{

	u4 magic;

	u2 minorVersion;
	u2 majorVersion;

	u2 constantPoolCount;

	/*IMPORTANTE:
	 * a tabela de constantes é indexada a partir de 1
	 */
	cpInfo *constantPool;

} classFile;

#endif /* CLASSFILE_H_ */
