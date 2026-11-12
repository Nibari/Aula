#include <stdio.h>
#include <stdlib.h>

int codigos[50];
char escolas[50][41];
char temas[50][41];
char datas[50][11];
char publicos[50][41];
char responsaveis[50][41];
int previstos[50];
int efetivos[50];
int situacoes[50];
int total_acoes = 0;

void ler_texto(char destino[], int tamanho){
	int c;
	int n = 0;

	c = getchar();
	while (c == ' ' || c == '\t') {
		c = getchar();
	}

	while (c != '\n' && c != EOF) {
		if (c != '\r' && n < tamanho - 1) {
			destino[n] = c;
			n++;
		}
		c = getchar();
	}

	if (c == EOF && n == 0) {
		printf("\nEntrada encerrada.\n");
		exit(0);
	}

	while (n > 0 && destino[n - 1] == ' ') {
		n--;
	}
	destino[n] = 0;
}

void ler_obrigatorio(char mensagem[], char destino[], int tamanho){
	destino[0] = 0;
	while (destino[0] == 0) {
		printf("%s", mensagem);
		ler_texto(destino, tamanho);
		if (destino[0] == 0) {
			printf("ERRO: este campo e obrigatorio.\n");
		}
	}
}

int ler_inteiro(char mensagem[]){
	char texto[20];
	int valido = 0;
	int valor, sinal, i;

	while (valido == 0) {
		printf("%s", mensagem);
		ler_texto(texto, 20);

		valor = 0;
		sinal = 1;
		i = 0;
		if (texto[0] == '-') {
			sinal = -1;
			i = 1;
		}

		valido = 1;
		if (texto[i] == 0) {
			valido = 0;
		}
		while (texto[i] != 0) {
			if (texto[i] >= '0' && texto[i] <= '9' && i < 9) {
				valor = valor * 10 + (texto[i] - '0');
			}
			else {
				valido = 0;
			}
			i++;
		}

		if (valido == 0) {
			printf("ERRO: digite um numero inteiro valido.\n");
		}
	}
	return valor * sinal;
}

int ler_quantidade(char mensagem[], int minimo){
	int valor = ler_inteiro(mensagem);

	while (valor < minimo) {
		if (valor < 0) {
			printf("ERRO: a quantidade nao pode ser negativa.\n");
		}
		else {
			printf("ERRO: o valor minimo e %d.\n", minimo);
		}
		valor = ler_inteiro(mensagem);
	}
	return valor;
}

char minuscula(char c){
	if (c >= 'A' && c <= 'Z') {
		return c + ('a' - 'A');
	}
	return c;
}

int contem(char texto[], char trecho[]){
	int inicio, i;

	for (inicio = 0; texto[inicio] != 0; inicio++) {
		i = 0;
		while (trecho[i] != 0 && minuscula(texto[inicio + i]) == minuscula(trecho[i])) {
			i++;
		}
		if (trecho[i] == 0) {
			return 1;
		}
	}
	return 0;
}

int data_valida(char d[]){
	int i, dia, mes, ano, limite;

	for (i = 0; i < 10; i++) {
		if (i == 2 || i == 5) {
			if (d[i] != '/') {
				return 0;
			}
		}
		else {
			if (d[i] < '0' || d[i] > '9') {
				return 0;
			}
		}
	}
	if (d[10] != 0) {
		return 0;
	}

	dia = (d[0] - '0') * 10 + (d[1] - '0');
	mes = (d[3] - '0') * 10 + (d[4] - '0');
	ano = (d[6] - '0') * 1000 + (d[7] - '0') * 100 + (d[8] - '0') * 10 + (d[9] - '0');

	if (mes < 1 || mes > 12) {
		return 0;
	}

	limite = 31;
	if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
		limite = 30;
	}
	if (mes == 2) {
		limite = 28;
		if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) {
			limite = 29;
		}
	}

	if (dia < 1 || dia > limite) {
		return 0;
	}
	return 1;
}

int buscar_codigo(int codigo){
	int i;

	for (i = 0; i < total_acoes; i++) {
		if (codigos[i] == codigo) {
			return i;
		}
	}
	return -1;
}

void mostrar_situacao(int situacao){
	if (situacao == 1) {
		printf("Planejada");
	}
	else {
		if (situacao == 2) {
			printf("Realizada");
		}
		else {
			printf("Cancelada");
		}
	}
}

