#include <iostream>
using namespace std;

class CircularQueue
{
    int pizza[100];
    int front, rear, m;

public:
    CircularQueue();
    void create();
    void enqueue();
    void dequeue();
    void display();
};

CircularQueue::CircularQueue()
{
    front = -1;
    rear = -1;
}

void CircularQueue::create()
{
    do
    {
        cout << "Enter maximum number of orders (1-100): ";
        cin >> m;
    } while (m < 1 || m > 100);
}

void CircularQueue::enqueue()
{
    int order;

    if ((rear + 1) % m == front)
    {
        cout << "Queue is Full." << endl;
        return;
    }

    cout << "Enter Pizza Order ID: ";
    cin >> order;

    if (front == -1)
        front = 0;

    rear = (rear + 1) % m;
    pizza[rear] = order;

    cout << "Order Added Successfully." << endl;
}

void CircularQueue::dequeue()
{
    if (front == -1)
    {
        cout << "Queue is Empty." << endl;
        return;
    }

    cout << "Completed Order: " << pizza[front] << endl;

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        front = (front + 1) % m;
}

void CircularQueue::display()
{
    if (front == -1)
    {
        cout << "Queue is Empty." << endl;
        return;
    }

    cout << "Pizza Orders: ";

    int i = front;

    while (true)
    {
        cout << pizza[i] << " ";

        if (i == rear)
            break;

        i = (i + 1) % m;
    }

    cout << endl;
}

int main()
{
    CircularQueue q;
    int choice;

    q.create();

    do
    {
        cout << "\n1. Add Pizza Order";
        cout << "\n2. Complete Pizza Order";
        cout << "\n3. Display Orders";
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
