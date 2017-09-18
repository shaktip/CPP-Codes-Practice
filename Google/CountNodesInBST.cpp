#include<iostream>

using namespace std;
struct node
{
  int data;
  struct node *left, *right;
  node(int d) { data = d ; left = right = NULL;}
};
void CountNodes(struct node *root , int leftR , int rightR , int &Count)
{
   if(!root)
     return;
   if(root->data >= leftR && root->data <= rightR)
     Count++;
   if(root->data >= leftR)
     CountNodes(root->left , leftR, rightR , Count);
   if(root->data <= rightR)
     CountNodes(root->right , leftR , rightR , Count);
}
int main()
{
  struct node *root = new node(10);
  root->left = new node(5);
  root->right = new node(50);
  root->left->left = new node(1);
  root->right->left  = new node(40);
  root->right->right = new node(100);
  int leftR , rightR;
  leftR = 5; rightR = 45;
  int Count = 0;
  CountNodes(root , leftR , rightR , Count);
  cout<<"No of nodes = "<<Count;


  return 0 ;
}
