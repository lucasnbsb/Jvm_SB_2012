/*
 * Arquivo inicial da JVM.
 *
 * Começa a ler o arquivo .class
 *
 */

#include <stdio.h>
#include <string.h>

int main(char* argv[], int argc){

	if(argc == 2 && strstr(argv[1],".class") != NULL){

	}
	else{
		printf("ERRO! Possíveis causas:\n");
		printf("\t1. Mais de um argumento de linha de comando foi passado\n");
		printf("\t2. Nao foi passado um argumento de linha de comando\n");
		printf("\t3. O arquivo nao possui a extensao .class\n");	//TODO - verificar extensao
	}

	return 0;
}
