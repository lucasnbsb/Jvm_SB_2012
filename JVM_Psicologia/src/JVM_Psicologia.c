/*
 * Arquivo inicial da JVM.
 *
 * Come�a a ler o arquivo .class
 *
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){

	if(argc == 2 && strstr(argv[1],".class") != NULL){

	}
	else{
		printf("ERRO! Poss�veis causas:\n");
		printf("\t1. Mais de um argumento de linha de comando foi passado\n");
		printf("\t2. Nao foi passado um argumento de linha de comando\n");
		printf("\t3. O arquivo nao possui a extensao .class\n");
	}

	return 0;
}