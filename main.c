#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* Dados dos alunos: a posicao 0 de cada vetor e do primeiro aluno, a 1 do segundo, etc.
   Valor -1 significa que o teste ainda nao foi feito. */
char nomes[30][13];
int saltos_cm[30];
float corrida20[30];
int corrida6[30];
float saltos_media[30];
int total_alunos = 0;
int atual;

/* Compara dois nomes letra por letra, comecando na posicao p. Devolve 1 se sao iguais e 0 se nao. */
int nome_igual(char a[], char b[], int p){
	if (a[p] == b[p]) {
		if (a[p] == 0) {
			return 1;
		}
		else {
			return nome_igual(a, b, p + 1);
		}
	}
	else {
		return 0;
	}
}

/* Procura o nome a partir do aluno i. Devolve a posicao do aluno ou -1 se nao achar. */
int buscar_aluno(char nome[], int i){
	if (i == total_alunos) {
		return -1;
	}
	else {
		if (nome_igual(nomes[i], nome, 0) == 1) {
			return i;
		}
		else {
			return buscar_aluno(nome, i + 1);
		}
	}
}

/* Pede o nome do aluno e guarda a posicao dele em "atual". Se for um nome novo, cadastra. */
void selecionar_aluno(){
	if (total_alunos == 30) {
		printf("\nLimite de alunos atingido.");
		atual = -1;
	}
	else {
		printf("Informe o nome do aluno: ");
		scanf("%12s", &nomes[total_alunos]);

		atual = buscar_aluno(nomes[total_alunos], 0);
		if (atual == -1) {
			atual = total_alunos;
			saltos_cm[atual] = -1;
			corrida20[atual] = -1;
			corrida6[atual] = -1;
			saltos_media[atual] = -1;
			total_alunos = total_alunos + 1;
		}
	}
}

void consulta(){
	char nome[13];
	int i;

	printf("\nPESQUISA DE ALUNO");
	printf("\nInforme o nome do aluno: ");
	scanf("%12s", &nome);

	i = buscar_aluno(nome, 0);
	if (i == -1) {
		printf("\nAluno nao encontrado.\n");
	}
	else {
		printf("\nALUNO: %s", nomes[i]);

		if (saltos_cm[i] == -1) {
			printf("\nSalto horizontal: nao realizado");
		}
		else {
			printf("\nSalto horizontal: %d cm", saltos_cm[i]);
		}

		if (corrida20[i] == -1) {
			printf("\nCorrida de 20m: nao realizado");
		}
		else {
			printf("\nCorrida de 20m: %f s", corrida20[i]);
		}

		if (corrida6[i] == -1) {
			printf("\nCorrida de 6 minutos: nao realizado");
		}
		else {
			printf("\nCorrida de 6 minutos: %d m", corrida6[i]);
		}

		if (saltos_media[i] == -1) {
			printf("\nSaltos laterais: nao realizado");
		}
		else {
			printf("\nSaltos laterais (media): %f", saltos_media[i]);
		}
		printf("\n");
	}
}

void forca(){
	int cm;
	printf("\nFORÇA: SALTO HORIZONTAL \n O aluno executa um salto horizontal para frente com os pes juntos, partindo parado atras de uma linha. \n Sera medido a distancia da linha ate o calcanhar mais proximo (em centimetros).");
	printf("\n\nColoque a distancia em do salto(cm) arredondando para baixo: ");
	scanf("%d",&cm);
	printf("\n%d",&cm);
	saltos_cm[atual] = cm;
}
void resistencia(){
	float sec;
	printf("\nRESISTENCIA: CORRIDA DE 20m \n O aluno corre 20 metros no máximo de velocidade, saindo parado. Será registrado o tempo usado em segundos(contando 2 casas apos a virgula).");
	printf("\nInsira a velociade para percorrer os 20m");
	scanf("%f",&sec);
	printf("%f",&sec);
	corrida20[atual] = sec;
}
void velocidade(){
	int m;
	printf("\nRESISTENCIA: CORRIDA 6 MINUTOS \n O aluno percorre a maior distancia possivel em 6 minutos dando voltas em um percurso ja calculado a distancia conforme a quantidade de voltas e aonde parou no percurso, podendo caminhar se cansar \n Insira a distancia em metros");
	printf("\nInsira a distancia percorrida(em metros): ");
	scanf("%d", &m);
	printf("%d",&m);
	corrida6[atual] = m;
}
void cordenacao(){
	int salto1,salto2;
	float salto_media;
	printf("\nSALTOS LATERAIS \n O aluno salta de um lado para o outro de uma linha ou ripa do chao, saltando com os pes juntos durantes 15 segundos. \n Sera contado o numero de falas, cada aluno tera 2 tentativas e sera inserido a quantidade de saltos das 2 tentativas");
	printf("\nInsira a quantidade de saltos (1 tentativa): ");
	scanf("%d",&salto1);
	printf("\nInsira a quantidade de saltos (2 tentativa): ");
	scanf("%d",&salto2);
	salto_media = (salto1 + salto2)/2;
	printf("%f",&salto_media);
	saltos_media[atual] = salto_media;
}


void menu (){

	int testes, a[2];
	char aluno[13];

	printf("\nTESTES DISPONIVEIS     OU      COLSUTA DE DADOS.");
	printf("\n1 - forca");
	printf("\n2 - resistencia");
	printf("\n3 - velocidade");
	printf("\n4 - cordenacao");
	printf("\n5 - consulta");
	printf("\n0 - sair");

	printf("\nQual teste quer analisar?\n");
	testes = 0;
	scanf("%d", &testes);

	switch(testes){
		case 1:{
				selecionar_aluno();
				if (atual == -1) {
				}
				else {
					forca();
				}
				menu();
			break;
		}
		case 2:{
				selecionar_aluno();
				if (atual == -1) {
				}
				else {
					resistencia();
				}
				menu();
			break;
		}
		case 3:{
				selecionar_aluno();
				if (atual == -1) {
				}
				else {
					velocidade();
				}
				menu();
			break;
		}
		case 4:{
				selecionar_aluno();
				if (atual == -1) {
				}
				else {
					cordenacao();
				}
				menu();
			break;
		}
		case 5:{
				consulta();
				menu();
			break;
		}
	}
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
