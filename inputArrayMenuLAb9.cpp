#include <iostream>
#include <cstdlib> // for system("cls")
using namespace std;

const int MAX = 100;

void displayArray(int arr[], int size) {
    cout << "Current Array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[MAX], n = 0, data;

    cout << "Enter sorted elements (-1 to stop):\n";
    while (n < MAX) {
        cin >> data;
        if (data == -1) break;
        arr[n++] = data;
    }

    int choice;
    do {
        system("cls"); // Clear the screen

        cout << "--- Menu ---\n";
        cout << "1. Insert element at position\n";
        cout << "2. Delete element at position\n";
        cout << "3. Display array\n";
        cout << "4. Exit\n";
        displayArray(arr, n);
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (n == MAX) {
                    cout << "Array is full!\n";
                    break;
                }

                int pos, val;
                cout << "Enter position (0 to " << n << "): ";
                cin >> pos;
                if (pos < 0 || pos > n) {
                    cout << "Invalid position!\n";
                    break;
                }
                cout << "Enter value to insert: ";
                cin >> val;

                for (int i = n; i > pos; i--)
                    arr[i] = arr[i - 1];
                arr[pos] = val;
                n++;
                break;
            }

            case 2: {
                int pos;
                cout << "Enter position to delete (0 to " << n - 1 << "): ";
                cin >> pos;
                if (pos < 0 || pos >= n) {
                    cout << "Invalid position!\n";
                    break;
                }

                for (int i = pos; i < n - 1; i++)
                    arr[i] = arr[i + 1];
                n--;
                break;
            }

            case 3:
                displayArray(arr, n);
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

        if (choice != 4) {
            cout << "\nPress any key to continue...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 4);

    return 0;
}
