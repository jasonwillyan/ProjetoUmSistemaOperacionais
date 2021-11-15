#include "matriz.h" 
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <sstream>
#include <unistd.h>
#include <thread>
#include <vector>

using namespace std;

//Função para mutiplicar matriz usando fork()

int main(int argc, char *argv[])
{
    //cout << "Nome do executavel: " << argv[0] << endl;
    if (argc > 1)
    {
        cout << endl;
        for (int i = 1; i < argc; ++i)
        {

            cout << "Argumento " << i << ": " << argv[i] << endl;
        }
    }
    else
    {
        cout << "Nao foram passados argumentos" << endl;
    }

    string arquivoUm(argv[1]);
    string arquivoDois(argv[2]);
    int p = atoi(argv[3]);

    int linhaM1, colunaM1;
    fstream arquivo(arquivoUm, ios_base::in);
    string line;
    getline(arquivo, line);
    stringstream stream(line);
    stream >> linhaM1;
    stream >> colunaM1;
    Matriz<int> M1(linhaM1, colunaM1);

    for (int i = 0; i < linhaM1; i++)
    {
        string line;
        getline(arquivo, line);
        stringstream stream(line);
        for (int j = 0; j < colunaM1; ++j)
        {
            stream >> M1.at(i, j);
        }
    }

    arquivo.close();

    int linhaM2, colunaM2;
    arquivo.open(arquivoDois, ios_base::in);
    string line1;
    getline(arquivo, line1);
    stringstream stream1(line1);
    stream1 >> linhaM2;
    stream1 >> colunaM2;
    Matriz<int> M2(linhaM2, colunaM2);

    for (int i = 0; i < linhaM2; i++)
    {
        string line1;
        getline(arquivo, line1);
        stringstream stream1(line1);
        for (int j = 0; j < colunaM2; ++j)
        {
            stream1 >> M2.at(i, j);
        }
    }
    arquivo.close();

    multiplica(M1, M2, p);
}