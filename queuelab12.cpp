#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int front = -1, rear = -1;

class QUEUE
{
public:
    int queue[N];

    void enqueue(int data)
    {
        if (rear == N - 1)
            cout << "Queue Overflow\n";
        else {
            if (front == -1) front = 0;
            rear++;
            queue[rear] = data;
            cout << "Enqueued " << data << " into queue.\n";
        }
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
            cout << "Queue Underflow\n";
        else {
            cout << "Dequeued " << queue[front] << " from queue.\n";
            front++;
        }
    }

    void peek()
    {
        if (front == -1 || front > rear)
            cout << "Queue is empty\n";
        else
            cout << "Front element: " << queue[front] << "\n";
    }

    void display()
    {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue from front to rear:\n";
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
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
    QUEUE q;
    int choice, data;

    while (true)
    {
        clearScreen();
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> data;
            q.enqueue(data);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
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
