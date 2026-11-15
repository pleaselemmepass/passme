#include <iostream>
using namespace std;
class Matrix
{
    int M[5][5], r, c;
public:
    void create();
    void display();
    void add(Matrix x, Matrix y);
    void sub(Matrix x, Matrix y);
    void mult(Matrix x, Matrix y);
    void transpose(Matrix x);
};
void Matrix::create()
{
    cout << "Enter rows and columns: ";
    cin >> r >> c;
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> M[i][j];
}
void Matrix::display()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
}
void Matrix::add(Matrix x, Matrix y)
{
    if (x.r == y.r && x.c == y.c)
    {
        r = x.r;
        c = x.c;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                M[i][j] = x.M[i][j] + y.M[i][j];
    }
    else
        cout << "Addition not possible\n";
}
void Matrix::sub(Matrix x, Matrix y)
{
    if (x.r == y.r && x.c == y.c)
    {
        r = x.r;
        c = x.c;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                M[i][j] = x.M[i][j] - y.M[i][j];
    }
    else
        cout << "Subtraction not possible\n";
}
void Matrix::mult(Matrix x, Matrix y)
{
    if (x.c == y.r)
    {
        r = x.r;
        c = y.c;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                M[i][j] = 0;
                for (int k = 0; k < x.c; k++)
                    M[i][j] += x.M[i][k] * y.M[k][j];
            }
        }
    }
    else
        cout << "Multiplication not possible\n";
}
void Matrix::transpose(Matrix x)
{
    r = x.c;
    c = x.r;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            M[i][j] = x.M[j][i];
}
int main()
{
    Matrix m1, m2, m3;
    m1.create();
    cout << "First matrix:\n";
    m1.display();
    m2.create();
    cout << "Second matrix:\n";
    m2.display();
    cout << "Addition:\n";
    m3.add(m1, m2);
    m3.display();
    cout << "Subtraction:\n";
    m3.sub(m1, m2);
    m3.display();
    cout << "Multiplication:\n";
    m3.mult(m1, m2);
    m3.display();
    cout << "Transpose of first matrix:\n";
    m3.transpose(m1);
    m3.display();
    return 0;
}
