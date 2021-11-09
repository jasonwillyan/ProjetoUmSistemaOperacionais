#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <sstream>

using namespace std;

int **newMatrix(int nlin, int ncol)
{
    int **matrix;
    matrix = new int *[nlin];
    for (int i = 0; i < nlin; ++i)
    {
        matrix[i] = new int[ncol];
    }
    return matrix;
}

void mutiplicarMatriz(int **M1, int **M2, int **M3, int linhaM1, int colunaM2)
{
    if (linhaM1 != colunaM2)
    {
        abort();
    }

    ofstream arquivo("M3.txt");
    arquivo << linhaM1 << " " << colunaM2 << endl;

    for (int i = 0; i < linhaM1; i++)
    {
        for (int j = 0; j < colunaM2; j++)
        {
            M3[i][j] = 0;
            for (int k = 0; k < linhaM1; k++)
            {
                M3[i][j] += M1[i][k] * M2[k][j];
            }
            arquivo << "c" << i + 1 << j + 1 << " " << M3[i][j] << endl;
        }
    }
    arquivo.close();
}

int main()
{
    int linhaM1, colunaM1;
    fstream arquivo("M1.txt", ios_base::in);
    string line;
    getline(arquivo, line);
    stringstream stream(line);
    stream >> linhaM1;
    stream >> colunaM1;
    int **M1 = newMatrix(linhaM1, colunaM1);

    for (int i = 0; i < linhaM1; i++)
    {
        string line;
        getline(arquivo, line);
        stringstream stream(line);
        for (int j = 0; j < colunaM1; ++j)
        {
            stream >> M1[i][j];
        }
    }

    arquivo.close();

    int linhaM2, colunaM2;
    arquivo.open("M2.txt", ios_base::in);
    string line1;
    getline(arquivo, line1);
    stringstream stream1(line1);
    stream1 >> linhaM2;
    stream1 >> colunaM2;
    int **M2 = newMatrix(linhaM2, colunaM2);

    for (int i = 0; i < linhaM2; i++)
    {
        string line1;
        getline(arquivo, line1);
        stringstream stream1(line1);
        for (int j = 0; j < colunaM2; ++j)
        {
            stream1 >> M2[i][j];
        }
    }
    arquivo.close();
    auto begin = chrono::high_resolution_clock::now();

    int **M3 = newMatrix(linhaM1, colunaM2);
    mutiplicarMatriz(M1, M2, M3, linhaM1, colunaM2);

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin).count();

    time_t end_time = chrono::system_clock::to_time_t(end);
    cout << "finished computation at " << ctime(&end_time) << endl;

    ofstream arquivo1("M3.txt", ios::app);
    arquivo1 << elapsed;
    arquivo.close();
    return 0;
}