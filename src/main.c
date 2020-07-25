/* Tarefa de decifrar uma cifra
 *
 * Nome: João Antônio Gória Silva
 * RA: 199567
 */

#include <stdio.h>

/* Tamanho do buffer ligeiramente aumentado de 50 para 100 */
#define TAM_BUFFER 100

char buffer_entrada[TAM_BUFFER];
char buffer_saida[TAM_BUFFER];

/* Senha usada para a criptografia, pode ser facilmente descoberta colocando uma string com vários 'A' na entrada do cifrador */
const char senha[] = "SENHASECRETA";


/* Função que decifra um caractere dada uma key*/
char decifrar(char caractere, char key){
	char caractere0, key0, out;
	/* Verifica se o caractere é uma letra do alfabeto, já que não-letras não são cifradas */
	if(caractere >= 'A' && caractere <= 'Z'){
	caractere0 = caractere - 'A';
	key0 = key - 'A';
	/* Decifra o caractere com a descrição algébrica do algoritmo de cifra descrita na página da Wikipedia */
	out = 'A' + (caractere0-key0+('Z'-'A'+1))%('Z'-'A'+1);
	return out;
	}
	/* Se não for uma letra, retorna o próprio caractere */
	else return caractere;
}

int main() {
  /* Leitura da entrada */
  fgets(buffer_entrada, TAM_BUFFER, stdin);
	char i, j=0;
	/* Percorre a entrada e a senha para decifrar caractere por caractere; armazena os caracteres decifrados no buffer_saida */
	for (i=0; (i<TAM_BUFFER) && (buffer_entrada[i]!='\0') && (buffer_entrada[i]!='\n'); i++) {
    buffer_saida[i] = decifrar(buffer_entrada[i], senha[j]);
    j++;
    if (senha[j]=='\0') j=0;
  }
	/* Coloca o caractere de terminação no buffer_saida */
  buffer_saida[i]='\0';		

  /* Escrever saida na tela */
  printf("%s\n", buffer_saida);

  return 0;
}
