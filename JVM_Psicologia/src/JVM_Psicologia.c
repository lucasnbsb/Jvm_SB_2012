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
		//tipoOperando op1, op2;
		execucao *p;

		p = malloc (sizeof(execucao));

		strcpy(nomeClasse, argv[1]);

		cf = carregaClassFile(nomeClasse);


		/*
		 * TESTE DE INSTRUÇÕES ARITMÉTICAS
		 *
		inicializaPilhaFrames(&(p->frameAtual));
		inicializaClassFileLista(&(p->pInicioLista));
		pushFrame(&(p->frameAtual));
		inicializaFrame(p->pInicioLista, cf, p->frameAtual, "main", "([Ljava/lang/String;)V");
		op1.tipoFloat = 3000.123;
		op2.tipoFloat = 7.5;
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op1, TIPO2);
		pushOperando(&(p->frameAtual->topoPilhaOperandos), op2, TIPO2);
		frem(p);
		printf("%s", p->frameAtual->topoPilhaOperandos->operandoTipo1 == TIPO1 ? "Tipo 1" : "Tipo 2");
		op1 = popOperando(&(p->frameAtual->topoPilhaOperandos));
		printf ("\n\n%g\n\n", op1.tipoFloat);
		*/

		//printConstantPool(cf);

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
