# Manual do usuário

## Objetivo

O sistema ajuda a equipe responsável pelo Programa Saúde na Escola (PSE) a registrar e acompanhar as ações coletivas realizadas nas escolas: o que foi planejado, o que já aconteceu, o que foi cancelado e quantas pessoas participaram.

O sistema trabalha somente com informações coletivas das ações. Não cadastre nome, diagnóstico ou qualquer dado individual de estudantes.

## Como compilar e executar

Com GCC:

```
gcc acoes_pse.c -o acoes_pse
./acoes_pse
```

No Windows, o segundo comando é `acoes_pse.exe`.

Com Dev-C++: abra o arquivo `acoes_pse.c` e pressione **F11**.

## Menu principal

Ao abrir, o programa mostra o menu e espera o número de uma opção. Depois de cada operação, o menu aparece de novo, até a opção 0 ser escolhida.

```
========================================
GESTAO DE ACOES DO PROGRAMA SAUDE NA ESCOLA
========================================
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acao
4 - Atualizar situacao
5 - Resumo geral
0 - Sair
Opcao:
```

| Opção | O que faz |
|---|---|
| 1 | Cadastra uma nova ação. |
| 2 | Mostra todas as ações cadastradas. |
| 3 | Procura ações por código, escola ou tema. |
| 4 | Muda a situação de uma ação. |
| 5 | Mostra o resumo geral das ações. |
| 0 | Encerra o programa. |

## Opção 1: cadastrar ação

O programa pede os dados na ordem abaixo.

| Campo | Regra |
|---|---|
| Código | Número inteiro maior que zero, que não pode se repetir. |
| Escola | Texto obrigatório, com até 40 caracteres. |
| Tema | Texto obrigatório, com até 40 caracteres. |
| Data prevista | Formato `dd/mm/aaaa`, por exemplo `15/03/2026`. |
| Público-alvo | Texto obrigatório, por exemplo `5o ano`. |
| Responsável | Texto obrigatório: o profissional que conduz a ação. |
| Quantidade prevista de participantes | Número inteiro maior que zero. |
| Situação inicial | 1 para planejada, 2 para realizada, 3 para cancelada. |

Se a situação inicial for "realizada", o programa também pede a quantidade efetiva de participantes.

Exemplo:

```
CADASTRO DE ACAO DO PSE
Codigo da acao (numero maior que zero): 10
Escola: Escola Municipal Jardim das Flores
Tema: Saude bucal
Data prevista (dd/mm/aaaa): 15/03/2026
Publico-alvo (exemplo: 5o ano): 5o ano
Responsavel pela acao: Enfermeira Carla
Quantidade prevista de participantes: 60

Situacao inicial:
1 - Planejada
2 - Realizada
3 - Cancelada
Situacao: 1

Acao 10 cadastrada com sucesso.
```

## Opção 2: listar ações

Mostra o total de ações e os dados de cada uma, na ordem em que foram cadastradas.

```
LISTA DE ACOES CADASTRADAS
Total de acoes: 1

----------------------------------------
Codigo: 10
Escola: Escola Municipal Jardim das Flores
Tema: Saude bucal
Data prevista: 15/03/2026
Publico-alvo: 5o ano
Responsavel: Enfermeira Carla
Participantes previstos: 60
Situacao: Planejada
```

## Opção 3: pesquisar ação

O programa pergunta o tipo de pesquisa:

- **1 - Por código:** mostra a ação com exatamente aquele código.
- **2 - Por escola:** mostra todas as ações cuja escola contém o texto digitado.
- **3 - Por tema:** mostra todas as ações cujo tema contém o texto digitado.

Na pesquisa por escola ou tema basta digitar uma parte do texto, e letras maiúsculas e minúsculas são tratadas como iguais. Por exemplo, `jardim` encontra "Escola Municipal Jardim das Flores".

```
PESQUISA DE ACOES
1 - Por codigo
2 - Por escola
3 - Por tema
0 - Voltar
Opcao: 2
Escola (ou parte do nome): jardim
```

## Opção 4: atualizar situação

1. Digite o código da ação.
2. O programa mostra os dados atuais.
3. Escolha a nova situação: 1 para planejada, 2 para realizada, 3 para cancelada.
4. Se a nova situação for "realizada", informe a quantidade efetiva de participantes.

```
ATUALIZAR SITUACAO DE UMA ACAO
Codigo da acao: 10
...
Nova situacao:
1 - Planejada
2 - Realizada
3 - Cancelada
Situacao: 2
Quantidade efetiva de participantes: 55

Situacao da acao 10 atualizada para Realizada.
```

Quando a ação deixa de estar como "realizada", a quantidade efetiva volta a zero.

## Opção 5: resumo geral

Mostra a quantidade de ações por situação, o total de participantes e o percentual de participação.

```
RESUMO GERAL DAS ACOES DO PSE
Acoes cadastradas: 3
Acoes planejadas: 0
Acoes realizadas: 2
Acoes canceladas: 1

Participantes previstos em todas as acoes: 130
Participantes previstos nas acoes realizadas: 100
Total de participantes efetivos: 90
Percentual de participacao (efetivos / previstos das acoes realizadas): 90.0%
```

O percentual compara os participantes efetivos com os previstos somente das ações realizadas, porque ações planejadas ou canceladas ainda não têm participantes efetivos.

## Mensagens de erro

| Mensagem | Quando aparece |
|---|---|
| `ERRO: opcao inexistente.` | O número digitado não é uma das opções do menu. |
| `ERRO: digite um numero inteiro valido.` | Foi digitado texto onde o programa esperava um número. |
| `ERRO: ja existe uma acao com o codigo N.` | O código informado no cadastro já foi usado. |
| `ERRO: a quantidade nao pode ser negativa.` | Foi digitado um número negativo. |
| `ERRO: este campo e obrigatorio.` | O campo de texto ficou vazio. |
| `ERRO: data invalida.` | A data não está no formato `dd/mm/aaaa` ou não existe. |
| `ERRO: nao existe acao com o codigo N.` | O código informado na atualização não foi cadastrado. |
| `ERRO: limite de 50 acoes atingido.` | Já existem 50 ações cadastradas. |

Depois de uma mensagem de erro, o programa pede o mesmo dado de novo.

## Limitações

- Os dados ficam em memória e são perdidos quando o programa é encerrado.
- O limite é de 50 ações por execução.
- Não é possível editar os outros campos de uma ação nem excluir uma ação.
- Textos com mais de 40 caracteres são cortados.
