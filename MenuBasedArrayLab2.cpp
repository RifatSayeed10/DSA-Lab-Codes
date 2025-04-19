#include <iostream>
#include <cstdlib> // For system("cls")
using namespace std;

int main() {
    const int SIZE = 100;
    int arr[SIZE], n = 0, choice, pos, value;

    // Initial array setup
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert element at a position\n";
        cout << "2. Delete element at a position\n";
        cout << "3. Display array\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter position to insert (0 to " << n << "): ";
                cin >> pos;
                if(pos < 0 || pos > n) {
                    cout << "Invalid position!\n";
                    break;
                }
                cout << "Enter value to insert: ";
                cin >> value;
                for(int i = n; i > pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = value;
                n++;
                cout << "Element inserted.\n";
                break;

            case 2:
                cout << "Enter position to delete (0 to " << n - 1 << "): ";
                cin >> pos;
                if(pos < 0 || pos >= n) {
                    cout << "Invalid position!\n";
                    break;
                }
                for(int i = pos; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
                cout << "Element deleted.\n";
                break;

            case 3:
                system("cls"); // Clear screen before displaying
                cout << "Array elements: ";
                for(int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                cout << "\n";
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while(choice != 4);

    return 0;
}
