/*
 * ClassFile.h
 *
 *  Created on: 24/01/2013
 *      Author: Vitor
 *      Co-Author:Filipe
 */

//FONTE -  http://docs.oracle.com/javase/specs/jvms/se5.0/html/VMSpecTOC.doc.html

#ifndef CLASSFILE_H_
#define CLASSFILE_H_

/*
 * Defini��o dos tamanhos de bytes lidos do arquivo .class.
 */
typedef unsigned char u1;
typedef unsigned short u2;
typedef unsigned int u4;
typedef unsigned long u8;

//Tabela dos constant_infos
#define CONSTANT_Class				7
#define CONSTANT_FieldRef			9
#define CONSTANT_Methodref			10
#define CONSTANT_InterfaceMethodRef	11
#define CONSTANT_String				8
#define CONSTANT_Integer			3
#define CONSTANT_Float				4
#define CONSTANT_Long				5
#define CONSTANT_Double				6
#define CONSTANT_NameAndType		12
#define CONSTANT_UTF8				1
#define CONSTANT_MethodHandle		15
#define CONSTANT_MethodType			16
#define CONSTANT_InvokeDynamic		18

//Tabela dos access flags de classes
#define ACC_PUBLIC		0x0001	//Declared public; may be accessed from outside its package.
#define ACC_FINAL		0x0010	//Declared final; no subclasses allowed.
#define ACC_SUPER		0x0020	//Treat superclass methods specially when invoked by the invokespecial instruction.
#define ACC_INTERFACE	0x0200	//Is an interface, not a class.
#define ACC_ABSTRACT	0x0400	  //Declared abstract; must not be instantiated.
#define ACC_SYNTHETIC	0x1000	//Declared synthetic; not present in the source code.
#define ACC_ANNOTATION	0x2000 //	Declared as an annotation type.
#define ACC_ENUM		0x4000	//Declared as an enum type.

//Tabela dos access flags de campos (flags n�o definidas s�o aproveitadas da tabela de classes)
#define ACC_PRIVATE		0x0002	//Declared private;
#define ACC_PROTECTED	0x0004	//Declared protected;
#define ACC_STATIC		0x0008	//Declared static;
#define ACC_VOLATILE	0x0040	//Declared volatile;
#define ACC_TRANSIENT	0x0080	//Decalred transient;

//Tabela dos access flags de m�todos (flags n�o definidas s�o aproveitadas das tabelas acima)
#define ACC_SYNCHRONIZED	0x0020	//Declared synchronized;
#define ACC_BRIDGE			0x0040	//Method generated by compiler;
#define ACC_VARARGS			0x0080	//Declared with variable number of arguments;
#define ACC_NATIVE			0x0100	//Declared native;
#define ACC_STRICT			0x0800	//Declared strict;

//Tags das verificacoes de vari�veis
#define ITEM_Top				0
#define ITEM_Integer			1
#define ITEM_Float				2
#define ITEM_Double				3
#define ITEM_Long				4
#define ITEM_Null				5
#define ITEM_UninitializedThis	6
#define ITEM_Object				7
#define ITEM_Uninitialized		8

typedef union _float{
	u4 bytes;
	float num;
} uFloat;

typedef union _double{
	u8 bytes;
	double num;
} uDouble;

/*
 * Union que indica os v�rios tipos poss�veis da pool de constantes
 */
typedef union _tipoConstPool{

	struct {
		u2 nameIndex;
	} classInfo;

	struct {
		u2 classIndex;
		u2 nameAndTypeIndex;
	} fieldRefInfo;

	struct {
		u2 classIndex;
		u2 nameAndTypeIndex;
	} methodRefInfo;

	struct {
		u2 classIndex;
		u2 nameAndTypeIndex;
	} interfaceMethodRefInfo;

	struct {
		u2 stringIndex;
	} stringInfo;

	struct {
		u4 bytes;
	} integerInfo;

	struct {
		uFloat f;
	} floatInfo;

	struct {
		u8 bytes;
	} longInfo;

	struct {
		uDouble d;
	} doubleInfo;

	struct {
		u2 nameIndex;
		u2 descriptorIndex;
	} nameAndTypeInfo;

	struct {
		u2 length;
		u1 *bytes;
	} UTF8Info;

} tipoConstPool;

/*
 * Estrutura da pool de constantes.
 */
typedef struct CP_info {
    u1 tag;
    tipoConstPool info;
}cpInfo;

/*
 * Tabela de exce��es, usada na parte de code de tipoAttributeInfo
 */
typedef struct _exceptionTable{
	u2 startPC;
	u2 endPC;
	u2 handlerPC;
	u2 catchType;
} exceptionTable;

