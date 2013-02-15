/*
 * Arquivo inicial da JVM.
 *
 * Come�a a ler o arquivo .class, faz a tarefa do ClassLoader
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ClassFile.h"
#include "DebugFuncs.h"
#include "ClassLoader.h"
#include "FuncoesGerais.h"

int main(int argc, char* argv[]){

	if(argc == 2 && strstr(argv[1],".class") != NULL){

		char nomeClasse[30];
		ClassFile cf;
		//methodInfo* m;

		strcpy(nomeClasse, argv[1]);

		cf = carregaClassFile(nomeClasse);

		printConstantPool(cf);

		//Teste de busca de m�todo por nome. Arquivo usado: Teste.class
		//m = buscaMetodoNome(cf, "getNome", "()[C");
		//
		//printf("\n\n\n%s\n", (char*) buscaUTF8ConstPool(cf,m->nameIndex));
	}
	else{
		printf("ERRO! Poss�veis causas:\n");
		printf("\t1. Mais de um argumento de linha de comando foi passado\n");
		printf("\t2. Nao foi passado um argumento de linha de comando\n");
		printf("\t3. O arquivo nao possui a extensao .class\n");
	}

	return 0;
}
