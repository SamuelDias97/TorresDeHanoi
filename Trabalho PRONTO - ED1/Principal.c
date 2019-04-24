#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include "Pilha.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

quantDiscos(Pilha * p, int quant){
	Pilha * aux1 = criar();
	Pilha * aux2 = criar();
	int x = 1;
	while(tamanho(p) < quant){
		empilhar(p, x);
		x=x+1;
	}
	while(tamanho(p) > 0) {
		empilhar(aux1, desempilhar(p));
	}
	while(tamanho(aux1) > 0) {
		empilhar(aux2, desempilhar(aux1));
	}
	while(tamanho(aux2) > 0) {
		empilhar(p, desempilhar(aux2));
	}
	destruir(aux1);
	destruir(aux2);
	return quant;
}

moverDisco(Pilha * p, Pilha * pX){
	
	if (tamanho(pX)!=0){
		if(topo(pX) < topo(p) || tamanho(p)==0){
			empilhar(p, desempilhar(pX));
			printf("\nJogada realizada com sucesso!\n\n");
		}
		else{
			printf("\nJogada ilegal!\n\n");
		}
	}else{
		printf("\nComando invalido!\n\n");
	}
	system("pause\n");
}

verificaMov(Pilha * p1, Pilha * p2, Pilha * p3){
	
	printf("Jogadas atualmente válidas: ");
	if(tamanho(p1)!=0){
		if(topo(p1) < topo(p2) || tamanho(p2)==0){
			printf("1 ");
		}
		if(topo(p1) < topo(p3) || tamanho(p3)==0){
			printf("2 ");
		}
	}
	if(tamanho(p2)!=0){
		if(topo(p2) < topo(p1) || tamanho(p1)==0){
			printf("3 ");
		}
		if(topo(p2) < topo(p3) || tamanho(p3)==0){
			printf("4 ");
		}
	}
	if(tamanho(p3)!=0){
		if(topo(p3) < topo(p1) || tamanho(p1)==0){
			printf("5 ");
		}
		if(topo(p3) < topo(p2) || tamanho(p2)==0){
			printf("6");
		}
	}
	printf("\n\n");
}
	
int menu(Pilha * p1, Pilha * p2, Pilha * p3){
	int i;
		printf("\n|-------------------Menu-------------------|\n");
		printf("|1-Inicializar pinos (Quantidade de discos)|\n");
		printf("|2-Finalizar programa                      |\n");
		printf("|------------------------------------------|\n\n");
		printf("--> Selecione uma opcao: ");
		scanf("%i", &i);
		if((i < 1)||(i > 2)){
			system("cls");
			printf("|--------------VALOR INVALIDO--------------|\n\n");
			return menu(p1,p2,p3);
		}else if(i!=2){
			menu2(p1,p2,p3);
		}else if(i==2){
			exit(0);	
		}
}

menu2(Pilha * p1, Pilha * p2, Pilha * p3){
	int quant;
	printf("--> Insira a quantidade de discos: ");
	scanf("%i", &quant);
	if(quant <= 0){
		printf("|--------------VALOR INVALIDO--------------|\n\n");
		menu2(p1,p2,p3);
	}
	else if(quant > 0){
		system("cls");
	    quantDiscos(p1, quant);
		menu3(p1,p2,p3,quant);
	}
}

menu3(Pilha * p1, Pilha * p2, Pilha * p3, int quant){
	int i;
	Pilha * aux1 = criar();
	Pilha * aux2 = criar();
	Pilha * aux3 = criar();
	printf("\n|----------Menu----------|\n");
	printf("|1-Realizar jogada       |\n");
	printf("|2-Voltar                |\n");
	printf("|3-Finalizar programa    |\n");
	printf("|------------------------|\n\n");
	
	printf("--> Selecione uma opcao: ");
	scanf("%i", &i);

	if((i <1)||(i >3)){
			printf("|--------------VALOR INVALIDO--------------|\n\n");
			printf("--> Selecione uma opcao novamente : \n");
			return menu(p1,p2,p3);
		}
		if(i==1){
			jogo(p1,p2,p3,quant);
		}else if(i==2){
			system("cls");
			while(tamanho(p1) != 0){
				empilhar(aux1, desempilhar(p1));
			}
			while(tamanho(p2) != 0){
				empilhar(aux2, desempilhar(p2));
			}
			while(tamanho(p3) != 0){
				empilhar(aux3, desempilhar(p3));
			}
			/*printf("\nP1-");
			imprimir(p1);
			printf("P2-");
			imprimir(p2);
			printf("P3-");
			imprimir(p3);*/
			destruir(aux1);
			destruir(aux2);
			destruir(aux3);
			menu(p1,p2,p3);
		}else if(i==3){
			exit(0);	
		}
	}
	
