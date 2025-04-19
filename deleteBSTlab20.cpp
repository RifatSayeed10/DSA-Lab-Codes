#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// Insert function for Binary Search Tree
Node *insertBst(Node *root, int val)
{
    if (root == nullptr)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insertBst(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insertBst(root->right, val);
    }
    return root;
}

// Find the inorder successor (smallest value in the right subtree)
Node *minValueNode(Node *root)
{
    Node *temp = root;
    while (temp->left != nullptr)
    {
        temp = temp->left;
    }
    return temp;
}

// Delete function for Binary Search Tree
Node *deleteBst(Node *root, int val)
{
    // base case
    if (root == nullptr)
    {
        return root;
    }
    if (val < root->data)
    {
        root->left = deleteBst(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = deleteBst(root->right, val);
    }
    else //(root data==val)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child

        // right child
        if (root->left == nullptr && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // left child
        if (root->right == nullptr && root->left != NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)

        {
            int mini = minValueNode(root->right)->data;
            root->data = mini;
            root->right = deleteBst(root->right, mini);
        }
    }
    return root;
}

// Search function for Binary Search Tree
bool searchBst(Node *root, int val)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->data == val)
    {
        return true;
    }
    if (val < root->data)
    {
        return searchBst(root->left, val);
    }
    return searchBst(root->right, val);
}

// Traversals
void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
void preorder(Node *root)
{
    if (root)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void displayTraversals(Node *root)
{
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << "\nPreorder Traversal: ";
    preorder(root);
    cout << "\nPostorder Traversal: ";
    postorder(root);
    cout << endl;
}

void clearScreen()
{
    system("cls"); // For Windows, use "clear" for Linux/Mac
}

int main()
{
    Node *root = nullptr;
    cout << "Enter tree elements separated by space (type -1 to stop): ";

    int num;
    while (cin >> num && num != -1)
    { // Read input until -1 is entered
        root = insertBst(root, num);
    }

    int choice;
    do
    {
        cout << "\nMenu:\n1. Display Traversals\n2. Search an Element\n3. Delete an Element\n4. Exit\nEnter your choice: ";
        cin >> choice;
        clearScreen();

        switch (choice)
        {
        case 1:
            displayTraversals(root);
            break;
        case 2:
            int searchValue;
            cout << "Enter value to search: ";
            cin >> searchValue;
            cout << searchValue << (searchBst(root, searchValue) ? " found" : " not found") << " in BST.\n";
            break;
        case 3:
            int deleteValue;
            cout << "Enter value to delete: ";
            cin >> deleteValue;
            root = deleteBst(root, deleteValue);
            cout << "Value deleted successfully. Press 1 to display traversals.\n";
            break;
        case 4:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
        system("pause");
    } while (choice != 4);

    return 0;
}
