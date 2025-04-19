#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int roll;
    float marks;

    void input() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> roll;
        cout << "Enter marks: ";
        cin >> marks;
    }

    void display() {
        cout << "Name: " << name << ", Roll: " << roll << ", Marks: " << marks << endl;
    }
};

int main() {
    const int MAX = 100;
    Student students[MAX];
    int count = 0;
    char ch;

    do {
        cout << "\n--- Student " << count + 1 << " ---\n";
        students[count].input();
        count++;

        if (count >= MAX) {
            cout << "Max student limit reached.\n";
            break;
        }

        cout << "Add another student? (y/n): ";
        cin >> ch;
    } while (ch != 'n' && ch != 'N');

    // Manual sorting by marks in descending order
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (students[i].marks < students[j].marks) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    // Display sorted list
    cout << "\n--- Students Sorted by Marks (Descending) ---\n";
    for (int i = 0; i < count; i++) {
        students[i].display();
    }

    return 0;
}
