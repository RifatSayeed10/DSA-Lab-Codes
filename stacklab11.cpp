#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int top = -1;

class STACK
{
public:
    int stack[N];

    void push(int data)
    {
        if (top == N - 1)
            cout << "Stack Overflow\n";
        else {
            top++;
            stack[top] = data;
            cout << "Pushed " << data << " onto stack.\n";
        }
    }

    void pop()
    {
        if (top == -1)
            cout << "Stack Underflow\n";
        else {
            cout << "Popped " << stack[top] << " from stack.\n";
            top--;
        }
    }

    void peek()
    {
        if (top == -1)
            cout << "Stack is empty\n";
        else
            cout << "Top element: " << stack[top] << "\n";
    }

    void display()
    {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack from top to bottom:\n";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << endl;
    }
};

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
    STACK s;
    int choice, data;

    while (true)
    {
        clearScreen();
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> data;
            s.push(data);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.display();
            break;
        case 5:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice\n";
        }

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }

    return 0;
}
