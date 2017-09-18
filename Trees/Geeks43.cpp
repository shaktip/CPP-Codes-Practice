/*Vertical Sum of Binary Tree*/
#include<iostream>
#include<map>

using namespace std;


struct node{
  int data;
  struct node *left,*right;
  node(int d)
  {
    data  = d; left = right = NULL;
  }
  node()
  {
    data = 0 ; left = right = NULL;
  }
};

map<int , int> mp;

void createHashMap(node *root, int hd)
{
    if(!root)
       return;
    if(mp.find(hd) != mp.end())
       mp.find(hd)->second += root->data;
    else
       mp[hd] = root->data;
    createHashMap(root->left , hd - 1);
    createHashMap(root->right, hd + 1);
}

void printTree(node *root)
{
   if(!root)
     return;
   printTree(root->left);
   cout<<" " << root->data;
   printTree(root->right);
}

void printHashMap(map<int , int > mp)
{
   cout<<"\n\t Possible sums = ";
   for(map<int, int> :: iterator itr = mp.begin() ; itr != mp.end() ; itr++)
     cout<<"  "<<itr->second;
}

int main()
{
  struct node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right->left = new node(6);
  root->right->right = new node(7);
  printTree(root);

  createHashMap(root, 0);
  printHashMap(mp);
  return 0;
}


