#include <iostream>
using namespace std;
class Queue
{
    int arr[100];
    int front, rear;
public:
    Queue()
    {
        front = rear = -1;
    }
    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (rear == 99)
            return true;
        else
            return false;
    }
    void enqueue(int x)
    {
        if (isFull())
            cout << "Queue Overflow" << endl;
        else
        {
            if (front == -1)
                front = 0;
            rear++;
            arr[rear] = x;
            cout << "Job Inserted" << endl;
        }
    }
    void dequeue()
    {
        if (isEmpty())
            cout << "Queue Underflow" << endl;
        else
        {
            cout << "Deleted Job: " << arr[front] << endl;
            if (front == rear)
                front = rear = -1;
            else
                front++;
        }
    }
    void display()
    {
        if (isEmpty())
            cout << "Queue is Empty" << endl;
        else
        {
            cout << "Queue: ";
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};
int main()
{
    Queue q;
    int choice, x;
    do
    {
        cout << "\n1. Add Job";
        cout << "\n2. Delete Job";
        cout << "\n3. Display Queue";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Job ID: ";
            cin >> x;
            q.enqueue(x);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exit";
            break;
        default:
            cout << "Invalid Choice";
        }
    } while (choice != 4);
    return 0;
}
