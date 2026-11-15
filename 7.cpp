#include <iostream>
#include <string>
using namespace std;

class Stack
{
    char s[100];
    int top;

public:
    Stack();

    bool isFull();
    bool isEmpty();
    void push(char ch);
    char pop();

    bool check(string str);
};

Stack::Stack()
{
    top = -1;
}

bool Stack::isFull()
{
    return top == 99;
}

bool Stack::isEmpty()
{
    return top == -1;
}

void Stack::push(char ch)
{
    if (!isFull())
        s[++top] = ch;
}

char Stack::pop()
{
    if (!isEmpty())
        return s[top--];

    return '\0';
}

bool Stack::check(string str)
{
    top = -1;

    char ch, x;

    for (int i = 0; i < str.length(); i++)
    {
        ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            if (isFull())
                return false;

            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (isEmpty())
                return false;

            x = pop();

            if (!((ch == ')' && x == '(') ||
                  (ch == '}' && x == '{') ||
                  (ch == ']' && x == '[')))
                return false;
        }
    }

    return isEmpty();
}

int main()
{
    Stack st;
    string str;

    cout << "Enter an expression: ";
    getline(cin, str);

    if (st.check(str))
        cout << "Expression is Well Parenthesized.";
    else
        cout << "Expression is Not Well Parenthesized.";

    return 0;
}
