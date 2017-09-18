#include<iostream>
using namespace std;
struct Node
{
   int data;
   Node *left, *right;
   Node(int d)
   {
      data = d; left = right = NULL;
   }
};
void inorder(Node *root)
{
   if(!root)
     return;
   inorder(root->left);
   cout<<"  "<<root->data;
   inorder(root->right);
}
Node* createBT(int arr[] , int n)
{
  static int pos = 0;
  if(pos >= n || arr[pos] == -1 )
    return NULL;
  Node *p = new Node(arr[pos++]);
  p->left = createBT(arr ,  n);
  pos++;
  p->right = createBT(arr ,  n);
  return p;

}

void preorder(struct Node *root1, struct Node* root2, int lvl)
{
    // Base cases
    if (root1 == NULL || root2==NULL)
        return;

    // Swap subtrees if level is even
    if (lvl%2 == 0)
        swap(root1->key, root2->key);

    // Recur for left and right subtrees (Note : left of root1
    // is passed and right of root2 in first call and opposite
    // in second call.
    preorder(root1->left, root2->right, lvl+1);
    preorder(root1->right, root2->left, lvl+1);
}

// This function calls preorder() for left and right children
// of root
void reverseAlternate(struct Node *root)
{
   preorder(root->left, root->right, 0);
}

int main()
{
   int arr[] = {20, 8, 4, -1, -1, 12, 10, -1, -1, 14, -1, -1, 23, 56, -1,-1,-1};
   int n = sizeof(arr) / sizeof(arr[0]);
   struct Node *root = NULL;
   root = createBT(arr ,  n);
   inorder(root);
   return 0;
}