void mostrar_acao(int i){
	printf("\n----------------------------------------");
	printf("\nCodigo: %d", codigos[i]);
	printf("\nEscola: %s", escolas[i]);
	printf("\nTema: %s", temas[i]);
	printf("\nData prevista: %s", datas[i]);
	printf("\nPublico-alvo: %s", publicos[i]);
	printf("\nResponsavel: %s", responsaveis[i]);
	printf("\nParticipantes previstos: %d", previstos[i]);
	printf("\nSituacao: ");
	mostrar_situacao(situacoes[i]);
	if (situacoes[i] == 2) {
		printf("\nParticipantes efetivos: %d", efetivos[i]);
	}
	printf("\n");
}

int ler_situacao(char mensagem[]){
	int situacao;

	printf("\n1 - Planejada");
	printf("\n2 - Realizada");
	printf("\n3 - Cancelada\n");
	situacao = ler_inteiro(mensagem);
	while (situacao < 1 || situacao > 3) {
		printf("ERRO: opcao inexistente. Escolha 1, 2 ou 3.\n");
		situacao = ler_inteiro(mensagem);
	}
	return situacao;
}

void cadastrar(){
	int i, codigo;

	printf("\nCADASTRO DE ACAO DO PSE\n");

	if (total_acoes == 50) {
		printf("ERRO: limite de 50 acoes atingido. Nao e possivel cadastrar mais.\n");
		return;
	}

	codigo = ler_quantidade("Codigo da acao (numero maior que zero): ", 1);
	while (buscar_codigo(codigo) != -1) {
		printf("ERRO: ja existe uma acao com o codigo %d.\n", codigo);
		codigo = ler_quantidade("Codigo da acao (numero maior que zero): ", 1);
	}

	i = total_acoes;
	codigos[i] = codigo;

	ler_obrigatorio("Escola: ", escolas[i], 41);
	ler_obrigatorio("Tema: ", temas[i], 41);

	ler_obrigatorio("Data prevista (dd/mm/aaaa): ", datas[i], 11);
	while (data_valida(datas[i]) == 0) {
		printf("ERRO: data invalida. Use o formato dd/mm/aaaa, por exemplo 15/03/2026.\n");
		ler_obrigatorio("Data prevista (dd/mm/aaaa): ", datas[i], 11);
	}

	ler_obrigatorio("Publico-alvo (exemplo: 5o ano): ", publicos[i], 41);
	ler_obrigatorio("Responsavel pela acao: ", responsaveis[i], 41);
	previstos[i] = ler_quantidade("Quantidade prevista de participantes: ", 1);

	printf("\nSituacao inicial:");
	situacoes[i] = ler_situacao("Situacao: ");

	efetivos[i] = 0;
	if (situacoes[i] == 2) {
		efetivos[i] = ler_quantidade("Quantidade efetiva de participantes: ", 0);
	}

	total_acoes = total_acoes + 1;
	printf("\nAcao %d cadastrada com sucesso.\n", codigo);
}

void listar(){
	int i;

	printf("\nLISTA DE ACOES CADASTRADAS\n");

	if (total_acoes == 0) {
		printf("Nenhuma acao cadastrada.\n");
		return;
	}

	printf("Total de acoes: %d\n", total_acoes);
	for (i = 0; i < total_acoes; i++) {
		mostrar_acao(i);
	}
}

void pesquisar(){
	int opcao, codigo, i, encontradas;
	char trecho[41];

	printf("\nPESQUISA DE ACOES\n");

	if (total_acoes == 0) {
		printf("Nenhuma acao cadastrada.\n");
		return;
	}

	printf("1 - Por codigo");
	printf("\n2 - Por escola");
	printf("\n3 - Por tema");
	printf("\n0 - Voltar\n");
	opcao = ler_inteiro("Opcao: ");
	while (opcao < 0 || opcao > 3) {
		printf("ERRO: opcao inexistente. Escolha de 0 a 3.\n");
		opcao = ler_inteiro("Opcao: ");
	}

	if (opcao == 0) {
		return;
	}

	if (opcao == 1) {
		codigo = ler_inteiro("Codigo procurado: ");
		i = buscar_codigo(codigo);
		if (i == -1) {
			printf("\nNenhuma acao encontrada com o codigo %d.\n", codigo);
		}
		else {
			mostrar_acao(i);
		}
		return;
	}

	if (opcao == 2) {
		ler_obrigatorio("Escola (ou parte do nome): ", trecho, 41);
	}
	else {
		ler_obrigatorio("Tema (ou parte do tema): ", trecho, 41);
	}

	encontradas = 0;
	for (i = 0; i < total_acoes; i++) {
		if ((opcao == 2 && contem(escolas[i], trecho) == 1) || (opcao == 3 && contem(temas[i], trecho) == 1)) {
			mostrar_acao(i);
			encontradas++;
		}
	}

	if (encontradas == 0) {
		printf("\nNenhuma acao encontrada para \"%s\".\n", trecho);
	}
	else {
		printf("\nAcoes encontradas: %d\n", encontradas);
	}
}

