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

template <typename T>  
void calc(const Matriz<T> &M1, const Matriz<T> &M2, Matriz<T> &M3, int linha, int coluna, int total_elementos)
{
    string nomeArquivo = to_string(linha) + " - " + to_string(coluna) +".txt";

    auto begin = chrono::high_resolution_clock::now();

    ofstream arquivo(nomeArquivo);
    arquivo << M3.getLine() << " " << M3.getColuna() << endl;

	int elementos = 0;
	for (int i = linha; i < M3.getLine(); i++)
	{
		for (int j = coluna; j < M3.getColuna(); j++)
		{
			M3.at(i, j) = 0;
			for (int k = 0; k < M2.getLine(); k++)
			{
				M3.at(i, j) += M1.get(i, k) * M2.get(k, j);
			}
            arquivo << "c" << i + 1 << j + 1 << " " << M3.at(i, j) << endl;
			elementos++;
			if (elementos == total_elementos)
            {
                auto end = chrono::high_resolution_clock::now();
                auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - begin).count();

                time_t end_time = chrono::system_clock::to_time_t(end);
                cout << "finished computation at " << ctime(&end_time) << endl;

                arquivo << elapsed;
                arquivo.close();
				return;
            }
		}
	}
}

template <typename T>
Matriz<T> multiplica(const Matriz<T> &M1, const Matriz<T> &M2, int elementos)
{
	vector<thread *> threads_vector;
	Matriz<T> M3(M1.getLine(), M2.getColuna());
	for (int i = 0; i < M1.getLine() * M2.getColuna(); i += elementos)
	{
		thread *calc_thread = new thread(calc<T>, ref(M1), ref(M2), ref(M3), i / M3.getColuna(), i % M3.getColuna(), elementos);
		threads_vector.emplace_back(calc_thread);
	}
	for (auto thread : threads_vector)
    {
		thread->join();
    }

	return M3;
}


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
    //int **M1 = Matriz<int>::newMatrix(linhaM1, colunaM1);
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
    //int **M2 = Matriz<int>::newMatrix(linhaM2, colunaM2);
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

    return 0;
}