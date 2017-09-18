#include<iostream>

using namespace std;
struct BT
{
  int data;
  struct BT *left , *right;
  BT(int d){data = d ; left = right = NULL;}
};

void print(struct BT *root , int sum , int &total)
{
    if(!root->left && !root->right)
    {  cout<<"Sum is ="<<sum<<endl;
       total = total + sum;
       return;}
    if(root->left)
      print(root->left , sum*10 + root->left->data , total);
    if(root->right)
      print(root->right , sum*10 + root->right->data , total);
}
int main()
{
   struct BT *root = new BT(6);
   root->left = new BT(3);
   root->right = new BT(5);
   root->left->left = new BT(2);
   root->left->right = new BT(5);
   root->left->right->left = new BT(7);
   root->left->right->right = new BT(4);
   root->right->right = new BT(4);
   int total = 0;
   print(root , root->data , total);
   cout<<"Total is  "<<total;
   return 0;
}
