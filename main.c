#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* Dados dos alunos: a posicao 0 de cada vetor e do primeiro aluno, a 1 do segundo, etc.
   Valor -1 significa que o teste ainda nao foi feito. */
char nomes[30][13];
int saltos_cm[30];
float corrida20[30];
int corrida6[30];
float quadrado[30];
int total_alunos = 0;
int atual;

/* Turma escolhida (exemplo: 3a, 5b) e a faixa dela nos parametros do PROESP-Br:
   faixa 1 = 1o ao 6o ano, faixa 2 = 7o ao 9o ano. */
char turma[4];
int faixa;

/* Compara dois nomes letra por letra. Devolve 1 se sao iguais e 0 se nao. */
int nome_igual(char a[], char b[]){
	int p = 0;
	while (a[p] == b[p]) {
		if (a[p] == 0) {
			return 1;
		}
		p++;
	}
	return 0;
}

/* Procura o nome entre os alunos cadastrados. Devolve a posicao do aluno ou -1 se nao achar. */
int buscar_aluno(char nome[]){
	int i;
	for (i = 0; i < total_alunos; i++) {
		if (nome_igual(nomes[i], nome) == 1) {
			return i;
		}
	}
	return -1;
}

/* Para testes em que quanto MAIOR o valor, melhor (salto e corrida de 6 minutos). */
void media_maior(float valor, float minimo, float maximo){
	if (valor < minimo) {
		printf("ABAIXO DA MEDIA");
	}
	else {
		if (valor > maximo) {
			printf("ACIMA DA MEDIA");
		}
		else {
			printf("NA MEDIA");
		}
	}
}

/* Para testes em que quanto MENOR o valor, melhor (tempo da corrida de 20m e do quadrado). */
void media_menor(float valor, float minimo, float maximo){
	if (valor > maximo) {
		printf("ABAIXO DA MEDIA");
	}
	else {
		if (valor < minimo) {
			printf("ACIMA DA MEDIA");
		}
		else {
			printf("NA MEDIA");
		}
	}
}

/* Cada funcao abaixo escolhe os parametros conforme a faixa da turma. */
void media_salto(int cm){
	if (faixa == 1) {
		media_maior(cm, 113, 124);
	}
	else {
		media_maior(cm, 142, 155);
	}
}

void media_corrida20(float sec){
	if (faixa == 1) {
		media_menor(sec, 4.37, 4.67);
	}
	else {
		media_menor(sec, 3.85, 4.10);
	}
}

void media_corrida6(int m){
	if (faixa == 1) {
		media_maior(m, 747, 840);
	}
	else {
		media_maior(m, 823, 924);
	}
}