int cont=0;
int jogo(Pilha *p1, Pilha * p2, Pilha *p3, int quant){
	int j;
	system("cls");
	printf("\n|------------Escolher Jogada------------|\n"); // QUANTIDADE DE POSSIBILIDADES = 2^n - 1
	printf("|1-Disco do Pino 1 para Pino 2(P1-P2)   |\n");
	printf("|2-Disco do Pino 1 para Pino 3(P1-P3)   |\n");
	printf("|3-Disco do Pino 2 para Pino 1(P2-P1)   |\n");
	printf("|4-Disco do Pino 2 para Pino 3(P2-P3)   |\n");
	printf("|5-Disco do Pino 3 para Pino 1(P3-P1)   |\n");
	printf("|6-Disco do Pino 3 para Pino 2(P3-P2)   |\n");
	printf("|7-Finalizar programa                   |\n");
	printf("|8-Voltar                               |\n");
	/*printf("|9-Desistir                             |\n");*/
	printf("|---------------------------------------|\n\n");

	verificaMov(p1,p2,p3);
	printf("Quantidade mínima de jogadas: %0.0f\n", pow(2, quant)-1);
	printf("Quantidade de jogadas realizadas: %i\n\n", cont);
	
	printf("P1-");
	imprimir(p1);
	printf("P2-");
	imprimir(p2);
	printf("P3-");
	imprimir(p3);
	
	printf("\n--> Selecione uma opcao: ");
	scanf("%i", &j);
	if(j == 7){
		exit(0);	
	}
	if(j == 8){
		system("cls");
		menu3(p1,p2,p3,quant);
	}
	/*if(j == 9){
		system("cls");
		hanoi(p1,p2,p3,quant);
	}*/
	if(j == 1){
		cont++;
		moverDisco(p2, p1);
	}
	if(j == 2){
		cont++;
		moverDisco(p3, p1);
	}
	if(j == 3){
		cont++;
		moverDisco(p1, p2);
	}
	if(j == 4){
		cont++;
		moverDisco(p3, p2);
	}
	if(j == 5){
		cont++;
		moverDisco(p1, p3);
	}
	if(j == 6){
		cont++;
		moverDisco(p2, p3);
	}
	
	if(tamanho(p1) == 0 && tamanho(p2) == 0){
		
		system("cls");
		printf("P1-");
		imprimir(p1);
		printf("P2-");
		imprimir(p2);
		printf("P3-");
		imprimir(p3);
	
		printf("\nJogo terminou!\n");
		printf("\nQuantidade mínima de jogadas: %0.0f\n", pow(2, quant)-1);
		printf("Quantidade de jogadas realizadas: %i\n\n", cont);
		jogarNovamente(p1,p2,p3, quant);
	}else{
		jogo(p1,p2,p3, quant);
	}
}

