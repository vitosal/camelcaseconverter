%{
#include <stdio.h>

#include "ccc_lib.h"
	char saida[100];


void zeraposicao(int tam, char *vetor);
%}


%%
[A-Z][a-z]+([A-Z][a-z]+)+ {
	camelcase_to_underline(yytext, saida); 
	printf("%s", saida);
	zeraposicao(100, saida);
}

([a-z]+[_][a-z]+)+ {
	underline_to_camelcase(yytext, saida);
	printf("%s", saida);
	zeraposicao(100, saida);
}

([A-Z][a-z]+([A-Z][a-z]+)+([a-z]+[_][a-z]+)+)+ {
	printf("ERRO");
}

(([a-z]+[_][a-z]+)+[A-Z][a-z]+([A-Z][a-z]+)+)+ {
	printf("ERRO");
}


%%

int main() {
	yylex();

	return 0;
}

void zeraposicao(int tam, char *vetor){
	int i;
	i=0;

	while(i!=tam){
		vetor[i++] = '\0';
	}
	return 0;
}

