# G21_Ordenacao_EDA2-2026.1

Número da Lista: 2
Conteúdo da Disciplina: Algoritmos de Ordenação (Estruturas de Dados II)

## Alunos

| Matrícula | Aluno                            |
| --------- | -------------------------------- |
| 202016604 | João Lucas Miranda de Sousa                   |

## Sobre

Este projeto implementa um sistema de agenda de eventos com o objetivo de aplicar conceitos de estruturas de dados. O sistema permite cadastrar, visualizar e gerenciar eventos com data, hora e descrição, oferecendo funcionalidades como visualização por mês e identificação do próximo evento.

## Screenshots

## Linguagem Utilizada

O projeto foi desenvolvido utilizando a linguagem C.

## Requisitos do Sistema

Para executar o programa, é necessário:

- Compilador C (GCC recomendado)
- Sistema operacional: Linux, Windows ou macOS
- Terminal ou prompt de comando

## Compilar o Programa

No terminal, navegue até a pasta do projeto e execute:

```
gcc agendaEvento.c -o agendaEvento
```

Isso irá gerar o executável do programa.

## Uso

Após compilar, execute o programa com o comando:

```
./agendaEvento
```

Ao executar, será exibido um menu com as seguintes opções:

1 - Cadastrar evento  
2 - Mostrar agenda  
3 - Mostrar eventos de um mês específico  
4 - Mostrar próximo evento  
5 - Sair  

### Descrição das Opções

**Cadastrar evento**  
Permite inserir um novo evento informando seu nome, data (dia, mês e ano) e horário (hora e minuto).

**Mostrar agenda**  
Exibe todos os eventos cadastrados em ordem baseada em suas respectivas datas e horários.

**Mostrar eventos de um mês específico**  
Filtra e exibe apenas os eventos que ocorrem em um determinado mês informado pelo usuário ordenados por data.

**Mostrar próximo evento**  
Identifica e mostra o próximo evento a ocorrer após a data atual.

**Sair**  
Encerra o programa.

## Outros

- **Estruturas de dados utilizadas:**


- **Funcionalidades implementadas:**

- Cadastro de múltiplos eventos
- Armazenamento em vetor de estruturas
- Listagem completa da agenda
- Filtro de eventos por mês
- Identificação do próximo evento futuro