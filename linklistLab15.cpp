#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void insert(Node *head, int data)
{

    while (head->next != nullptr)
    {
        head = head->next;
    }

    head->next = new Node;
    head->next->data = data;
    head->next->next = nullptr;
}

void display(Node *head)
{

    while (head->next != nullptr)
    {
        cout << head->next->data << " ";
        head = head->next;
    }
    cout << endl;
}

void deleteNode(Node *head, int data)
{

    while (head->next != nullptr)
    {
        if (head->next->data == data)
        {

            head->next = head->next->next;
            return;
        }
        head = head->next;
    }
    cout << "Value not found!\n";
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main()
{
    Node *head = new Node; // Dummy head node
    head->next = nullptr;

    cout << "Enter elements to insert (-1 to stop): ";
    int num;
    while (cin >> num && num != -1)
    {
        insert(head, num);
    }

    int choice, data;

    while (true)
    {
       // clearScreen();
        cout << "Menu:\n";
        cout << "1. Insert More Data\n";
        cout << "2. Delete Data\n";
        cout << "3. Display List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter elements to insert (-1 to stop): ";
            while (cin >> data && data != -1)
            {
                insert(head, data);
            }
            break;

        case 2:
            cout << "Enter data to delete: ";
            cin >> data;
            deleteNode(head, data);
            break;

        case 3:
        system("cls");
            cout << "List: ";
            display(head);
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            break;

        case 4:
            cout << "Exiting program.\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
