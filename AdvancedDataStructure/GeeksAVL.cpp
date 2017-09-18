// C program to insert a node in AVL tree
#include<iostream>
#include<stdlib.h>
using namespace std;
// An AVL tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

// A utility function to get maximum of two integers
int max(int a, int b);

// A utility function to get height of the tree
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}

/* Helper function that allocates a new node with the given data and
    NULL left and right pointers. */
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)
                        malloc(sizeof(struct Node));
    node->data   = data;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return(node);
};

void print(Node *root)
{
    if(!root)
      return;
    print(root->left);
    cout<<"(Data = "<<root->data << ", Height = " << root->height<< ")  ";
    print(root->right);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert data in subtree rooted
// with node and returns new root of subtree.
struct Node* insertToAVL(struct Node* node, int data)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(data));

    if (data < node->data)
        node->left  = insertToAVL(node->left, data);
    else if (data > node->data)
        node->right = insertToAVL(node->right, data);
    else // Equal datas are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                           height(node->right));

    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && data > node->left->data)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}


int main()
{

    Node *root = NULL;

    int arr[] = { 887, 778 ,916, 794 ,336 ,387 ,493 ,650 ,422 ,363 ,28 ,691,
     60 ,764 ,927 ,541 ,427 ,173 ,737 ,212 ,369 ,568 ,430 ,783 ,531 ,863 ,124 ,
     68 ,136 ,930 ,803, 23, 59, 70, 168, 394, 457, 12, 43, 230, 374, 422, 920,
      785 ,538 ,199 ,325 ,316 ,371 ,414, 527, 92 ,981, 957, 874 ,863 ,171 ,
997, 282 ,306 ,926 ,85 ,328, 337 ,506 ,847 ,730 ,314 ,858 ,125 ,896 ,583, 546, 815 ,368 ,435 ,365 ,44 ,751 ,88 ,809 ,277, 179, 789 };
/*
    int n = sizeof(arr) / sizeof(int);
    for(int i = 0 ; i < n ; i++)
    {
      root = insertToAVL(root , arr[i]);
      cout<<"\n\t Contents = "; print(root);
      char ch;
      cin>>ch;
    }
*/
    /*
    root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);
  */

    root = insertToAVL(root , 10);
    cout<<"\n\t Contents = "; print(root);
    root = insertToAVL(root , 20);
    cout<<"\n\t Contents = "; print(root);

    root = insertToAVL(root , 30);
    cout<<"\n\t Contents = "; print(root);
/*
    root = insertToAVL(root , 40);
    cout<<"\n\t Contents = "; print(root);

    root = insertToAVL(root , 50);
    cout<<"\n\t Contents = "; print(root);

    root = insertToAVL(root , 25);
    cout<<"\n\t Contents = "; print(root);



    //root = insertToAVL(root , 1);
    //cout<<"\n\t Contents = "; print(root);
    //root = insertToAVL(root , 0);
    //cout<<"\n\t Contents = "; print(root);
*/
    return 0;
}
