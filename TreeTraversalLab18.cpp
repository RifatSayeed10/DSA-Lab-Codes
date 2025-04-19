#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize node
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Pre-order traversal (Root, Left, Right)
void preOrder(Node* root) {
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// In-order traversal (Left, Root, Right)
void inOrder(Node* root) {
    if (root == nullptr)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// Post-order traversal (Left, Right, Root)
void postOrder(Node* root) {
    if (root == nullptr)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    // Manually creating the binary tree for demonstration
    // Example Tree:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Pre-order Traversal: ";
    preOrder(root);
    cout << endl;

    cout << "In-order Traversal: ";
    inOrder(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    postOrder(root);
    cout << endl;

    return 0;
}
