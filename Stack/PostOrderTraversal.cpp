#include<iostream>
#include<stack>

using namespace std;
struct Tree
{
  int data;
  struct Tree *left , *right;
  Tree(int d)
  {
     data = d ; left = NULL ; right = NULL;
  }
};

void postTraversal(struct Tree *root)
{
    stack<struct Tree *> stk;

    do
    {
       if(root != NULL)
       {
        if(root->right != NULL)
           stk.push(root->right);
        stk.push(root);
        root = root->left;
       }
       else if(!stk.empty())
       {
          struct Tree *temp = stk.top();
          stk.pop();
          if(temp->right && !stk.empty())
          {
             if(temp->right != stk.top())
             {
                cout<<temp->data<<"  ";
                root = NULL;
             }
             else
             {
                struct Tree *y = stk.top();
                stk.pop();
                stk.push(temp);
                root = y;
             }
          }
          else
          {
             cout<<temp->data<<"  ";
             root = NULL;
          }
       }

    }while(!stk.empty());
}

int main()
{
   struct Tree *root = new Tree(1);
   root->left = new Tree(2);
   root->left->left = new Tree(4);
   root->left->right = new Tree(5);
   root->right = new Tree(3);
   root->right->left = new Tree(6);
   root->right->right = new Tree(7);
   postTraversal(root);
   return 0;
}
