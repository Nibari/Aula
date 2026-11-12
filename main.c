#include <stdio.h>
#include <stdlib.h>

char nomes[30][13];
int saltos_cm[30];
float corrida20[30];
int corrida6[30];
int saltos_laterais[30];
int total_alunos = 0;
int atual;

char turma[4];
int faixa;

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

int buscar_aluno(char nome[]){
	int i;
	for (i = 0; i < total_alunos; i++) {
		if (nome_igual(nomes[i], nome) == 1) {
			return i;
		}
	}
	return -1;
}

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

void media_saltos(int total){
	if (faixa == 1) {
		media_maior(total, 49, 64);
	}
	else {
		media_maior(total, 70, 86);
	}
}

void forca(){
	int cm;

	printf("\nFORCA: SALTO HORIZONTAL");
	printf("\n O aluno executa um salto horizontal para frente com os pes juntos, partindo parado atras de uma linha.");
	printf("\n Sera medida a distancia da linha ate o calcanhar mais proximo (em centimetros).");
	printf("\n\nInsira a distancia do salto (em centimetros), arredondando para baixo: ");
	scanf("%d", &cm);

	saltos_cm[atual] = cm;
	printf("\nResultado: %d cm - ", cm);
	media_salto(cm);
}

void velocidade(){
	float sec;

	printf("\nVELOCIDADE: CORRIDA DE 20m");
	printf("\n O aluno corre 20 metros no maximo de velocidade, saindo parado.");
	printf("\n Sera registrado o tempo usado em segundos (contando 2 casas apos a virgula).");
	printf("\n\nInsira o tempo para percorrer os 20m (em segundos): ");
	scanf("%f", &sec);

	corrida20[atual] = sec;
	printf("\nResultado: %f s - ", sec);
	media_corrida20(sec);
}

void resistencia(){
	int m;

	printf("\nRESISTENCIA: CORRIDA DE 6 MINUTOS");
	printf("\n O aluno percorre a maior distancia possivel em 6 minutos, dando voltas em um percurso de distancia ja calculada, podendo caminhar se cansar.");
	printf("\n A distancia e calculada conforme a quantidade de voltas e onde o aluno parou no percurso.");
	printf("\n\nInsira a distancia percorrida (em metros): ");
	scanf("%d", &m);

	corrida6[atual] = m;
	printf("\nResultado: %d m - ", m);
	media_corrida6(m);
}

void coordenacao(){
	int salto1, salto2, total;

	printf("\nCOORDENACAO: SALTOS LATERAIS");
	printf("\n O aluno salta de um lado para o outro de uma linha ou ripa no chao, com os pes juntos, durante 15 segundos.");
	printf("\n Sera contado o numero de saltos. Cada aluno tera 2 tentativas e o resultado e a soma das duas.");
	printf("\n\nInsira a quantidade de saltos (1 tentativa): ");
	scanf("%d", &salto1);
	printf("Insira a quantidade de saltos (2 tentativa): ");
	scanf("%d", &salto2);

	total = salto1 + salto2;

	saltos_laterais[atual] = total;
	printf("\nResultado: %d saltos (soma das 2 tentativas) - ", total);
	media_saltos(total);
}

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
			saltos_laterais[atual] = -1;
			total_alunos = total_alunos + 1;
		}
	}
}

void mostrar_aluno(int i){
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

	if (saltos_laterais[i] == -1) {
		printf("\nSaltos laterais: nao realizado");
	}
	else {
		printf("\nSaltos laterais: %d saltos - ", saltos_laterais[i]);
		media_saltos(saltos_laterais[i]);
	}
	printf("\n");
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
		mostrar_aluno(i);
	}
}

void resumo(){
	int i;

	printf("\nRESUMO GERAL DA TURMA %s", turma);
	if (total_alunos == 0) {
		printf("\nNenhum aluno cadastrado.\n");
	}
	else {
		printf("\nTotal de alunos cadastrados: %d\n", total_alunos);
		for (i = 0; i < total_alunos; i++) {
			mostrar_aluno(i);
		}
	}
}

void atualizar(){
	char nome[13];
	int i, opcao;

	printf("\nATUALIZAR DADOS DE ALUNO");
	printf("\nInforme o nome do aluno: ");
	scanf("%12s", &nome);

	i = buscar_aluno(nome);
	if (i == -1) {
		printf("\nAluno nao encontrado.\n");
	}
	else {
		printf("\nDADOS ATUAIS:");
		mostrar_aluno(i);

		printf("\nQual dado quer atualizar?");
		printf("\n1 - forca");
		printf("\n2 - velocidade");
		printf("\n3 - resistencia");
		printf("\n4 - coordenacao");
		printf("\n0 - cancelar\n");
		opcao = 0;
		scanf("%d", &opcao);

		atual = i;
		switch(opcao){
			case 1:{
				forca();
				break;
			}
			case 2:{
				velocidade();
				break;
			}
			case 3:{
				resistencia();
				break;
			}
			case 4:{
				coordenacao();
				break;
			}
		}

		if (opcao >= 1 && opcao <= 4) {
			printf("\nDados atualizados.\n");
		}
		else {
			printf("\nNada foi alterado.\n");
		}
	}
}

void menu(){
	int testes;

	do {
		printf("\nTESTES DISPONIVEIS     OU      CONSULTA DE DADOS.");
		printf("\n1 - forca");
		printf("\n2 - velocidade");
		printf("\n3 - resistencia");
		printf("\n4 - coordenacao");
		printf("\n5 - consulta");
		printf("\n6 - resumo geral");
		printf("\n7 - atualizar dados de um aluno");
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
					velocidade();
				}
				break;
			}
			case 3:{
				selecionar_aluno();
				if (atual != -1) {
					resistencia();
				}
				break;
			}
			case 4:{
				selecionar_aluno();
				if (atual != -1) {
					coordenacao();
				}
				break;
			}
			case 5:{
				consulta();
				break;
			}
			case 6:{
				resumo();
				break;
			}
			case 7:{
				atualizar();
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