void atualizar_situacao(){
	int codigo, i;

	printf("\nATUALIZAR SITUACAO DE UMA ACAO\n");

	if (total_acoes == 0) {
		printf("Nenhuma acao cadastrada.\n");
		return;
	}

	codigo = ler_inteiro("Codigo da acao: ");
	i = buscar_codigo(codigo);
	if (i == -1) {
		printf("ERRO: nao existe acao com o codigo %d.\n", codigo);
		return;
	}

	printf("\nDados atuais:");
	mostrar_acao(i);

	printf("\nNova situacao:");
	situacoes[i] = ler_situacao("Situacao: ");

	efetivos[i] = 0;
	if (situacoes[i] == 2) {
		efetivos[i] = ler_quantidade("Quantidade efetiva de participantes: ", 0);
	}

	printf("\nSituacao da acao %d atualizada para ", codigo);
	mostrar_situacao(situacoes[i]);
	printf(".\n");
}

void resumo(){
	int i;
	int planejadas = 0, realizadas = 0, canceladas = 0;
	int previsto_total = 0, previsto_realizadas = 0, efetivo_total = 0;
	float percentual;

	printf("\nRESUMO GERAL DAS ACOES DO PSE\n");

	if (total_acoes == 0) {
		printf("Nenhuma acao cadastrada.\n");
		return;
	}

	for (i = 0; i < total_acoes; i++) {
		previsto_total = previsto_total + previstos[i];
		if (situacoes[i] == 1) {
			planejadas++;
		}
		if (situacoes[i] == 2) {
			realizadas++;
			previsto_realizadas = previsto_realizadas + previstos[i];
			efetivo_total = efetivo_total + efetivos[i];
		}
		if (situacoes[i] == 3) {
			canceladas++;
		}
	}

	printf("Acoes cadastradas: %d", total_acoes);
	printf("\nAcoes planejadas: %d", planejadas);
	printf("\nAcoes realizadas: %d", realizadas);
	printf("\nAcoes canceladas: %d", canceladas);
	printf("\n\nParticipantes previstos em todas as acoes: %d", previsto_total);
	printf("\nParticipantes previstos nas acoes realizadas: %d", previsto_realizadas);
	printf("\nTotal de participantes efetivos: %d", efetivo_total);

	if (previsto_realizadas == 0) {
		printf("\nPercentual de participacao: sem acoes realizadas para calcular.\n");
	}
	else {
		percentual = efetivo_total * 100.0 / previsto_realizadas;
		printf("\nPercentual de participacao (efetivos / previstos das acoes realizadas): %.1f%%\n", percentual);
	}
}

void menu(){
	int opcao;

	do {
		printf("\n========================================");
		printf("\nGESTAO DE ACOES DO PROGRAMA SAUDE NA ESCOLA");
		printf("\n========================================");
		printf("\n1 - Cadastrar acao");
		printf("\n2 - Listar acoes");
		printf("\n3 - Pesquisar acao");
		printf("\n4 - Atualizar situacao");
		printf("\n5 - Resumo geral");
		printf("\n0 - Sair\n");
		opcao = ler_inteiro("Opcao: ");

		switch(opcao){
			case 1:{
				cadastrar();
				break;
			}
			case 2:{
				listar();
				break;
			}
			case 3:{
				pesquisar();
				break;
			}
			case 4:{
				atualizar_situacao();
				break;
			}
			case 5:{
				resumo();
				break;
			}
			case 0:{
				printf("\nSistema encerrado.\n");
				break;
			}
			default:{
				printf("ERRO: opcao inexistente. Escolha de 0 a 5.\n");
				break;
			}
		}
	} while (opcao != 0);
}

int main(int argc, char *argv[]) {
	menu();
	return 0;
}