/*
 * Estrutura usada para debuggar c�digo de Java (provavelmente n�o � necess�ria na nossa implementa��o)
 */
typedef struct _lineNumberTable {
	u2 startPC;
	u2 lineNumber;
} lineNumberTable;

/*
 * Toda entrada CONSTANT_Class_info na constant_pool que representa uma classe ou interface C
 * que n�o � um membro do pacote deve ter exatamente uma entrada correspondente no array de classes.
 */
typedef struct _classes {
	u2 innerClassInfoIndex;
	u2 outerClassInfoIndex;
	u2 innerNameIndex;
	u2 innerClassAccessFlags;
} classes;

/*
 * Um atributo da classe, seja m�todo, constante, membro, etc.
 */
typedef struct _attributeInfo {
	u2 attributeNameIndex;
	u4 attributeLength;
	union {
		struct {
			u2 constantValueIndex;	//�ndice v�lido para a constant pool
		} constantValue;

		struct {
			u2 maxStack;
			u2 maxLocals;
			u4 codeLength;
			u1 *code;
			u2 exceptionTableLength;
			exceptionTable *excTable;
			u2 attributesCount;
			struct _attributeInfo *attributes;	//Tamanho: attributesCount
		} code;

		struct {
			u2 numberOfExceptions;
			u2 *exceptionIndexTable;	//Tamanho: numberOfExceptions
		} exceptions;

		struct {
			//Vazia??
		} synthetic;

		struct {
			u2 sourceFileIndex;	//�ndice valido para a constant pool
		} sourceFile;

		struct {
			u2 numberOfClasses;
			classes *classes;	//Tamanho: numberOfClasses
		} innerClasses;

		struct {
			u1 *info;
		} unknown;

	}tipoInfo;

} attributeInfo;

/*
 * Informa��es sobre campos de classes
 */
typedef struct _fieldInfo {
	u2 accessFlags;
	u2 nameIndex;
	u2 descriptorIndex;
	u2 attributesCount;
	attributeInfo *attributes;	//Tamanho: attributesCount
} fieldInfo;

/*
 * Estrutura que descreve os m�todos da class
 */
typedef struct _methodInfo {
	u2 accessFlags;
	u2 nameIndex;
	u2 descriptorIndex;
	u2 attributesCount;
	attributeInfo *attributes;	//Tamanho: attributesCount
} methodInfo;

/*
 * Estrutura de topo, dela saem todas as outras.
 */
typedef struct classfile {
    u4             	magic; 				//0xCAFEBABE
    u2             	minor_version; 		// Versionamento  no formato M.m
    u2             	major_version; 		// onde M = major version e m=minor version , determina se o arquivo ser� lido ou n�o
    u2             	constant_pool_count;// numero de entradas na pool de constantes + 1 , um indice da pool s� � valido se estiver entre 0 e constant_pool_count
    cpInfo    		*constant_pool; 	//deve ser alocado com constant_pool[constant_pool_count-1];
    u2             	access_flags; 		// tabela de flags a ser consultada para checar a permiss�o de acesso ao classfile em quest�o , item 4.1 na fonte
    u2             	this_class; 		// deve ser uma entrada v�lida da constant_pool contendo uma estrutura do tipo CONSTANT_Class_info , item 4.4.1 na fonte
    u2             	super_class; 		// deve ser 0 caso a classe n�o tenha herdado de uma superclasse ou uma entrada v�lida na constant pool  com uma struct CONSTANT_Class_info contendo informa�oes sobre a superclasse direta da classe em quest�o
    u2             	interfaces_count; 	// contem o n�mero de superinterfaces diretas da classe ou interface em quest�o
    u2             	*interfaces; 		// deve ser alocado com interfaces[interfaces_count]  , deve ser uma entrada v�lida na constant_pool com as informa��es das interfaces da classe
    u2             	fields_count; 		// numero de estruturas field_info na tabela de fields
    fieldInfo    	*fields; 			//deve ser alocado com fields[fields_count] ,  cada valor deve ser um field_info(4.5 na fonte) com a desci��o completa de um field na classe em quest�o
    u2             	methods_count; 		// contem o n�mero de estruturas method_info na biblioteca de m�todos
    methodInfo   	*methods; 			// deve ser alocado com  methods[methods_count] , biblioteca de m�todos
    u2             	attributes_count; 	// numero de entradas na tabela de atributos
    attributeInfo 	*attributes;		//deve ser alocado com attributes[attributes_count] ,  tabela de atributos
}ClassFile;




#endif /* CLASSFILE_H_ */
