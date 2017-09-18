#include<iostream>
#include<queue>


using namespace std;
struct node{
  int data;
  struct node* left;
  struct node* right;
  struct node* nextRight;
  node(int d){data = d; left = right = nextRight = NULL;}
};

void connectNodes(node *root)
{
   queue<node *> q;
   q.push(root);
   while(!q.empty())
   {
      int sz = q.size();
      for(int i = 0 ; i < sz ; i++)
      {
         node *curr = q.front(); q.pop();
         if(i < sz - 1)
           curr->nextRight = q.front();
         if(curr->left)
           q.push(curr->left);
         if(curr->right)
           q.push(curr->right);
      }
   }

}
void print(node *root)
{
     queue<node *> q;
     q.push(root);
     while(!q.empty())
     {
        int sz = q.size();
        for(int i = 0 ; i < sz ; i++)
        {
          node *curr = q.front() ; q.pop();
          cout<<" Curr Node = "<<curr->data;
          if(curr->nextRight)
            cout<<" Its right is = "<<curr->nextRight->data;
          else
            cout<<" Null";
          cout<<endl;
          if(curr->left)
            q.push(curr->left);
          if(curr->right)
            q.push(curr->right);
        }
     }
}
int main()
{
  node *root = new node(1);

  root->left = new node(2);

  root->right = new node(3);

  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right->left = new node(6);
  root->right->right = new node(7);
  root->left->left->left = new node(8);
  root->left->left->right = new node(9);
  root->right->right->left = new node(10);
  root->right->right->right = new node(11);

  connectNodes(root);
  print(root);

  return 0;
}
