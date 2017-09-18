#include<iostream>
#include<limits.h>

using namespace std;

struct Tree
{
   int data;
   struct Tree *left , *right;
   Tree(int d)
   {
      data = d;; left = NULL; right =NULL;
   }
   Tree()
   {
      data = 0 ; left = NULL ; right = NULL;
   }
};
void inorder(Tree *root)
{
   if(!root)
      return;
   inorder(root->left);
   cout<<" "<<root->data;
   inorder(root->right);
}
int findSum(Tree *root)
{
   if(!root)
      return 0;
   int leftSum = findSum(root->left);
   int rightSum = findSum(root->right);
   root->data = root->data + leftSum;
   return root->data + rightSum;
}
int findMinDepth(Tree *root, int depth)
{

    if(!root)
      return depth - 1;
    if(root->left == NULL && root->right == NULL)
      return depth;
    int l = INT_MAX, r = INT_MAX;
    if(root->left)
        l = findMinDepth(root->left , depth+1);
    if(root->right)
        r = findMinDepth(root->right , depth + 1);
    return min(l , r);
}
int main()
{
  Tree *root = new Tree(1);
  root->left = new Tree(2);
  root->right = new Tree(3);
  root->left->left = new Tree(4);
  root->left->right = new Tree(5);
  root->right->left = new Tree(6);
  root->right->right = new Tree(7);
  root->left->left->left = new Tree(8);
  root->left->right->right = new Tree(10);
  root->right->left->left = new Tree(11);
  root->left->left->right = new Tree(12);



  cout<<"\n\t";
  inorder(root);
  findSum(root);
  cout<<"\n\t";
  inorder(root);
  cout<<"\n\tMinimum depth is = ";
  cout<<findMinDepth(root , 1);
  return 0;
}
