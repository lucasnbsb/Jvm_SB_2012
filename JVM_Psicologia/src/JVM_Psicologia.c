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
#include "Frame.h"
#include "FuncoesGerais.h"
#include "Instrucoes.h"

int main(int argc, char* argv[]){

	if(argc == 2 && strstr(argv[1],".class") != NULL){

		char nomeClasse[30];
		ClassFile cf;
		//methodInfo* m;
		tipoOperando op;
		execucao *p;

		p = malloc (sizeof(execucao));

		strcpy(nomeClasse, argv[1]);

		cf = carregaClassFile(nomeClasse);

		/*
		 * TESTE DE INSTRUÇÃO ARITMÉTICA
		 *
		inicializaPilhaFrames(&(p->frameAtual));
		pushFrame(&(p->frameAtual));
		inicializaFrame(cf, p->frameAtual, "getNome", "()[C");
		iconst_m1(p);
		op = popOperando(&(p->frameAtual->topoPilhaOperandos));
		printf ("\n\n%d\n\n", op.tipoInt);
		*/

		// printConstantPool(cf);

		//Teste de busca de método por nome. Arquivo usado: Teste.class
		//m = buscaMetodoNome(cf, "getNome", "()[C");
		//
		//printf("\n\n\n%s\n", (char*) buscaUTF8ConstPool(cf,m->nameIndex));
	}
	else{
		printf("ERRO! Possíveis causas:\n");
		printf("\t1. Mais de um argumento de linha de comando foi passado\n");
		printf("\t2. Nao foi passado um argumento de linha de comando\n");
		printf("\t3. O arquivo nao possui a extensao .class\n");
	}

	return 0;
}
