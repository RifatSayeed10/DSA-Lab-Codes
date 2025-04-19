#include <iostream>
using namespace std;

int main() {
    int n, key, count = 0;

    // Input array size
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    // Input array elements
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Input element to search
    cout << "Enter the element to search: ";
    cin >> key;

    // Search for the element
    cout << "Element " << key << " found at positions: ";
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            cout << i << " ";
            count++;
        }
    }

    if(count == 0) {
        cout << "Not found in the array.\n";
    } else {
        cout << "\nTotal occurrences of " << key << ": " << count << endl;
    }

    return 0;
}
