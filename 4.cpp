#include <iostream>
using namespace std;
class Student
{
    float marks[50], temp;
    int n;
public:
    void create();
    void display();
    void selectionSort();
    void bubbleSort();
    void topFive();
};
void Student::create()
{
    cout << "Enter number of students: ";
    cin >> n;
    cout << "Enter percentages: ";
    for (int i = 0; i < n; i++)
        cin >> marks[i];
}
void Student::display()
{
    cout << "Percentages: ";
    for (int i = 0; i < n; i++)
        cout << marks[i] << " ";
    cout << endl;
}
void Student::selectionSort()
{
    for (int i = 0; i < n - 1; i++)
    {
        int small = i;
        for (int j = i + 1; j < n; j++)
        {
            if (marks[j] < marks[small])
                small = j;
        }
        temp = marks[i];
        marks[i] = marks[small];
        marks[small] = temp;
    }
    cout << "Selection Sort: ";
    display();
}
void Student::bubbleSort()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (marks[j] > marks[j + 1])
            {
                temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;
            }
        }
    }
    cout << "Bubble Sort: ";
    display();
}
void Student::topFive()
{
    cout << "Top five scores: ";
    for (int i = n - 1; i >= 0 && i >= n - 5; i--)
        cout << marks[i] << " ";
    cout << endl;
}
int main()
{
    Student s;
    s.create();
    cout << "\nOriginal ";
    s.display();
    s.selectionSort();
    s.bubbleSort();
    s.topFive();
    return 0;
}
