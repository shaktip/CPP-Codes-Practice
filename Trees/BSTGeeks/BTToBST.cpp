// The Node structure is
#include<iostream>
#include<algorithm>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int d){data = d; left = right = NULL;}
};

/*Your code here*/
#define MAX 21
void getArray(Node *root , int *arr , int &n)
{
    if(!root)
      return;
    getArray(root->left , arr , n);
    arr[n++] = root->data;
    getArray(root->right , arr , n);
}
void TraverseAndFill(Node *root , int *arr)
{
    static int index = 0;
    if(!root)
       return;
    TraverseAndFill(root->left , arr);
    root->data = arr[index++];
    TraverseAndFill(root->right , arr);
}
int compare(const void *a, const void *b)
{
  return *(int *)a > *(int *)b;
}
Node *binaryTreeToBST (Node *root)
{
    int *a = new int[MAX];
    int n = 0;
    getArray(root , a , n);
    qsort(a, n , sizeof(int) , compare);
    TraverseAndFill(root , a);
    return root;
//Your code here
}

void display(Node *root)
{
   if(!root)
      return;
   display(root->left);
   cout<<root->data<<" ";
   display(root->right);
}
int main()
{
   Node *root = new Node(10);
   root->left = new Node(20);
   root->right = new Node(30);
   root->left->left = new Node(40);
   root->left->right = new Node(60);
   display(root);
   root = binaryTreeToBST(root);
   cout<<"\n";
   display(root);
   return 0;
}
