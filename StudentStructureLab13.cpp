#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Student
{
    char name[50];
    int roll;
    float marks;
} s[100];
int n = 0;

void insert()
{
    cout << "Name: ";
    cin.ignore();
    cin.getline(s[n].name, 50);
    cout << "Roll: ";
    cin >> s[n].roll;
    cout << "Marks: ";
    cin >> s[n++].marks;
    cout << "Inserted.\n";
}

void del()
{
    int r;
    cout << "Roll to delete: ";
    cin >> r;
    for (int i = 0; i < n; i++)
    {
        if (s[i].roll == r)
        {
            for (int j = i; j < n - 1; j++)
                s[j] = s[j + 1];
            n--;
            cout << "Deleted.\n";
            return;
        }
    }
    cout << "Not found.\n";
}

void display()
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (s[i].marks < s[j].marks)
                swap(s[i], s[j]);
    for (int i = 0; i < n; i++)
        cout << s[i].name << " Roll: " << s[i].roll << " Marks: " << s[i].marks << endl;
}

int main()
{
    int ch;
    do
    {
        system("cls");
        cout << "1.Insert 2.Delete 3.Display 4.Exit\nChoice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            del();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            cout << "Invalid\n";
        }
        if (ch != 4)
        {
            cout << "\nPress any key...";
            cin.ignore();
            cin.get();
        }
    } while (ch != 4);
    return 0;
}
