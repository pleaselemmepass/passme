#include <iostream>
using namespace std;
class Node
{
public:
    int prn;
    string name;
    Node *link;
    Node(int p, string n)
    {
        prn = p;
        name = n;
        link = NULL;
    }
};
class MemberList
{
    Node *start;
public:
    MemberList()
    {
        start = NULL;
    }
    // 1. Add at beginning
    void addFirst(int p, string n)
    {
        Node *newnode = new Node(p, n);
        newnode->link = start;
        start = newnode;
        cout << "Member added." << endl;
    }
    // 2. Add at end
    void addLast(int p, string n)
    {
        Node *newnode = new Node(p, n);
        if (start == NULL)
        {
            start = newnode;
        }
        else
        {
            Node *temp = start;
            while (temp->link != NULL)
            {
                temp = temp->link;
            }
            temp->link = newnode;
        }
        cout << "Member added." << endl;
    }
    // 3. Add after given PRN
    void addAfter(int key, int p, string n)
    {
        Node *temp = start;
        while (temp != NULL && temp->prn != key)
        {
            temp = temp->link;
        }
        if (temp == NULL)
        {
            cout << "PRN not found." << endl;
            return;
        }
        Node *newnode = new Node(p, n);
        newnode->link = temp->link;
        temp->link = newnode;
        cout << "Member added." << endl;
    }
    // 4. Delete first member
    void removeFirst()
    {
        if (start == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = start;
        start = start->link;
        delete temp;
        cout << "First member deleted." << endl;
    }
    // 5. Delete last member
    void removeLast()
    {
        if (start == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
        if (start->link == NULL)
        {
            delete start;
            start = NULL;
        }
        else
        {
            Node *temp = start;
            while (temp->link->link != NULL)
            {
                temp = temp->link;
            }
            delete temp->link;
            temp->link = NULL;
        }
        cout << "Last member deleted." << endl;
    }
    // 6. Delete member using PRN
    void removeMember(int key)
    {
        if (start == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
        if (start->prn == key)
        {
            removeFirst();
            return;
        }
        Node *temp = start;
        while (temp->link != NULL && temp->link->prn != key)
        {
            temp = temp->link;
        }
        if (temp->link == NULL)
        {
            cout << "PRN not found." << endl;
            return;
        }
        Node *del = temp->link;
        temp->link = del->link;
        delete del;
        cout << "Member deleted." << endl;
    }
    // 7. Display members
    void showMembers()
    {
        if (start == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = start;
        cout << "\nPresident: " << start->name << endl;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        cout << "Secretary: " << temp->name << endl;
        cout << "\nAll Members:" << endl;
        temp = start;
        while (temp != NULL)
        {
            cout << temp->prn << " " << temp->name << endl;
            temp = temp->link;
        }
    }
    // 8. Count members
    int totalMembers()
    {
        int count = 0;
        Node *temp = start;
        while (temp != NULL)
        {
            count++;
            temp = temp->link;
        }
        return count;
    }
    // 9. Join two lists
    void joinLists(MemberList &other)
    {
        if (other.start == NULL)
        {
            cout << "Second list is empty." << endl;
            return;
        }
        if (start == NULL)
        {
            start = other.start;
        }
        else
        {
            Node *temp = start;
            while (temp->link != NULL)
            {
                temp = temp->link;
            }
            temp->link = other.start;
        }
        other.start = NULL;
        cout << "Lists joined successfully." << endl;
    }
};
int main()
{
    MemberList first, second;
    int choice, division, p, key;
    string n;
    do
    {
        cout << "\n--- CLUB MEMBER LIST ---";
        cout << "\n1. Add at Beginning";
        cout << "\n2. Add at End";
        cout << "\n3. Add After PRN";
        cout << "\n4. Delete First";
        cout << "\n5. Delete Last";
        cout << "\n6. Delete by PRN";
        cout << "\n7. Display Members";
        cout << "\n8. Count Members";
        cout << "\n9. Join Lists";
        cout << "\n10. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        if (choice >= 1 && choice <= 8)
        {
            cout << "Enter division (1 or 2): ";
            cin >> division;
        }
        switch (choice)
        {
            case 1:
                cout << "Enter PRN and Name: ";
                cin >> p >> n;
                if (division == 1)
                    first.addFirst(p, n);
                else if (division == 2)
                    second.addFirst(p, n);
                else
                    cout << "Invalid division.";
                break;
            case 2:
                cout << "Enter PRN and Name: ";
                cin >> p >> n;
                if (division == 1)
                    first.addLast(p, n);
                else if (division == 2)
                    second.addLast(p, n);
                else
                    cout << "Invalid division.";
                break;
            case 3:
                cout << "Enter existing PRN: ";
                cin >> key;
                cout << "Enter new PRN and Name: ";
                cin >> p >> n;
                if (division == 1)
                    first.addAfter(key, p, n);
                else if (division == 2)
                    second.addAfter(key, p, n);
                else
                    cout << "Invalid division.";
                break;
            case 4:
                if (division == 1)
                    first.removeFirst();
                else if (division == 2)
                    second.removeFirst();
                else
                    cout << "Invalid division.";
                break;
            case 5:
                if (division == 1)
                    first.removeLast();
                else if (division == 2)
                    second.removeLast();
                else
                    cout << "Invalid division.";
                break;
            case 6:
                cout << "Enter PRN: ";
                cin >> key;
                if (division == 1)
                    first.removeMember(key);
                else if (division == 2)
                    second.removeMember(key);
                else
                    cout << "Invalid division.";
                break;
            case 7:
                if (division == 1)
                    first.showMembers();
                else if (division == 2)
                    second.showMembers();
                else
                    cout << "Invalid division.";
                break;
            case 8:
                if (division == 1)
                    cout << "Total: " << first.totalMembers();
                else if (division == 2)
                    cout << "Total: " << second.totalMembers();
                else
                    cout << "Invalid division.";
                break;
            case 9:
                first.joinLists(second);
                break;
            case 10:
                cout << "Program terminated.";
                break;
            default:
                cout << "Invalid choice.";
        }
    } while (choice != 10);
    return 0;
}
