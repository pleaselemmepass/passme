#include <iostream>
using namespace std;

class search
{
    int roll[100], sorted[100], n;

public:
    void create();
    void display();
    void sort();
    void linear(int key);
    void binary(int key);
};

void search::create()
{
    cout << "How many students attended the program: ";
    cin >> n;

    cout << "Enter the roll numbers of students: ";

    for (int i = 0; i < n; i++)
    {
        cin >> roll[i];
        sorted[i] = roll[i];
    }
}

void search::display()
{
    cout << "\nRoll numbers of students: ";

    for (int i = 0; i < n; i++)
        cout << roll[i] << " ";

    cout << endl;
}

void search::sort()
{
    int temp;

    cout << "\nSorting using Bubble Sort:\n";

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (sorted[j] > sorted[j + 1])
            {
                temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }

        cout << "Pass " << i + 1 << ": ";

        for (int k = 0; k < n; k++)
            cout << sorted[k] << " ";

        cout << endl;
    }
}

void search::linear(int key)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        count++;

        if (roll[i] == key)
        {
            cout << "\nStudent found using Linear Search.";
            cout << "\nPosition: " << i;
            cout << "\nComparisons: " << count << endl;
            return;
        }
    }

    cout << "\nStudent not found using Linear Search.";
    cout << "\nComparisons: " << count << endl;
}

void search::binary(int key)
{
    int low = 0, high = n - 1;
    int mid, count = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;
        count++;

        if (sorted[mid] == key)
        {
            cout << "\nStudent found using Binary Search.";
            cout << "\nPosition in sorted array: " << mid;
            cout << "\nComparisons: " << count << endl;
            return;
        }
        else if (key < sorted[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    cout << "\nStudent not found using Binary Search.";
    cout << "\nComparisons: " << count << endl;
}

int main()
{
    search s;
    int key;

    s.create();
    s.display();
    s.sort();

    cout << "\nEnter the roll number to search: ";
    cin >> key;

    s.linear(key);
    s.binary(key);

    return 0;
}
