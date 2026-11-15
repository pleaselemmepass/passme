#include <iostream>
using namespace std;
class CircularQueue
{
    int arr[10], front = -1, rear = -1;
public:
    int isempty()
    {
        if (front == -1 && rear == -1)
            return 1;
        else
            return 0;
    }
    int isfull()
    {
        if ((rear + 1) % 10 == front)
            return 1;
        else
            return 0;
    }
    void enqueue(int x)
    {
        if (isfull() == 1)
        {
            cout << "Order queue is full." << endl;
            return;
        }
        if (isempty() == 1)
        {
            front = rear = 0;
            arr[rear] = x;
        }
        else
        {
            rear = (rear + 1) % 10;
            arr[rear] = x;
        }
        cout << "Order accepted: " << x << endl;
        display();
    }
    void dequeue()
    {
        if (isempty() == 1)
        {
            cout << "No pending orders." << endl;
            return;
        }
        cout << "Order served: " << arr[front] << endl;
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % 10;
        }
        display();
    }
    void display()
    {
        if (isempty() == 1)
        {
            cout << "No orders in queue." << endl;
            return;
        }
        cout << "Orders in queue: ";
        int i = front;
        while (1)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % 10;
        }
        cout << endl;
    }
};
int main()
{
    CircularQueue q;
    int choice, order;
    do
    {
        cout << "\n--- Pizza Parlor ---" << endl;
        cout << "1. Place an order" << endl;
        cout << "2. Serve an order" << endl;
        cout << "3. Display orders" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "Enter order number: ";
                cin >> order;
                q.enqueue(order);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 4);
    return 0;
}
