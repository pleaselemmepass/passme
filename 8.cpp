#include <iostream>
using namespace std;

class Queue
{
    int job[100];
    int front, rear;

public:
    Queue();

    void enqueue();
    void dequeue();
    void display();
};

Queue::Queue()
{
    front = -1;
    rear = -1;
}

void Queue::enqueue()
{
    int id;

    if (rear == 99)
    {
        cout << "Queue is Full." << endl;
        return;
    }

    cout << "Enter Job ID: ";
    cin >> id;

    if (front == -1)
        front = 0;

    job[++rear] = id;

    cout << "Job Added Successfully." << endl;
}

void Queue::dequeue()
{
    if (front == -1)
    {
        cout << "Queue is Empty." << endl;
        return;
    }

    cout << "Deleted Job: " << job[front] << endl;
    front++;

    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

void Queue::display()
{
    if (front == -1)
    {
        cout << "Queue is Empty." << endl;
        return;
    }

    cout << "Jobs in Queue: ";

    for (int i = front; i <= rear; i++)
        cout << job[i] << " ";

    cout << endl;
}

int main()
{
    Queue q;
    int choice;

    do
    {
        cout << "\n1. Add Job";
        cout << "\n2. Delete Job";
        cout << "\n3. Display Jobs";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                q.enqueue();
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid Choice.";
        }

    } while (choice != 4);

    return 0;
}
