#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>


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

int main(int argc, char *argv[])
{
    srand(time(nullptr));
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

    int n1 = atoi(argv[1]);
    int m1 = atoi(argv[2]);
    int n2 = atoi(argv[3]);
    int m2 = atoi(argv[4]);

    int **M1 = newMatrix(n1, m1);
    int **M2 = newMatrix(n2, m2);

    fstream arquivo;
    arquivo.open("M1.txt", ios::out);
    arquivo << n1 << " " << m1 << "\n";

    for (size_t i = 0; i < n1; i++)
    {
        for (size_t j = 0; j < m1; j++)
        {
            M1[i][j] = rand();
            arquivo << M1[i][j] << " ";
        }
        arquivo << "\n";
    }

    arquivo.close();

    arquivo.open("M2.txt", ios::out);
    arquivo << n2 << " " << m2 << "\n";

    for (size_t i = 0; i < n2; i++)
    {
        for (size_t j = 0; j < m2; j++)
        {
            M2[i][j] = rand();
            arquivo << M2[i][j] << " ";
        }
        arquivo << "\n";
    }

    arquivo.close();
    cout << endl;
    return 0;
}