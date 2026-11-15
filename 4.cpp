#include <iostream>
using namespace std;

class sort
{
    float a[100], b[100];
    int n;

public:
    void create();
    void selection();
    void bubble();
    void topfive(float arr[]);
};

void sort::create()
{
    cout << "Enter the number of students: ";
    cin >> n;

    cout << "Enter the percentages of students: ";

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
}

void sort::selection()
{
    int min;
    float temp;

    cout << "\nSelection Sort:\n";

    for (int i = 0; i < n - 1; i++)
    {
        min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;

        cout << "Pass " << i + 1 << ": ";

        for (int k = 0; k < n; k++)
            cout << a[k] << " ";

        cout << endl;
    }

    topfive(a);
}

void sort::bubble()
{
    float temp;

    cout << "\nBubble Sort:\n";

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (b[j] > b[j + 1])
            {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }

        cout << "Pass " << i + 1 << ": ";

        for (int k = 0; k < n; k++)
            cout << b[k] << " ";

        cout << endl;
    }

    topfive(b);
}

void sort::topfive(float arr[])
{
    cout << "Top five scores:\n";

    int start = n - 5;

    if (start < 0)
        start = 0;

    for (int i = n - 1; i >= start; i--)
        cout << arr[i] << " ";

    cout << endl;
}

int main()
{
    sort s;

    s.create();
    s.selection();
    s.bubble();

    return 0;
}
