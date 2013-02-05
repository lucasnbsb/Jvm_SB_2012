/*
 * Arquivo inicial da JVM.
 *
 * Começa a ler o arquivo .class, faz a tarefa do ClassLoader
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ClassFile.h"
#include "DebugFuncs.h"
#include "ClassLoader.h"

int main(int argc, char* argv[]){

	if(argc == 2 && strstr(argv[1],".class") != NULL){

		char nomeClasse[30];
		ClassFile cf;

		strcpy(nomeClasse, argv[1]);

		cf = carregaClassFile(nomeClasse);

		printConstantPool(cf);
	}
	else{
		printf("ERRO! Possíveis causas:\n");
		printf("\t1. Mais de um argumento de linha de comando foi passado\n");
		printf("\t2. Nao foi passado um argumento de linha de comando\n");
		printf("\t3. O arquivo nao possui a extensao .class\n");
	}

	return 0;
}
