# Testes

Casos de teste executados no arquivo `acoes_pse.c`, compilado com GCC no Linux. Todos tiveram o resultado esperado. O grupo deve repetir os testes no ambiente definido pelo professor e tirar as capturas de tela.

## Menu

| Nº | Entrada | Resultado esperado | Situação |
|---|---|---|---|
| 1 | Opção `9` no menu | Mensagem "opcao inexistente" e o menu aparece de novo | Passou |
| 2 | Texto `abc` no menu | Mensagem "digite um numero inteiro valido" e pede a opção de novo | Passou |
| 3 | Opção `0` | Mensagem "Sistema encerrado" e o programa termina | Passou |

## Cadastro

| Nº | Entrada | Resultado esperado | Situação |
|---|---|---|---|
| 4 | Código `-3` | Mensagem "a quantidade nao pode ser negativa" e pede o código de novo | Passou |
| 5 | Código `0` | Mensagem de valor mínimo e pede o código de novo | Passou |
| 6 | Código já cadastrado | Mensagem "ja existe uma acao com o codigo" e pede outro | Passou |
| 7 | Escola vazia ou só com espaços | Mensagem "este campo e obrigatorio" e pede de novo | Passou |
| 8 | Data `31/02/2026` | Mensagem "data invalida" e pede de novo | Passou |
| 9 | Data `15-03-2026` | Mensagem "data invalida" e pede de novo | Passou |
| 10 | Data `29/02/2026` (ano não bissexto) | Mensagem "data invalida" e pede de novo | Passou |
| 11 | Data `29/02/2028` (ano bissexto) | Data aceita | Passou |
| 12 | Quantidade prevista `-5` | Mensagem "a quantidade nao pode ser negativa" e pede de novo | Passou |
| 13 | Quantidade prevista `dez` | Mensagem "digite um numero inteiro valido" e pede de novo | Passou |
| 14 | Situação inicial `7` | Mensagem "opcao inexistente" e pede de novo | Passou |
| 15 | Situação inicial `2` (realizada) | O programa pede a quantidade efetiva de participantes | Passou |
| 16 | Dados válidos | Mensagem "Acao N cadastrada com sucesso" | Passou |
| 17 | 51º cadastro | Mensagem "limite de 50 acoes atingido" e volta ao menu | Passou |
| 18 | Escola com mais de 40 caracteres | O texto é cortado em 40 caracteres e o cadastro continua | Passou |

## Listagem

| Nº | Entrada | Resultado esperado | Situação |
|---|---|---|---|
| 19 | Listar sem ações cadastradas | Mensagem "Nenhuma acao cadastrada" | Passou |
| 20 | Listar com 3 ações | Total 3 e os dados das 3 ações | Passou |

## Pesquisa

| Nº | Entrada | Resultado esperado | Situação |
|---|---|---|---|
| 21 | Por código existente | Mostra a ação | Passou |
| 22 | Por código inexistente (`99`) | Mensagem "Nenhuma acao encontrada com o codigo 99" | Passou |
| 23 | Por escola, trecho `jardim` | Mostra as 2 ações da escola "Jardim das Flores" | Passou |
| 24 | Por tema, trecho `SAUDE` em maiúsculas | Mostra a ação de tema "Saude bucal" | Passou |
| 25 | Por tema inexistente (`xyz`) | Mensagem "Nenhuma acao encontrada" | Passou |

## Atualização de situação

| Nº | Entrada | Resultado esperado | Situação |
|---|---|---|---|
| 26 | Código inexistente (`99`) | Mensagem "nao existe acao com o codigo 99" | Passou |
| 27 | Nova situação `5` | Mensagem "opcao inexistente" e pede de novo | Passou |
| 28 | Planejada para realizada, com 55 efetivos | Situação "Realizada" e 55 participantes efetivos | Passou |
| 29 | Realizada para cancelada | Situação "Cancelada" e participantes efetivos zerados | Passou |

## Resumo geral

| Nº | Entrada | Resultado esperado | Situação |
|---|---|---|---|
| 30 | Resumo sem ações cadastradas | Mensagem "Nenhuma acao cadastrada" | Passou |
| 31 | 2 realizadas (60 e 40 previstos; 55 e 35 efetivos) e 1 cancelada (30 previstos) | 0 planejadas, 2 realizadas, 1 cancelada; 130 previstos no total; 100 previstos nas realizadas; 90 efetivos; 90.0% | Passou |
| 32 | Resumo sem nenhuma ação realizada | Contagens e a mensagem "sem acoes realizadas para calcular" | Passou |
