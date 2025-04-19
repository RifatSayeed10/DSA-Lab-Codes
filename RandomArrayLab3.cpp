
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int n, key, count = 0;
    cout << "Enter number of elements: ";
    cin >> n;

    srand(time(0));
    int arr[n];

    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }

    cout << "\nEnter element to search: ";
    cin >> key;

    cout << "Positions: ";
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << i << " ";
            count++;
        }
    }
    if(count == 0) {
        cout << "Element not found in the array.\n";
    } else {
        cout << "Total occurrences of " << key << ": " << count << endl;
    }

    return 0;
}
