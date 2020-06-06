#include <iostream>
#include <queue>
using namespace std;

// A Binary Tree Node
struct node
{
    int key;
    struct node *left, *right;
};

// An Iterative level order traversal based function to
// convert left-right to down-right representation.
void convert(node *root)
{
    // Base Case
    if (root == NULL)  return;

    // Recursively convert left an right subtrees
    convert(root->left);
    convert(root->right);

    // If left child is NULL, make right child as left
    // as it is the first child.
    if (root->left == NULL)
       root->left = root->right;

    // If left child is NOT NULL, then make right child
    // as right of left child
    else
       root->left->right = root->right;

    // Set root's right as NULL
    root->right = NULL;
}

// A utility function to traverse a tree stored in
// down-right form.
void downRightTraversal(node *root)
{
    if (root != NULL)
    {
        cout <<"root->info : " <<root->key << " ";
    if(root->left)
        cout<<"root->left->info : " <<root->left->key<<" ";
    if(root->right)
        cout<<"root->right->info : " <<root->right->key;
        cout<<endl;
        downRightTraversal(root->right);
        downRightTraversal(root->left);
    }
}

// Utility function to create a new tree node
node* newNode(int key)
{
    node *temp = new node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

void inorderTraversal(node *root)
{
    if(!root)
        return;
    cout <<"root->info : " <<root->key << " ";
    if(root->left)
        cout<<"root->left->info : " <<root->left->key<<" ";
    if(root->right)
        cout<<"root->right->info : " <<root->right->key;
    cout<<endl;
    inorderTraversal(root->left);
    inorderTraversal(root->right);
}

// Driver program to test above functions
int main()
{
    // Let us create binary tree shown in above diagram
    /*
           1
         /   \
        2     3
             / \
            4   5
           /   /  \
          6   7    8
    */
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->right->left->left = newNode(6);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(8);

    inorderTraversal(root);
    convert(root);

    cout << "Traversal of the tree converted to down-right form\n";
    downRightTraversal(root);

    return 0;
}
