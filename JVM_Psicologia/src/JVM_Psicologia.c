/*
 * Arquivo inicial da JVM.
 *
 * Começa a ler o arquivo .class
 *
 */

#include <stdio.h>

int main(char* argv[], int argc){

	if(argc == 2){

	}
	else{
		printf("ERRO! Possíveis causas:\n");
		printf("\t1. Mais de um argumento de linha de comando foi passado");
		printf("\t2. Nao foi passado um argumento de linha de comando");
		printf("\t3. O arquivo nao possui a extensao .class");	//TODO - verificar extensao
	}

	return 0;
}
