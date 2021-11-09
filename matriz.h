#ifndef matriz_h
#define matriz_h
#include <fstream>

using namespace std;

template <typename T> 
class Matriz
{
    private:
        int nlin = 0;
        int ncol = 0;
        int **matriz;

    public:
        Matriz(int linhaM1, int colunaM2)
        {
            matriz = newMatrix(linhaM1, colunaM2);
        }

        ~Matriz()
        {
            //Destrutor
        }

        int getLine() const
        {
            return nlin;
        }

        int getColuna() const
        {
            return ncol;
        }

    T &at(size_t line, size_t column)
    {
        return matriz[line][column];
    }

    const T &get(size_t line, size_t column) const
    {
        return matriz[line][column];
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

    int **newMatrix(int nlin, int ncol)
    {
        int **matrix;
        this->nlin = nlin;
        this->ncol = ncol;
        matrix = new int *[nlin];
        for (int i = 0; i < nlin; ++i)
        {
            matrix[i] = new int[ncol];
        }
        return matrix;
    }
};

#endif