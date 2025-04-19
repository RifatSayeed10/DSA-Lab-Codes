#include <iostream>
using namespace std;

class BinaryTree
{
private:
    int *tree;
    int size;
    int capacity;

public:
    // Constructor to initialize the binary tree
    BinaryTree(int cap)
    {
        capacity = cap;
        tree = new int[capacity];
        size = 0;
    }

    // Destructor to free the memory
    ~BinaryTree()
    {
        delete[] tree;
    }

    // Insert an element into the binary tree
    void insert(int val)
    {
        if (size < capacity)
        {
            tree[size++] = val;
        }
        else
        {
            cout << "Tree is full, can't insert more elements!" << endl;
        }
    }

    // Display the tree in sequential representation
    void display()
    {
        cout << "Tree elements in sequential form: ";
        for (int i = 0; i < size; i++)
        {
            cout << tree[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    BinaryTree bt(7); // Binary tree with capacity for 7 nodes

    // Insert nodes into the binary tree
    bt.insert(1); // Root
    bt.insert(2); // Left child of 1
    bt.insert(3); // Right child of 1
    bt.insert(4); // Left child of 2
    bt.insert(5); // Right child of 2
    bt.insert(6); // Left child of 3
    bt.insert(7); // Right child of 3

    // Display the tree elements in sequential form (array representation)
    bt.display();

    return 0;
}
