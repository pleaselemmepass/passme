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
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (top == 99)
            return true;
        else
            return false;
    }
    void push(char x)
    {
        if (isFull())
            cout << "Stack is Full";
        else
        {
            top++;
            a[top] = x;
        }
    }
    char pop()
    {
        if (isEmpty())
            return '\0';
        else
        {
            char x = a[top];
            top--;
            return x;
        }
    }
    void check(string str)
    {
        char x;
        bool valid = true;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            {
                push(str[i]);
            }
            else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
            {
                if (isEmpty())
                {
                    valid = false;
                    break;
                }
                x = pop();
                if ((str[i] == ')' && x != '(') ||
                    (str[i] == '}' && x != '{') ||
                    (str[i] == ']' && x != '['))
                {
                    valid = false;
                    break;
                }
            }
        }
        if (!isEmpty())
            valid = false;
        if (valid)
            cout << "Expression is Well Parenthesized";
        else
            cout << "Expression is Not Well Parenthesized";
    }
};
int main()
{
    Stack s;
    string str;
    cout << "Enter expression: ";
    cin >> str;
    s.check(str);
    return 0;
}
