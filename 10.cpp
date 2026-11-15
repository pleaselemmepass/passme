#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int prn;
    string name;
    Node *next;
};

class Pinnacle
{
    Node *head;

public:
    Pinnacle();

    void addPresident();
    void addSecretary();
    void addMember();

    void deletePresident();
    void deleteSecretary();
    void deleteMember();

    void display();
    void count();
    void concatenate(Pinnacle &p);
};

Pinnacle::Pinnacle()
{
    head = NULL;
}

void Pinnacle::addPresident()
{
    Node *temp = new Node;

    cout << "Enter PRN and Name: ";
    cin >> temp->prn >> temp->name;

    temp->next = head;
    head = temp;
}

void Pinnacle::addSecretary()
{
    Node *temp = new Node;

    cout << "Enter PRN and Name: ";
    cin >> temp->prn >> temp->name;

    temp->next = NULL;

    if (head == NULL)
        head = temp;
    else
    {
        Node *p = head;

        while (p->next != NULL)
            p = p->next;

        p->next = temp;
    }
}

void Pinnacle::addMember()
{
    Node *temp = new Node;

    cout << "Enter PRN and Name: ";
    cin >> temp->prn >> temp->name;

    if (head == NULL)
    {
        temp->next = NULL;
        head = temp;
    }
    else
    {
        Node *p = head;

        while (p->next != NULL && p->next->next != NULL)
            p = p->next;

        temp->next = p->next;
        p->next = temp;
    }
}

void Pinnacle::deletePresident()
{
    if (head == NULL)
    {
        cout << "List is Empty." << endl;
        return;
    }

    Node *temp = head;
    head = head->next;

    delete temp;

    cout << "President Deleted." << endl;
}

void Pinnacle::deleteSecretary()
{
    if (head == NULL)
    {
        cout << "List is Empty." << endl;
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        cout << "Secretary Deleted." << endl;
        return;
    }

    Node *p = head;

    while (p->next->next != NULL)
        p = p->next;

    delete p->next;
    p->next = NULL;

    cout << "Secretary Deleted." << endl;
}

void Pinnacle::deleteMember()
{
    int key;

    if (head == NULL || head->next == NULL ||
        head->next->next == NULL)
    {
        cout << "No ordinary members to delete." << endl;
        return;
    }

    cout << "Enter PRN to delete: ";
    cin >> key;

    Node *p = head;

    while (p->next != NULL &&
           p->next->next != NULL &&
           p->next->prn != key)
        p = p->next;

    if (p->next == NULL || p->next->next == NULL)
    {
        cout << "Member Not Found." << endl;
        return;
    }

    Node *temp = p->next;
    p->next = temp->next;

    delete temp;

    cout << "Member Deleted." << endl;
}

void Pinnacle::display()
{
    if (head == NULL)
    {
        cout << "List is Empty." << endl;
        return;
    }

    Node *p = head;

    cout << "\nPRN\tName\n";

    while (p != NULL)
    {
        cout << p->prn << "\t" << p->name << endl;
        p = p->next;
    }
}

void Pinnacle::count()
{
    int c = 0;
    Node *p = head;

    while (p != NULL)
    {
        c++;
        p = p->next;
    }

    cout << "Total Members: " << c << endl;
}

void Pinnacle::concatenate(Pinnacle &p)
{
    if (p.head == NULL)
    {
        cout << "Second List is Empty." << endl;
        return;
    }

    if (head == NULL)
    {
        head = p.head;
        p.head = NULL;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = p.head;
    p.head = NULL;
}

int main()
{
    Pinnacle divisionA, divisionB;
    int choice, division;
    Pinnacle *p;

    do
    {
        cout << "\n1. Add President";
        cout << "\n2. Add Secretary";
        cout << "\n3. Add Member";
        cout << "\n4. Delete President";
        cout << "\n5. Delete Secretary";
        cout << "\n6. Delete Member";
        cout << "\n7. Display";
        cout << "\n8. Count Members";
        cout << "\n9. Concatenate Divisions";
        cout << "\n10. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 8)
        {
            cout << "Select Division (1 or 2): ";
            cin >> division;

            if (division == 1)
                p = &divisionA;
            else if (division == 2)
                p = &divisionB;
            else
            {
                cout << "Invalid Division.";
                continue;
            }
        }

        switch (choice)
        {
        case 1:
            p->addPresident();
            break;

        case 2:
            p->addSecretary();
            break;

        case 3:
            p->addMember();
            break;

        case 4:
            p->deletePresident();
            break;

        case 5:
            p->deleteSecretary();
            break;

        case 6:
            p->deleteMember();
            break;

        case 7:
            p->display();
            break;

        case 8:
            p->count();
            break;

        case 9:
            divisionA.concatenate(divisionB);
            cout << "Divisions Concatenated." << endl;
            break;

        case 10:
            cout << "Exiting...";
            break;

        default:
            cout << "Invalid Choice.";
        }

    } while (choice != 10);

    return 0;
}
