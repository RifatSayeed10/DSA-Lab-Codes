#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

node *insert(node *root, int data)
{
    if (root == NULL)
        return new node(data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else if (data < root->data)
        root->left = insert(root->left, data);
    return root;
}

bool search(node *root, int val)
{
    if (root == NULL)
        return false;
    else if (root->data == val)
    {
        return true;
        
    }

    else if (val > root->data)
        return search(root->right, val);
    else
        return search(root->left, val);
}
node *minValue(node *root)
{
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
node *deleteb(node *root, int data)
{
    if (root == NULL)
        return root;
    else if (data > root->data)
        root->right = deleteb(root->right, data);
    else if (data < root->data)
        root->left = deleteb(root->left, data);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        if (!root->left)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        int mini = minValue(root->right)->data;
        root->data = mini;
        root->right = deleteb(root->right, mini);
    }
    return root;
}

void preorder(node *root)
{
    if (root)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root)
{
    if (root)
    {

        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void inorder(node *root)
{
    if (root)
    {

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void display(node *root)
{
    cout << "inorder:";
    inorder(root);
    cout << "\npreorder:";
    preorder(root);
    cout << "\npostorder:";
    postorder(root);
    cout << "\n";
}

int main()
{
    node *root = NULL;

    int choice;

    while (true)
    {
        cout << "---------MENU-----------\n";
        cout << "1.input\n";
        cout << "2.search\n";
        cout << "3.delete\n";
        cout << "4.display\n";
        cout<<"5.exit\n";
        cout<<"Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter tree elements: ";
            int num;

            while (cin >> num && num != -1)
            {
                root = insert(root, num);
            }

            break;
        case 2:
            int data;
            cin >> data;
            search(root, data);
            if (search(root, data))
                cout << "Data found in BST\n";
            else
                cout << "Data not found in BST\n";
            break;
        case 3:
            int valu;
            cin >> valu;
            deleteb(root, valu);
            cout << "deleted successfully\n";
            break;
        case 4:
            system("cls");
            display(root);
            break;
        case 5:
            cout << "exit\n";
            return 0;
        default:
            cout << "invalid choice\n";
        }
    }
    return 0;
}
