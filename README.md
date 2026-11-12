# Sistema de Testes Físicos Escolares

Programa em linguagem C, executado no terminal, para o professor registrar os resultados dos testes físicos de uma turma e ver a classificação de cada aluno: abaixo da média, na média ou acima da média.

As instruções para compilar e usar o programa estão em [INSTRUCOES_DE_EXECUCAO.md](INSTRUCOES_DE_EXECUCAO.md).

## Integrantes

> Preencher com os dados do grupo.

| Nome | RA |
|---|---|
| | |
| | |
| | |

## O que o programa faz

1. Pede o nome do professor e a senha de acesso.
2. Pede a turma (por exemplo `3a` ou `8b`) e escolhe os parâmetros conforme o ano.
3. Registra o resultado de quatro testes físicos por aluno.
4. Mostra a classificação de cada resultado.
5. Consulta os dados de um aluno pelo nome.
6. Mostra um resumo geral com todos os alunos cadastrados.
7. Atualiza o resultado de um teste de um aluno já cadastrado.

## Testes

| Opção do menu | Capacidade | Teste | Como é medido |
|---|---|---|---|
| 1 | Força | Salto horizontal | Distância em centímetros |
| 2 | Velocidade | Corrida de 20 m | Tempo em segundos |
| 3 | Resistência | Corrida de 6 minutos | Distância em metros |
| 4 | Coordenação | Saltos laterais | Soma dos saltos de 2 tentativas de 15 segundos |

## Parâmetros de classificação

A classificação depende só da turma, sem diferença entre meninos e meninas. O primeiro caractere da turma é o ano: de 1 a 6 o programa usa a primeira faixa, e de 7 a 9 usa a segunda.

### 1º ao 6º ano

| Teste | Abaixo da média | Na média | Acima da média |
|---|---|---|---|
| Salto horizontal (cm) | menos de 113 | 113 a 124 | mais de 124 |
| Corrida de 20 m (s) | mais de 4,67 | 4,37 a 4,67 | menos de 4,37 |
| Corrida de 6 minutos (m) | menos de 747 | 747 a 840 | mais de 840 |
| Saltos laterais (saltos) | menos de 49 | 49 a 64 | mais de 64 |

### 7º ao 9º ano

| Teste | Abaixo da média | Na média | Acima da média |
|---|---|---|---|
| Salto horizontal (cm) | menos de 142 | 142 a 155 | mais de 155 |
| Corrida de 20 m (s) | mais de 4,10 | 3,85 a 4,10 | menos de 3,85 |
| Corrida de 6 minutos (m) | menos de 823 | 823 a 924 | mais de 924 |
| Saltos laterais (saltos) | menos de 70 | 70 a 86 | mais de 86 |

Na corrida de 20 m, quanto menor o tempo, melhor.

### Origem dos parâmetros

- **Salto horizontal, corrida de 20 m e corrida de 6 minutos:** valores definidos pelo grupo com base no Manual PROESP-Br 2021 (UFRGS).
- **Saltos laterais:** média dos percentis 25 e 75 por idade, meninos e meninas juntos, da Tabela 4 de Coppens et al. (2021), *Validation of a Motor Competence Assessment Tool for Children and Adolescents (KTK3+) With Normative Values for 6- to 19-Year-Olds*, Frontiers in Physiology, doi 10.3389/fphys.2021.652952. A amostra do estudo é de crianças da Bélgica.

## Como o código está organizado

Todo o programa está no arquivo `main.c`.

| Parte | Funções | O que faz |
|---|---|---|
| Dados | vetores no topo do arquivo | Guardam nome e resultados; a posição do aluno é a mesma em todos os vetores. O valor -1 indica teste não realizado. |
| Busca | `nome_igual`, `buscar_aluno` | Comparam nomes letra por letra e localizam o aluno. |
| Classificação | `media_maior`, `media_menor`, `media_salto`, `media_corrida20`, `media_corrida6`, `media_saltos` | Escolhem os parâmetros da faixa da turma e mostram a classificação. |
| Testes | `forca`, `velocidade`, `resistencia`, `coordenacao` | Explicam o teste, leem o resultado e guardam. |
| Cadastro e telas | `selecionar_aluno`, `mostrar_aluno`, `consulta`, `resumo`, `atualizar` | Cadastram o aluno e mostram ou alteram os dados. |
| Controle | `menu`, `main` | Fazem o acesso, leem a turma e repetem o menu até a opção 0. |

O programa usa apenas `stdio.h` e `stdlib.h`, com vetores, funções, estruturas condicionais e laços de repetição.

## Limitações

- Os dados ficam em memória e são perdidos quando o programa é encerrado.
- O limite é de 30 alunos por execução.
- O nome do aluno tem uma palavra só, com até 12 letras, e a busca diferencia maiúsculas de minúsculas.
- Cada execução trabalha com uma turma.
- O programa não confere se os valores digitados são negativos ou se foi digitado texto no lugar de número.

## Arquivos do repositório

| Arquivo | Conteúdo |
|---|---|
| `main.c` | Código-fonte do sistema de testes físicos. |
| `README.md` | Este arquivo. |
| `INSTRUCOES_DE_EXECUCAO.md` | Como compilar, executar e usar o programa. |
| `acoes_pse.c` | Programa alternativo de gestão de ações do Programa Saúde na Escola. |
| `docs/` | Manual do usuário, casos de uso e testes do `acoes_pse.c`. |
