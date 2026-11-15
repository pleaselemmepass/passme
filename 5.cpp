
#include <iostream>
using namespace std;

class sorting
{
    float s[100];
    int num;

public:
    void create();
    void display();
    void quick();
};

void sorting::create()
{
    cout << "Enter number of students: ";
    cin >> num;

    cout << "Enter percentages:\n";

    for (int i = 0; i < num; i++)
        cin >> s[i];
}

void sorting::quick()
{
    int low[100], high[100];
    int top = -1;

    low[++top] = 0;
    high[top] = num - 1;

    int pass = 1;

    while (top >= 0)
    {
        int l = low[top];
        int h = high[top];
        top--;

        int i = l;
        int j = h;
        float pivot = s[(l + h) / 2];
        float temp;

        while (i <= j)
        {
            while (s[i] < pivot)
                i++;

            while (s[j] > pivot)
                j--;

            if (i <= j)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;

                i++;
                j--;
            }
        }

        cout << "Pass " << pass++ << ": ";

        for (int k = 0; k < num; k++)
            cout << s[k] << " ";

        cout << endl;

        if (l < j)
        {
            low[++top] = l;
            high[top] = j;
        }

        if (i < h)
        {
            low[++top] = i;
            high[top] = h;
        }
    }
}

void sorting::display()
{
    cout << "\nSorted percentages:\n";

    for (int i = 0; i < num; i++)
        cout << s[i] << " ";

    cout << "\n\nTop five scores:\n";

    int start = num - 5;

    if (start < 0)
        start = 0;

    for (int i = num - 1; i >= start; i--)
        cout << s[i] << " ";

    cout << endl;
}

int main()
{
    sorting s;

    s.create();
    s.quick();
    s.display();

    return 0;
}



#include <iostream>
using namespace std;

class sorting
{
    float s[100];
    int num, pass;
public:
    void create();
    void display();
    void quick(int l, int h);
};

void sorting::create()
{
    cout << "Enter number of students: ";
    cin >> num;
    cout << "Enter percentages:\n";
    for(int i = 0; i < num; i++)
    {
        cin >> s[i];
    }
    pass = 1;
}

void sorting::display()
{
    cout << "\nSorted percentages:\n";
    for(int i = 0; i < num; i++)
    {
        cout << s[i] << " ";
    }

    cout << "\n\nTop five scores:\n";
    int start;
    if(num > 5)
        start = num - 5;
    else
        start = 0;

    for(int i = num - 1; i >= start; i--)
    {
        cout << s[i] << " ";
    }
    cout << endl;
}

void sorting::quick(int l, int h)
{
    int i = l;
    int j = h;
    float pivot = s[(l + h) / 2];
    float temp;

    while(i <= j)
    {
        while(s[i] < pivot)
            i++;

        while(s[j] > pivot)
            j--;

        if(i <= j)
        {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }

    cout << "Pass " << pass++ << ": ";
    for(int k = 0; k < num; k++)
    {
        cout << s[k] << " ";
    }
    cout << endl;

    if(l < j)
        quick(l, j);

    if(i < h)
        quick(i, h);
}

int main()
{
    sorting s;
    s.create();

    cout << "\nQuick Sort Pass-wise Output:\n";
    s.quick(0, 0); // Replace this call with s.quick(0, num-1) using the corrected call below.

    s.display();
    return 0;
}

