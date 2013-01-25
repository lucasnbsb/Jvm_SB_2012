/*
 * ClassFile.h
 *
 *  Created on: 24/01/2013
 *      Author: Vitor
 *      Co-Author:Filipe
 */

//FONTE -  http://docs.oracle.com/javase/specs/jvms/se7/html/jvms-4.html

#ifndef CLASSFILE_H_
#define CLASSFILE_H_

/*
 * Definição dos tamanhos de bytes lidos do arquivo .class.
 */
typedef unsigned char u1;
typedef unsigned short u2;
typedef unsigned int u4;
typedef unsigned long u8;

//tabela dos access flags
#define ACC_PUBLIC	0x0001	//Declared public; may be accessed from outside its package.
#define ACC_FINAL	0x0010	//Declared final; no subclasses allowed.
#define ACC_SUPER	0x0020	//Treat superclass methods specially when invoked by the invokespecial instruction.
#define ACC_INTERFACE	0x0200	//Is an interface, not a class.
#define ACC_ABSTRACT	 0x0400	  //Declared abstract; must not be instantiated.
#define ACC_SYNTHETIC	0x1000	//Declared synthetic; not present in the source code.
#define ACC_ANNOTATION	 0x2000 //	Declared as an annotation type.
#define ACC_ENUM	0x4000	//Declared as an enum type.



/*
 * Union que indica os vários tipos possíveis da pool de constantes
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
	} interfaceMethodRef;

	struct {
		u2 stringIndex;
	} stringInfo;

	struct {
		u4 bytes;
	} integerInfo;

	struct {
		u4 bytes;
	} floatInfo;

	struct {

	} ;

} tipoConstPool;

/*
typedef struct _cpInfo{
	u1 tag;
	tipoConstPool constante;
} cpInfo;*/

// FONTE - http://docs.oracle.com/javase/specs/jvms/se7/html/jvms-4.html

typedef struct CP_info {
    u1 tag; //TODO - tabela de defines pra tags da constant pool
    u1 info[];
}cp_info;

typedef struct classfile {
    u4             magic; //  0xCAFEBABE
    u2             minor_version; // Versionamento  no formato M.m
    u2             major_version; // onde M = major version e m=minor version , determina se o arquivo será lido ou não
    u2             constant_pool_count; // numero de entradas na pool de constantes + 1 , um indice da pool só é valido se estiver entre 0 e constant_pool_count
     cp_info    *constant_pool; //deve ser alocado com constant_pool[constant_pool_count-1];
    u2             access_flags; // tabela de flags a ser consultada para checar a permissão de acesso ao classfile em questão , item 4.1 na fonte //TODO - implementar os defines da tabela
    u2             this_class; // deve ser uma entrada válida da constant_pool contendo uma estrutura do tipo CONSTANT_Class_info , item 4.4.1 na fonte
    u2             super_class; // deve ser 0 caso a classe não tenha herdado de uma superclasse ou uma entrada válida na constant pool  com uma struct CONSTANT_Class_info contendo informaçoes sobre a superclasse direta da classe em questão
    u2             interfaces_count; // contem o número de superinterfaces diretas da classe ou interface em questão
    u2             *interfaces; // deve ser alocado com interfaces[interfaces_count]  , deve ser uma entrada válida na constant_pool com as informações das interfaces da classe
    u2             fields_count; // numero de estruturas field_info na tabela de fields
    //field_info    *fields; //deve ser alocado com fields[fields_count] ,  cada valor deve ser um field_info(4.5 na fonte) com a descição completa de um field na classe em questão TODO implementar field_info
    u2             methods_count; // contem o número de estruturas method_info na biblioteca de métodos
    //method_info   *methods; // deve ser alocado com  methods[methods_count] , biblioteca de métodos TODO - implementar method_info
    u2             attributes_count; // numero de entradas na tabela de atributos
    //attribute_info *attributes;//deve ser alocado com attributes[attributes_count] ,  tabela de atributos TODO - implementar attribute_info
}ClassLoader;



#endif /* CLASSFILE_H_ */
