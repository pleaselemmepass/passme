#include <iostream>
using namespace std;
class Student
{
    int roll[20], n, searchRoll;
public:
    void create();
    void display();
    void linearSearch();
    void binarySearch();
};
void Student::create()
{
    cout << "Enter number of students: ";
    cin >> n;
    cout << "Enter roll numbers: ";
    for (int i = 0; i < n; i++)
        cin >> roll[i];
}
void Student::display()
{
    cout << "Roll numbers: ";
    for (int i = 0; i < n; i++)
        cout << roll[i] << " ";
    cout << endl;
}
void Student::linearSearch()
{
    int comparisons = 0;
    bool found = false;
    cout << "Enter roll number to search: ";
    cin >> searchRoll;
    for (int i = 0; i < n; i++)
    {
        comparisons++;
        if (roll[i] == searchRoll)
        {
            found = true;
            break;
        }
    }
    if (found)
        cout << "Student found" << endl;
    else
        cout << "Student not found" << endl;
    cout << "Number of comparisons: "
         << comparisons << endl;
}
void Student::binarySearch()
{
    // Sort roll numbers
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (roll[i] > roll[j])
            {
                int temp = roll[i];
                roll[i] = roll[j];
                roll[j] = temp;
            }
        }
    }
    int first = 0, last = n - 1, middle;
    int comparisons = 0;
    bool found = false;
    cout << "Enter roll number to search: ";
    cin >> searchRoll;
    while (first <= last)
    {
        middle = (first + last) / 2;
        comparisons++;
        if (roll[middle] == searchRoll)
        {
            found = true;
            break;
        }
        else if (searchRoll < roll[middle])
            last = middle - 1;
        else
            first = middle + 1;
    }
    if (found)
        cout << "Student found" << endl;
    else
        cout << "Student not found" << endl;
    cout << "Number of comparisons: "
         << comparisons << endl;
}
int main()
{
    Student s;
    s.create();
    s.display();
    cout << "\n--- Linear Search ---\n";
    s.linearSearch();
    cout << "\n--- Binary Search ---\n";
    s.binarySearch();
    return 0;
}
