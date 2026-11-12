# Gestão de Ações do Programa Saúde na Escola (PSE)

Trabalho da AEP da Universidade Cesumar (UniCesumar): sistema em linguagem C, executado no terminal, para cadastrar e acompanhar ações coletivas do Programa Saúde na Escola.

## Integrantes

> Preencher com os dados do grupo.

| Nome | RA |
|---|---|
| | |
| | |
| | |

## O que o sistema faz

1. Cadastra uma ação do PSE com código, escola, tema, data prevista, público-alvo, responsável, quantidade prevista de participantes e situação inicial.
2. Lista todas as ações cadastradas.
3. Pesquisa ações por código, escola ou tema.
4. Atualiza a situação da ação (planejada, realizada ou cancelada) e, quando realizada, registra a quantidade efetiva de participantes.
5. Gera um resumo geral com a quantidade de ações por situação, o total de participantes e o percentual de participação.
6. Valida as entradas: código repetido, quantidade negativa, campo obrigatório vazio, data inválida e opção inexistente no menu.

Os dados ficam em memória enquanto o programa está aberto e são perdidos ao encerrar.

## Arquivos do repositório

| Arquivo | Conteúdo |
|---|---|
| `acoes_pse.c` | Código-fonte do sistema de ações do PSE (escopo do trabalho). |
| `main.c` | Versão anterior do grupo, um registro de testes físicos por aluno. Não faz parte do escopo do trabalho. |
| `docs/manual_do_usuario.md` | Manual do usuário, com instruções e exemplo de uso. |
| `docs/casos_de_uso.md` | Diagrama e descrição dos casos de uso. |
| `docs/testes.md` | Casos de teste executados. |

## Como compilar e executar

### Com GCC (Linux, macOS ou Windows com MinGW)

```
gcc acoes_pse.c -o acoes_pse
```

No Linux e no macOS:

```
./acoes_pse
```

No Windows:

```
acoes_pse.exe
```

### Com Dev-C++

1. Abra o arquivo `acoes_pse.c` em **Arquivo > Abrir**.
2. Pressione **F11** para compilar e executar.

## Limites do sistema

- O sistema usa somente dados fictícios e informações coletivas sobre as ações.
- Não são cadastrados nome, diagnóstico, prontuário ou qualquer dado individual de estudantes.
- O programa não faz diagnóstico, triagem médica, prescrição ou recomendação de tratamento.
- O limite é de 50 ações por execução.
