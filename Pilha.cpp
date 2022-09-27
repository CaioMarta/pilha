#include <stdio.h>
#define tam 10

// Estrutura heterogênea - Criando novo tipo de dado chamado "Pilha"
struct Pilha
{
	   char elementos [tam];
	   int topo;
};

// Protótipos das funções
void iniciaPilha(struct Pilha *P);
void push(struct Pilha *P, char c);
void pop(struct Pilha *P);
void mostrar(struct Pilha P);
char getTopo(struct Pilha P);

// Programa principal
int main()
{
	struct Pilha P;
	int op;
	char c;
	
	// Menu em loop
	do
	{
		printf("Opcoes para usar o menu: ");
		printf("\n 1 - Iniciar nova pilha ");
		printf("\n 2 - Adicionar novo elemento ");
		printf("\n 3 - Retirar um elemento ");
		printf("\n 4 - Mostrar pilha ");
		printf("\n 5 - Consultar elemento no topo ");
		printf("\n 6 - Sair do menu ");
		printf("\n Digite sua escolha: ");
		scanf("%d", &op);
		
		switch(op)
		{
		case 1:
			iniciaPilha(&P);
			break;
		case 2:
			// Empilhar : PUSH
			printf("\n Digite um caracter a ser inserido na pilha: ");
			scanf(" %c", &c);
			push(&P, c);
			break;
		case 3:
			// Desempilhar : POP
			pop(&P);
			break;
		case 4:
			// Mostrar Pilha
			mostrar(P);
			break;
		case 5:
			// Mostrar elemento no topo
			c = getTopo(P);
			printf("Elemento no topo: %c", c);
			break;
		default:
			break;
		}
	}while(op!=6); // Encerra o loop
	
	return 0;
}

// Métodos 
void iniciaPilha(struct Pilha *P)
{
	P->topo = -1;
}

void push(struct Pilha *P, char c)
{
	if(P->topo == tam -1)
	{
		printf("\n Pilha cheia - Impossivel adicionar mais elementos");
	}
	else
	{
		P->topo++;
		P->elementos[P->topo] = c;
	}
} 

void pop(struct Pilha *P)
{
	if(P->topo == -1)
	{
		printf("Pilha vazia");
	}
	else
	{
		P->topo--;
	}
} 

void mostrar(struct Pilha P)
{
	int i;
	for(i=0; i <= P.topo; i++)
	{
		printf(" %c", P.elementos[i]);
	}
}

char getTopo(struct Pilha P)
{
	char c;
	c = P.elementos[P.topo];
	return c;
}
