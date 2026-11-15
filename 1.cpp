#include <iostream>
#include <string>
using namespace std;

class stringops
{
    string name;

public:
    void create();
    void display();
    void longestlen();
    void freq();
    void palindrome();
    void substring();
    void wordfrequency();
};

void stringops::create()
{
    cout << "Please enter a string: ";
    getline(cin, name);
}

void stringops::display()
{
    cout << "The string entered is: " << name << endl;
}

void stringops::longestlen()
{
    string word = "", longest = "";

    for (int i = 0; i <= name.length(); i++)
    {
        if (i < name.length() && name[i] != ' ')
            word += name[i];
        else
        {
            if (word.length() > longest.length())
                longest = word;

            word = "";
        }
    }

    cout << "Longest word is: " << longest << endl;
}

void stringops::freq()
{
    char ch;
    int count = 0;

    cout << "Enter the character to search: ";
    cin >> ch;

    for (int i = 0; i < name.length(); i++)
    {
        if (name[i] == ch)
            count++;
    }

    cout << "Frequency of " << ch << " is: " << count << endl;
}

void stringops::palindrome()
{
    string rev = "";

    for (int i = name.length() - 1; i >= 0; i--)
        rev += name[i];

    if (name == rev)
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;
}

void stringops::substring()
{
    string sub;
    int j;

    cout << "Enter the substring: ";
    cin >> sub;

    for (int i = 0; i < name.length(); i++)
    {
        j = 0;

        while (j < sub.length() &&
               i + j < name.length() &&
               name[i + j] == sub[j])
        {
            j++;
        }

        if (j == sub.length())
        {
            cout << "Substring found at index: " << i << endl;
            return;
        }
    }

    cout << "Substring not found." << endl;
}

void stringops::wordfrequency()
{
    string word[100], temp = "";
    int count[100], n = 0;

    for (int i = 0; i <= name.length(); i++)
    {
        if (i < name.length() && name[i] != ' ')
            temp += name[i];
        else if (temp != "")
        {
            int j;

            for (j = 0; j < n; j++)
            {
                if (word[j] == temp)
                {
                    count[j]++;
                    break;
                }
            }

            if (j == n)
            {
                word[n] = temp;
                count[n] = 1;
                n++;
            }

            temp = "";
        }
    }

    cout << "\nWord Frequencies:\n";

    for (int i = 0; i < n; i++)
        cout << word[i] << " : " << count[i] << endl;
}

int main()
{
    stringops s;

    s.create();
    s.longestlen();
    s.display();
    s.freq();
    s.palindrome();
    s.substring();
    s.wordfrequency();

    return 0;
}
    