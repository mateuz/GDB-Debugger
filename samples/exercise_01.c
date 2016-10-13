#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char Nomes[10][50] = {
	{"Paulo"},
	{"Guilherme"},
	{"Vitor"},
	{"Pablo"},
	{"Priscila"},
	{"Carlos"},
	{"Joana"},
	{"Ciro"},
	{"Giovanni"},
	{"Antonio"}
};

typedef struct{
	int idade;
	char *nome;
} Pessoas;

void whoIsMyFriend(Pessoas *amigos, int n){
	int i;
	for ( i = 0; i <= n; i++ ){
		printf(" %s : %d\n", (amigos + i)->nome, (amigos + i)->idade);
	}
}

int main(){
	int n, i;
	printf("Digite quantos valores você quer preencher: ");
	scanf("%d", &n);
	Pessoas *amigos = (Pessoas *) malloc ( sizeof(Pessoas) * n );
	n = 10;
	for ( i = 0; i < n; i++ ){
		(amigos + i)->idade = (i+n);
		(amigos + i)->nome = (char *) malloc (sizeof(char) * 80);
		if( i == n ) n += 2;
		strcpy((amigos + i)->nome, Nomes[i%10]);
	}
	n = 20;
	whoIsMyFriend(amigos, n);
	return 1;
}
