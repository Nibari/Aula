#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define MAX_ALUNOS 50
#define TAM_NOME 50

/* Ficha de cada aluno. Valor -1 significa "teste ainda nao feito". */
struct Aluno {
	char nome[TAM_NOME];
	int salto_cm;        /* forca: salto horizontal */
	float corrida20_s;   /* corrida de 20m */
	int corrida6_m;      /* corrida de 6 minutos */
	float saltos_media;  /* saltos laterais */
};

struct Aluno alunos[MAX_ALUNOS];
int total_alunos = 0;

void menu();

/* Procura o aluno pelo nome. Devolve a posicao dele no vetor ou -1 se nao achar. */
int buscar_aluno(char nome[]){
	int i;
	for (i = 0; i < total_alunos; i++) {
		if (strcmp(alunos[i].nome, nome) == 0) {
			return i;
		}
	}
	return -1;
}

/* Pergunta o nome do aluno. Se ele ainda nao existe, cadastra. Devolve a posicao dele. */
int selecionar_aluno(){
	char nome[TAM_NOME];
	int i;

	printf("Informe o nome do aluno: ");
	scanf(" %49[^\n]", nome);

	i = buscar_aluno(nome);
	if (i == -1) {
		if (total_alunos == MAX_ALUNOS) {
			printf("\nLimite de alunos atingido.");
			return -1;
		}
		i = total_alunos;
		strcpy(alunos[i].nome, nome);
		alunos[i].salto_cm = -1;
		alunos[i].corrida20_s = -1;
		alunos[i].corrida6_m = -1;
		alunos[i].saltos_media = -1;
		total_alunos++;
	}
	return i;
}

/* Consulta: pede um nome e mostra tudo que esta salvo para aquele aluno. */
void consulta(){
	char nome[TAM_NOME];
	int i;

	printf("\nPESQUISA DE ALUNO");
	printf("\nInforme o nome do aluno: ");
	scanf(" %49[^\n]", nome);

	i = buscar_aluno(nome);
	if (i == -1) {
		printf("\nAluno nao encontrado.\n");
		return;
	}

	printf("\nALUNO: %s", alunos[i].nome);

	if (alunos[i].salto_cm == -1)
		printf("\nSalto horizontal: nao realizado");
	else
		printf("\nSalto horizontal: %d cm", alunos[i].salto_cm);

	if (alunos[i].corrida20_s == -1)
		printf("\nCorrida de 20m: nao realizado");
	else
		printf("\nCorrida de 20m: %.2f s", alunos[i].corrida20_s);

	if (alunos[i].corrida6_m == -1)
		printf("\nCorrida de 6 minutos: nao realizado");
	else
		printf("\nCorrida de 6 minutos: %d m", alunos[i].corrida6_m);

	if (alunos[i].saltos_media == -1)
		printf("\nSaltos laterais: nao realizado");
	else
		printf("\nSaltos laterais (media): %.1f", alunos[i].saltos_media);

	printf("\n");
}

void forca(int i){
	int cm;
	printf("\nFORÇA: SALTO HORIZONTAL \n O aluno executa um salto horizontal para frente com os pes juntos, partindo parado atras de uma linha. \n Sera medido a distancia da linha ate o calcanhar mais proximo (em centimetros).");
	printf("\n\nColoque a distancia em do salto(cm) arredondando para baixo: ");
	scanf("%d",&cm);
	printf("\n%d",&cm);
	alunos[i].salto_cm = cm;
}
void resistencia(int i){
	float sec;
	printf("\nRESISTENCIA: CORRIDA DE 20m \n O aluno corre 20 metros no máximo de velocidade, saindo parado. Será registrado o tempo usado em segundos(contando 2 casas apos a virgula).");
	printf("\nInsira a velociade para percorrer os 20m");
	scanf("%f",&sec);
	printf("%f",&sec);
	alunos[i].corrida20_s = sec;
}
void velocidade(int i){
	int m;
	printf("\nRESISTENCIA: CORRIDA 6 MINUTOS \n O aluno percorre a maior distancia possivel em 6 minutos dando voltas em um percurso ja calculado a distancia conforme a quantidade de voltas e aonde parou no percurso, podendo caminhar se cansar \n Insira a distancia em metros");
	printf("\nInsira a distancia percorrida(em metros): ");
	scanf("%d", &m);
	printf("%d",&m);
	alunos[i].corrida6_m = m;
}
void cordenacao(int i){
	int salto1,salto2;
	float salto_media;
	printf("\nSALTOS LATERAIS \n O aluno salta de um lado para o outro de uma linha ou ripa do chao, saltando com os pes juntos durantes 15 segundos. \n Sera contado o numero de falas, cada aluno tera 2 tentativas e sera inserido a quantidade de saltos das 2 tentativas");
	printf("\nInsira a quantidade de saltos (1 tentativa): ");
	scanf("%d",&salto1);
	printf("\nInsira a quantidade de saltos (2 tentativa): ");
	scanf("%d",&salto2);
	salto_media = (salto1 + salto2)/2;
	printf("%f",&salto_media);
	alunos[i].saltos_media = salto_media;
}


void menu (){

	int testes, i;

	do {
		printf("\nTESTES DISPONIVEIS     OU      COLSUTA DE DADOS.");
		printf("\n1 - forca");
		printf("\n2 - resistencia");
		printf("\n3 - velocidade");
		printf("\n4 - cordenacao");
		printf("\n5 - consulta");
		printf("\n0 - sair");

		printf("\nQual teste quer analisar?\n");
		if (scanf("%d", &testes) != 1) {
			break;
		}

		switch(testes){
			case 1:{
					i = selecionar_aluno();
					if (i != -1) forca(i);
				break;
			}
			case 2:{
					i = selecionar_aluno();
					if (i != -1) resistencia(i);
				break;
			}
			case 3:{
					i = selecionar_aluno();
					if (i != -1) velocidade(i);
				break;
			}
			case 4:{
					i = selecionar_aluno();
					if (i != -1) cordenacao(i);
				break;
			}
			case 5:{
					consulta();
				break;
			}
		}
	} while (testes != 0);
}

int main(int argc, char *argv[]) {

	char pro[20], turma[4];
	int senha;

	printf("PROFESSOR: ");
	scanf("%19s", &pro);

	printf("SENHA: ");
	scanf("%d", &senha);

	if (senha == 12211) {
	    printf("ACESSO AUTORIZADO, BEM VINDO PROFESSOR %s", pro);
	    printf("\nSelecione a turma para a analise: ");
	    scanf("%3s", &turma);
	    menu();
	}
	else {
	    printf("ACESSO NEGADO, CREDENCIAIS NAO AUTORIZADAS");
	}
	return 0;
}