jogarNovamente(Pilha * p1, Pilha * p2, Pilha * p3, int quant){
	int k;
	Pilha * aux1 = criar();
	Pilha * aux2 = criar();
	Pilha * aux3 = criar();
	
	printf("|--------------------------------|\n");
	printf("|1-Jogar novamente?              |\n");
	printf("|2-Alterar quantidade de Discos  |\n");
	printf("|3-Finalizar programa            |\n");
	printf("|--------------------------------|\n");
	printf("--> Selecione uma opcao: ");
	scanf("%i", &k);
	
	if((k < 1)||(k > 3)){
		printf("|--------------VALOR INVALIDO--------------|\n\n");
		printf("--> Selecione uma opcao novamente : \n");
		return jogarNovamente(p1,p2,p3, quant);
	}
	else if(k == 1){
		cont=0;
		while(tamanho(p3) > 0){
			empilhar(aux1, desempilhar(p3));
		}
		while(tamanho(aux1) > 0){
			empilhar(p1, desempilhar(aux1));
		}
		destruir(aux1);
		jogo(p1,p2,p3,quant);
	}
	else if(k == 2){
		cont=0;
		while(tamanho(p1) != 0){
			empilhar(aux1, desempilhar(p1));
		}
		while(tamanho(p2) != 0){
			empilhar(aux2, desempilhar(p2));
		}
		while(tamanho(p3) != 0){
			empilhar(aux3, desempilhar(p3));
		}
		destruir(aux1);
		destruir(aux2);
		destruir(aux3);
		
		printf("--> Insira a quantidade de discos: ");
		scanf("%i", &quant);
		if(quant <= 0){
			printf("|--------------VALOR INVALIDO--------------|\n\n");
			system("cls");
			menu2(p1,p2,p3);
		}
		else if(quant > 0){
	   		quantDiscos(p1, quant);
	   		system("cls");
			menu3(p1,p2,p3, quant);
		}
	}else if(k == 3){
		exit(0);	
	}
}

/*hanoi(Pilha * p1, Pilha * p2, Pilha * p3, int quant){
	printf("%i", quant);
if((quant%2)==0){
	while(tamanho(p3) < quant){
		if(topo(p1) < topo(p2) || tamanho(p2)==0){
			empilhar(p2, desempilhar(p1));
			printf("1 ");
		}
		else if(topo(p2) < topo(p1) || tamanho(p1)==0){
			empilhar(p1, desempilhar(p2));
			printf("3 ");
		}
		else if(topo(p1) < topo(p3) || tamanho(p3)==0){
			empilhar(p3, desempilhar(p1));
			printf("2 ");
		}
		else if(topo(p3) < topo(p1) || tamanho(p1)==0){
			empilhar(p1, desempilhar(p3));
			printf("5 ");
		}
		else if(topo(p2) < topo(p3) || tamanho(p3)==0){
			empilhar(p3, desempilhar(p2));
			printf("4 ");
		}
		else if(topo(p3) < topo(p2) || tamanho(p2)==0){
			empilhar(p2, desempilhar(p3));
			printf("6 ");
		}
	}
}
else if((quant%2)!=0){
	while(tamanho(p3) < quant){
		if(topo(p1) < topo(p3) || tamanho(p3)==0){
			empilhar(p3, desempilhar(p1));
			printf("2 ");
		}
	if(topo(p3) < topo(p1) || tamanho(p1)==0){
			empilhar(p1, desempilhar(p3));
			printf("5 ");
		}
	if(topo(p1) < topo(p2) || tamanho(p2)==0){
			empilhar(p2, desempilhar(p1));
			printf("1 ");
		}
	if(topo(p2) < topo(p1) || tamanho(p1)==0){
			empilhar(p1, desempilhar(p2));
			printf("3 ");
		}
	if(topo(p2) < topo(p3) || tamanho(p3)==0){
			empilhar(p3, desempilhar(p2));
			printf("4 ");
		}
	if(topo(p3) < topo(p2) || tamanho(p2)==0){
			empilhar(p2, desempilhar(p3));
			printf("6 ");
		}
	}
}
	
}*/


int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	Pilha * p1 = criar();
	Pilha * p2 = criar();
	Pilha * p3 = criar();
	
	printf("                    Torres de Hanoi\n\n");
	printf("|-------------------------------------------------------|\n");
	printf("|O famoso jogo da Torre de Hanói é um 'quebra-cabeca'   |\n");
	printf("|que consiste em uma base contendo três pinos, na       |\n"); 
	printf("|qual no primeiro são dispostos alguns discos uns sobre |\n"); 
	printf("|os outros, em ordem crescente de diâmetro, de cima     |\n");
	printf("|para baixo.                                            |\n");
	printf("|-------------------------------------------------------|\n\n");
	printf("|-------------------------------------------------------|\n");
	printf("|Objetivo: mover todos os discos para o terceiro pino.  |\n");
	printf("|-------------------------------------------------------|\n\n");
	
	
	menu(p1, p2, p3);
	
	system("pause");
	return 0;
}
