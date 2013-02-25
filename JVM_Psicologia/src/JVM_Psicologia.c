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

	if(argc == 2){

		char nomeClasse[30];
		ClassFile cf;
		//methodInfo* m;
		//tipoOperando op;
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

		printConstantPool(cf);

		//Teste de busca de método por nome. Arquivo usado: Teste.class
		//m = buscaMetodoNome(cf, "<clinit>", "()V");

		//printf("\n\n\n%s\n", (char*) buscaUTF8ConstPool(cf.constant_pool,m->nameIndex));
		//printf("%s\n", (char*) buscaUTF8ConstPool(cf.constant_pool,m->descriptorIndex));
	}
	else{
		printf("ERRO! Possíveis causas:\n");
		printf("\t1. Mais de um argumento de linha de comando foi passado\n");
		printf("\t2. Nao foi passado um argumento de linha de comando\n");
	}

	return 0;
}
