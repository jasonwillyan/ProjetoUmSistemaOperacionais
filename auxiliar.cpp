#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

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

    int M1[n1][m1];
    int M2[n2][m2];

    fstream arquivo;
    arquivo.open("M1.txt", ios::out);
    arquivo << n1 << " " << m1 << "\n";

    for (size_t i = 0; i < n1; i++)
    {
        for (size_t j = 0; j < m1; j++)
        {
            M1[i][j] = rand() % 100;
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
            M2[i][j] = rand() % 100;
            arquivo << M2[i][j] << " ";
        }
        arquivo << "\n";
    }

    arquivo.close();
    cout << endl;
    return 0;
}