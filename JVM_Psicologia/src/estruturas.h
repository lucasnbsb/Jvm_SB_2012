/*
 * estruturas.h
 *
 *  Created on: 25/01/2013
 *      Author: Lucas_Neto
 */

#ifndef ESTRUTURAS_H_
#define ESTRUTURAS_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdint.h>
#include<windows.h>

typedef uint8_t u1;
typedef uint16_t u2;
typedef uint32_t u4;
typedef uint64_t u8;

// FONTE - http://docs.oracle.com/javase/specs/jvms/se7/html/jvms-4.html

typedef struct CP_info {
    u1 tag; //TODO - tabela de defines pra tags da constant pool
    u1 info[];
}cp_info;

struct classfile;

typedef struct classfile {
    u4             magic; //  0xCAFEBABE
    u2             minor_version; // Versionamento  no formato M.m
    u2             major_version; // onde M = major version e m=minor version , determina se o arquivo ser� lido ou n�o
    u2             constant_pool_count; // numero de entradas na pool de constantes + 1 , um indice da pool s� � valido se estiver entre 0 e constant_pool_count
     cp_info    *constant_pool; //deve ser alocado com constant_pool[constant_pool_count-1];
    u2             access_flags; // tabela de flags a ser consultada para checar a permiss�o de acesso ao classfile em quest�o , item 4.1 na fonte //TODO - implementar os defines da tabela
    u2             this_class; // deve ser uma entrada v�lida da constant_pool contendo uma estrutura do tipo CONSTANT_Class_info , item 4.4.1 na fonte
    u2             super_class; // deve ser 0 caso a classe n�o tenha herdado de uma superclasse ou uma entrada v�lida na constant pool  com uma struct CONSTANT_Class_info contendo informa�oes sobre a superclasse direta da classe em quest�o
    u2             interfaces_count; // contem o n�mero de superinterfaces diretas da classe ou interface em quest�o
    u2             *interfaces; // deve ser alocado com interfaces[interfaces_count]  , deve ser uma entrada v�lida na constant_pool com as informa��es das interfaces da classe
    u2             fields_count; // numero de estruturas field_info na tabela de fields
    //field_info    *fields; //deve ser alocado com fields[fields_count] ,  cada valor deve ser um field_info(4.5 na fonte) com a desci��o completa de um field na classe em quest�o TODO implementar field_info
    u2             methods_count; // contem o n�mero de estruturas method_info na biblioteca de m�todos
    //method_info   *methods; // deve ser alocado com  methods[methods_count] , biblioteca de m�todos TODO - implementar method_info
    u2             attributes_count; // numero de entradas na tabela de atributos
    //attribute_info *attributes;//deve ser alocado com attributes[attributes_count] ,  tabela de atributos TODO - implementar attribute_info
}ClassLoader;



#endif /* ESTRUTURAS_H_ */
