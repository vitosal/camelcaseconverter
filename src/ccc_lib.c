
/* Funcao que converte entradas came1case para saida underline*/
void camelcase_to_underline(char *input, char *output){
	int i, j, aux;
	i =0;
	j = i; 
	aux = 'a'-'A';
	
	/* Loop de leitura da string de entrada e armazenamento na string de saida*/	
	while( input[i] != '\0'){
		/*Indentifica uma letra maiuscula*/
		if(  (input[i] > 64) && (input[i] < 91) ){
			/* A primeira letra maiuscula vira minuscula*/
			if(i == 0){
				output[j] = input[i] + aux;
			}
			/*Caso que temos uma maiuscula no meio da frase logo antes devemos colocar underline por exemplo AbC vira ab_c*/
			else{
				output[j] = '_';
				output[++j] = input[i] + aux;
			}
		}
		/*Temos uma letra minuscula*/
		else{
			output[j] = input[i];

		}

		i++;
		j++;
	}


	return;
}

/* Funcao que converte entradas underline para saida came1case*/
void underline_to_camelcase(char *input, char *output){
	int i, j, aux;
	i =0;
	j =i;
	aux = 'a'-'A';
	/* Loop de leitura da string de entrada e armazenamento na string de saida*/	
	while(input[i] !='\0'){
		/*Indentifica a primeira letra*/
		if( i == 0){
			output[j] = input[i] - aux;
		}
		/* Indetifica os outros caracteres */
		else{
			/* Temos um underline exemplo a_bc se transforma em A Bc */
			if(input[i] == '_'){
				output[j] = input[++i] - aux;

			}
			/* Encontra minusculas */
			else{
				output[j] = input[i];

			}

		}
		i++;
		j++;

	}


	return;
}


