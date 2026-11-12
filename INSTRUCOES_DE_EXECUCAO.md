# Instruções de execução

Como compilar, executar e usar o Sistema de Testes Físicos Escolares (`main.c`).

## 1. O que é preciso

Um compilador de linguagem C. Qualquer uma das opções abaixo serve:

- **Dev-C++** (Windows).
- **GCC** (Linux, macOS ou Windows com MinGW).

## 2. Compilar e executar

### Com Dev-C++

1. Abra o Dev-C++.
2. Vá em **Arquivo > Abrir** e escolha o arquivo `main.c`.
3. Pressione **F11** para compilar e executar.

### Com GCC

Abra o terminal na pasta onde está o `main.c` e compile:

```
gcc main.c -o testes_fisicos
```

Depois execute. No Linux e no macOS:

```
./testes_fisicos
```

No Windows:

```
testes_fisicos.exe
```

O GCC pode mostrar avisos (warnings) sobre o `scanf` durante a compilação. Eles não impedem o programa de funcionar.

## 3. Acesso

Ao abrir, o programa pede o professor e a senha.

```
PROFESSOR: Ana
SENHA: 12211
ACESSO AUTORIZADO, BEM VINDO PROFESSOR Ana
```

- **Professor:** uma palavra só, sem espaço.
- **Senha:** `12211`.

Com a senha errada, o programa mostra `ACESSO NEGADO, CREDENCIAIS NAO AUTORIZADAS` e encerra.

## 4. Escolher a turma

Digite a turma começando pelo ano, seguido da letra: `3a` é o 3º ano turma A, `8b` é o 8º ano turma B.

```
Selecione a turma para a analise (exemplo: 3a, 5b): 3a
Turma 3a: parametros do 1 ao 6 ano.
```

Se a turma não começar com um número de 1 a 9, o programa avisa e pede de novo.

## 5. Menu

```
TESTES DISPONIVEIS     OU      CONSULTA DE DADOS.
1 - forca
2 - velocidade
3 - resistencia
4 - coordenacao
5 - consulta
6 - resumo geral
7 - atualizar dados de um aluno
0 - sair
Qual teste quer analisar?
```

Digite o número da opção e pressione Enter. Depois de cada operação o menu aparece de novo, até a opção `0`.

| Opção | O que faz | O que o programa pede |
|---|---|---|
| 1 | Registra o salto horizontal | Nome do aluno e distância em centímetros |
| 2 | Registra a corrida de 20 m | Nome do aluno e tempo em segundos |
| 3 | Registra a corrida de 6 minutos | Nome do aluno e distância em metros |
| 4 | Registra os saltos laterais | Nome do aluno e a quantidade de saltos das 2 tentativas |
| 5 | Consulta um aluno | Nome do aluno |
| 6 | Mostra todos os alunos cadastrados | Nada |
| 7 | Refaz um teste de um aluno já cadastrado | Nome do aluno e qual teste |
| 0 | Encerra o programa | Nada |

## 6. Registrar um teste (opções 1 a 4)

1. Escolha o teste no menu.
2. Digite o nome do aluno. Se o nome ainda não existe, o aluno é cadastrado na hora.
3. Digite o resultado.
4. O programa mostra o resultado e a classificação.

```
Qual teste quer analisar?
1
Informe o nome do aluno: Joao

FORCA: SALTO HORIZONTAL
 O aluno executa um salto horizontal para frente com os pes juntos, partindo parado atras de uma linha.
 Sera medida a distancia da linha ate o calcanhar mais proximo (em centimetros).

Insira a distancia do salto (em centimetros), arredondando para baixo: 120

Resultado: 120 cm - NA MEDIA
```

Nos saltos laterais (opção 4) o programa pede as duas tentativas e soma:

```
Insira a quantidade de saltos (1 tentativa): 28
Insira a quantidade de saltos (2 tentativa): 30

Resultado: 58 saltos (soma das 2 tentativas) - NA MEDIA
```

## 7. Consultar um aluno (opção 5)

Digite o nome exatamente como foi cadastrado.

```
PESQUISA DE ALUNO
Informe o nome do aluno: Joao

ALUNO: Joao   TURMA: 3a
Salto horizontal: 120 cm - NA MEDIA
Corrida de 20m: 4.500000 s - NA MEDIA
Corrida de 6 minutos: nao realizado
Saltos laterais: 58 saltos - NA MEDIA
```

Um teste que ainda não foi feito aparece como `nao realizado`. Se o nome não existir, aparece `Aluno nao encontrado.`

## 8. Resumo geral (opção 6)

Mostra a turma, o total de alunos cadastrados e os dados de cada aluno, no mesmo formato da consulta. Sem alunos cadastrados, aparece `Nenhum aluno cadastrado.`

## 9. Atualizar dados de um aluno (opção 7)

1. Digite o nome do aluno. Ele precisa já estar cadastrado.
2. O programa mostra os dados atuais.
3. Escolha qual teste refazer: `1` força, `2` velocidade, `3` resistência, `4` coordenação, ou `0` para cancelar.
4. Digite o novo resultado. Ele substitui o anterior.

## 10. Cuidados ao digitar

- **Nome do aluno:** uma palavra só, com até 12 letras, sem espaço.
- **Maiúsculas e minúsculas:** `joao` e `Joao` são alunos diferentes para o programa.
- **Números decimais:** use ponto, não vírgula. Digite `4.5`, não `4,5`.
- **Onde o programa pede número, digite só número.** Uma letra no menu encerra o programa.
- **Os dados não são salvos.** Ao escolher `0` ou fechar a janela, tudo é perdido.