void media_quadrado(float sec){
	if (faixa == 1) {
		media_menor(sec, 7.33, 7.80);
	}
	else {
		media_menor(sec, 6.47, 6.89);
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

		atual = buscar_aluno(nomes[total_alunos]);
		if (atual == -1) {
			atual = total_alunos;
			saltos_cm[atual] = -1;
			corrida20[atual] = -1;
			corrida6[atual] = -1;
			quadrado[atual] = -1;
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

	i = buscar_aluno(nome);
	if (i == -1) {
		printf("\nAluno nao encontrado.\n");
	}
	else {
		printf("\nALUNO: %s   TURMA: %s", nomes[i], turma);

		if (saltos_cm[i] == -1) {
			printf("\nSalto horizontal: nao realizado");
		}
		else {
			printf("\nSalto horizontal: %d cm - ", saltos_cm[i]);
			media_salto(saltos_cm[i]);
		}

		if (corrida20[i] == -1) {
			printf("\nCorrida de 20m: nao realizado");
		}
		else {
			printf("\nCorrida de 20m: %f s - ", corrida20[i]);
			media_corrida20(corrida20[i]);
		}

		if (corrida6[i] == -1) {
			printf("\nCorrida de 6 minutos: nao realizado");
		}
		else {
			printf("\nCorrida de 6 minutos: %d m - ", corrida6[i]);
			media_corrida6(corrida6[i]);
		}

		if (quadrado[i] == -1) {
			printf("\nTeste do quadrado: nao realizado");
		}
		else {
			printf("\nTeste do quadrado: %f s - ", quadrado[i]);
			media_quadrado(quadrado[i]);
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
	printf("\nResultado: ");
	media_salto(cm);
}
void resistencia(){
	float sec;
	printf("\nRESISTENCIA: CORRIDA DE 20m \n O aluno corre 20 metros no máximo de velocidade, saindo parado. Será registrado o tempo usado em segundos(contando 2 casas apos a virgula).");
	printf("\nInsira a velociade para percorrer os 20m");
	scanf("%f",&sec);
	printf("%f",&sec);
	corrida20[atual] = sec;
	printf("\nResultado: ");
	media_corrida20(sec);
}
void velocidade(){
	int m;
	printf("\nRESISTENCIA: CORRIDA 6 MINUTOS \n O aluno percorre a maior distancia possivel em 6 minutos dando voltas em um percurso ja calculado a distancia conforme a quantidade de voltas e aonde parou no percurso, podendo caminhar se cansar \n Insira a distancia em metros");
	printf("\nInsira a distancia percorrida(em metros): ");
	scanf("%d", &m);
	printf("%d",&m);
	corrida6[atual] = m;
	printf("\nResultado: ");
	media_corrida6(m);
}
void cordenacao(){
	float tempo1,tempo2,melhor;
	printf("\nCOORDENACAO: TESTE DO QUADRADO 4x4m \n O aluno percorre correndo um quadrado de 4 metros de lado marcado com 4 cones, tocando em cada cone, o mais rapido possivel. \n Sera registrado o tempo em segundos(contando 2 casas apos a virgula), cada aluno tera 2 tentativas e vale o menor tempo.");
	printf("\nInsira o tempo em segundos (1 tentativa): ");
	scanf("%f",&tempo1);
	printf("\nInsira o tempo em segundos (2 tentativa): ");
	scanf("%f",&tempo2);
	if (tempo1 < tempo2) {
		melhor = tempo1;
	}
	else {
		melhor = tempo2;
	}
	quadrado[atual] = melhor;
	printf("\nMelhor tempo: %f s", melhor);
	printf("\nResultado: ");
	media_quadrado(melhor);
}


void menu (){

	int testes;

	do {
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
					if (atual != -1) {
						forca();
					}
				break;
			}
			case 2:{
					selecionar_aluno();
					if (atual != -1) {
						resistencia();
					}
				break;
			}
			case 3:{
					selecionar_aluno();
					if (atual != -1) {
						velocidade();
					}
				break;
			}
			case 4:{
					selecionar_aluno();
					if (atual != -1) {
						cordenacao();
					}
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

	char pro[20];
	int senha;

	printf("PROFESSOR: ");
	scanf("%19s", &pro);

	printf("SENHA: ");
	scanf("%d", &senha);

	if (senha == 12211) {
	    printf("ACESSO AUTORIZADO, BEM VINDO PROFESSOR %s", pro);

	    /* O primeiro caractere da turma e o ano: 1 a 6 usa uma faixa, 7 a 9 usa a outra. */
	    faixa = 0;
	    while (faixa == 0) {
	        printf("\nSelecione a turma para a analise (exemplo: 3a, 5b): ");
	        turma[0] = 0;
	        if (scanf("%3s", &turma) != 1) {
	            return 0;
	        }
	        if (turma[0] >= '1' && turma[0] <= '6') {
	            faixa = 1;
	        }
	        else {
	            if (turma[0] >= '7' && turma[0] <= '9') {
	                faixa = 2;
	            }
	            else {
	                printf("Turma invalida, comece pelo ano de 1 a 9.");
	            }
	        }
	    }
	    if (faixa == 1) {
	        printf("Turma %s: parametros do 1 ao 6 ano.", turma);
	    }
	    else {
	        printf("Turma %s: parametros do 7 ao 9 ano.", turma);
	    }
	    menu();
	}
	else {
	    printf("ACESSO NEGADO, CREDENCIAIS NAO AUTORIZADAS");
	}
	return 0;
}
