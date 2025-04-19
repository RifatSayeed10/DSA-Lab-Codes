#include <iostream>
using namespace std;

class PriorityQueue {
    int* arr;
    int size;
    int capacity;

public:
    PriorityQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        size = 0;
    }

    ~PriorityQueue() {
        delete[] arr;
    }

    // Insert an element in the priority queue
    void insert(int val) {
        if (size < capacity) {
            arr[size++] = val;
            // Sorting to maintain priority (Highest value first)
            for (int i = size - 1; i > 0 && arr[i] > arr[i - 1]; --i)
                swap(arr[i], arr[i - 1]);
        }
    }

    // Remove the highest priority element
    void remove() {
        if (size > 0) {
            for (int i = 0; i < size - 1; ++i)
                arr[i] = arr[i + 1];
            --size;
        }
    }

    // Display the current elements of the priority queue
    void display() {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq(5);
    pq.insert(10);
    pq.insert(30);
    pq.insert(20);
    pq.display();  // Output: 30 20 10

    pq.remove();
    pq.display();  // Output: 20 10

    return 0;
}
