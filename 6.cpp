#include <iostream>
#include <string>
using namespace std;
class Stack
{
    char a[100];
    int top;
public:
    Stack()
    {
        top = -1;
    }
    int isEmpty()
    {
        if (top == -1)
            return 1;
        else
            return 0;
    }
    int isFull()
    {
        if (top == 99)
            return 1;
        else
            return 0;
    }
    void push(char x)
    {
        if (isFull())
            cout << "Stack Overflow\n";
        else
        {
            top++;
            a[top] = x;
        }
    }
    char pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow\n";
            return '\0';
        }
        else
        {
            char x = a[top];
            top--;
            return x;
        }
    }
    void display()
    {
        if (isEmpty())
            cout << "Stack is Empty";
        else
        {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--)
                cout << a[i] << " ";
        }
        cout << endl;
    }
    void reverseString(string str)
    {
        Stack s;
        for (int i = 0; i < str.length(); i++)
        {
            s.push(str[i]);
        }
        cout << "Reverse String: ";
        while (s.isEmpty() == 0)
        {
            cout << s.pop();
        }
        cout << endl;
    }
    void palindrome(string str)
    {
        Stack s;
        for (int i = 0; i < str.length(); i++)
        {
            s.push(str[i]);
        }
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != s.pop())
            {
                cout << "Not Palindrome";
                return;
            }
        }
        cout << "Palindrome";
    }
};
int main()
{
    Stack s;
    int ch;
    char x;
    string str;
    do
    {
        cout << "\n\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Display";
        cout << "\n4. Reverse String";
        cout << "\n5. Palindrome";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> ch;
        switch (ch)
        {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                s.push(x);
                break;
            case 2:
                cout << "Pop = " << s.pop();
                break;
            case 3:
                s.display();
                break;
            case 4:
                cout << "Enter string: ";
                cin >> str;
                s.reverseString(str);
                break;
            case 5:
                cout << "Enter string: ";
                cin >> str;
                s.palindrome(str);
                break;
            case 6:
                cout << "Exit";
                break;
            default:
                cout << "Invalid choice";
        }
    } while (ch != 6);
    return 0;
}
