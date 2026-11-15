#include <iostream>
using namespace std;

class matrix
{
    int r1, c1, r2, c2;
    int a[10][10], b[10][10];

public:
    void create();
    void display();
    void add();
    void sub();
    void mult();
    void transpose();
};

void matrix::create()
{
    cout << "Enter rows and columns of first matrix: ";
    cin >> r1 >> c1;

    cout << "Enter elements of first matrix:\n";

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cout << "Index (" << i << " " << j << "): ";
            cin >> a[i][j];
        }
    }

    cout << "Enter rows and columns of second matrix: ";
    cin >> r2 >> c2;

    cout << "Enter elements of second matrix:\n";

    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << "Index (" << i << " " << j << "): ";
            cin >> b[i][j];
        }
    }
}

void matrix::display()
{
    cout << "\nFirst Matrix:\n";

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
            cout << a[i][j] << " ";

        cout << endl;
    }

    cout << "\nSecond Matrix:\n";

    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
            cout << b[i][j] << " ";

        cout << endl;
    }
}

void matrix::add()
{
    if (r1 != r2 || c1 != c2)
    {
        cout << "Addition not possible." << endl;
        return;
    }

    cout << "\nAddition of both matrices:\n";

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
            cout << a[i][j] + b[i][j] << " ";

        cout << endl;
    }
}

void matrix::sub()
{
    if (r1 != r2 || c1 != c2)
    {
        cout << "Subtraction not possible." << endl;
        return;
    }

    cout << "\nSubtraction of both matrices:\n";

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
            cout << a[i][j] - b[i][j] << " ";

        cout << endl;
    }
}

void matrix::mult()
{
    if (c1 != r2)
    {
        cout << "Multiplication not possible." << endl;
        return;
    }

    int sum;

    cout << "\nMultiplication of both matrices:\n";

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            sum = 0;

            for (int k = 0; k < c1; k++)
                sum += a[i][k] * b[k][j];

            cout << sum << " ";
        }

        cout << endl;
    }
}

void matrix::transpose()
{
    cout << "\nTranspose of first matrix:\n";

    for (int i = 0; i < c1; i++)
    {
        for (int j = 0; j < r1; j++)
            cout << a[j][i] << " ";

        cout << endl;
    }

    cout << "\nTranspose of second matrix:\n";

    for (int i = 0; i < c2; i++)
    {
        for (int j = 0; j < r2; j++)
            cout << b[j][i] << " ";

        cout << endl;
    }
}

int main()
{
    matrix m;

    m.create();
    m.display();
    m.add();
    m.sub();
    m.mult();
    m.transpose();

    return 0;
}
