# Desafio #01 da Disciplina de Sistemas Operacionais

Multiplicações de matrizes

### Pré-requisitos 

1️⃣ Visual Studio Code

2️⃣ g++

## Compilando os testes

```
g++ auxiliar.cpp -o auxiliar
```
```
g++ sequencial.cpp -o sequencial
```
```
g++ paraleloThreads.cpp -o paraleloThreads -lpthread
```
## Executando os testes (execute na ordem)

``` 
./auxiliar n1 m1 n2 m2
```
➡️ Executa o programa auxiliar passando linhas e colunas para duas matrizes por linha de comando 

Exemplo:

  ./auxiliar 5 5 5 5

``` 
./sequencial M1.txt M2.txt 
```
➡️ Executa o programa auxiliar passando os dois arquivos txt criando no programa auxiliar 

``` 
./paraleloThreads M1.txt M2.txt p
```
➡️ Executa o programa auxiliar passando os dois arquivos txt criando no programa auxiliar e uma váriavel p

p = quantidade de elementos que vai ser calculada

Exemplo:

  ./paraleloThreads M1.txt M2.txt 5

### ⚠️ Limitações

O projeto está faltando parte o programa que calcula matrizes usando processos


## Author

<a target="_blank" href="https://github.com/jasonwillyan">👤 Jason Willyan </a>


