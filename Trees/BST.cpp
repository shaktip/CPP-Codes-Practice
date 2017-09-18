#include<iostream>
#include<queue>
#include<vector>
#include<stack>

using namespace std;

struct node
{
   int data;
   struct node *left, *right;
   node(int d)
   {
      data = d;
      left = NULL;
      right = NULL;
   }
   node()
   {
      data = 0;
      left = NULL;
      right = NULL;
   }
};

void MirrorImage(node *root)
{
   if(!root)
     return ;
   MirrorImage(root->left);
   MirrorImage(root->right);
   swap(root->left, root->right);
}

void printLevelWise(node *root)
{
  queue<node *> q;
  q.push(root);
  while(!q.empty())
  {
      node *r = q.front();
      q.pop();
      cout<<" "<<r->data;
      if(r->left)
         q.push(r->left);
      if(r->right)
         q.push(r->right);
  }
}
void printPath(vector<int> v)
{
   cout<<"\n\t";
   for(vector<int> :: iterator itr = v.begin() ; itr != v.end() ; itr++)
     cout<<*itr;
}

void printAllPathsRec(node *root, vector<int> path)
{
    if(!root)
       return ;
    vector<int> v(path);
    v.push_back(root->data);
    printAllPathsRec(root->left  , v);
    if(root->left == NULL && root->right == NULL)
      printPath(v);
    printAllPathsRec(root->right , v);

}
void countLeafNodes(node *root, int *cnt)
{
   if(!root)
     return ;
   countLeafNodes(root->left , cnt);
   if(!root->left && !root->right)
      (*cnt)++;
   else
      countLeafNodes(root->right , cnt);
}
void manageChildData(node *root, int diff)
{
   if(!root)
     return ;
   if(root->left == NULL && root->right == NULL)
     return;

   if(root->left)
   {
     root->left->data = root->left->data + diff;

     manageChildData(root->left, diff);
   }
   else
   {
      root->right->data = root->right->data + diff;
      manageChildData(root->right, diff);
   }
}
void maintainSumProperty(node *root)
{
   if(!root)
     return ;
   if(root->left == NULL && root->right == NULL)
     return;
   maintainSumProperty(root->left);
   maintainSumProperty(root->right);
   int l = root->left ? root->left->data : 0;
   int r = root->right ? root->right->data : 0;
   if(root->data == (l + r))
      return;
   int diff = root->data - (l+r);
   if(diff < 0)
      root->data = root->data + (-diff);
   else
      manageChildData(root, diff);
}

void printAllPaths(node *root)
{
   vector<int> path;
   printAllPathsRec(root, path);

}
void DuplicateTheTree(node *root)
{
    if(!root)
      return;
    DuplicateTheTree(root->left);
    DuplicateTheTree(root->right);

    node *newNode = new node(root->data);
    newNode->left = root->left;
    newNode->right = NULL;
    root->left = newNode;
}
void iterativePre(node *root)
{
  stack<node *> s;
  s.push(root);
  node *p = s.top();
  s.pop();
  while(!s.empty() || p != NULL)
  {

    while(p != NULL)
    {
        cout<<" "<<p->data;
        s.push(p);
        p = p->left;
    }
    if(!s.empty())
    {
       p = s.top();
       s.pop();
       p = p->right;
    }
  }
}
void iterativeIn(node *root)
{
   stack<node *> s;
   s.push(root);
   node *p = s.top();
   s.pop();
   while(!s.empty() || p != NULL)
   {
       while(p != NULL)
       {
           s.push(p);
           p = p->left;
       }
       if(!s.empty())
       {
          p = s.top();
          s.pop();
          cout<<"  "<<p->data;
          p = p->right;
       }
   }
}
void iterativePost(struct *root)
{
}
int main()
{
   node *root;
   root = new node(1);
   node *l = new node(2);
   l->left = new node(4);
   l->right = new node(5);
   root->left = l;

   root->right = new node(3);
   //root->right->left = new node(1);
   //root->right->right = new node(30);

   cout<<"\n\tOriginal Image :";
   printLevelWise(root);

   //MirrorImage(root);
   //cout<<"\n\tMirror Image :";
   //printLevelWise(root);
   //cout<<"All Paths";
   //printAllPaths(root);
   //int cnt = 0;
   //countLeafNodes(root, &cnt);
   //cout<<"Number of leaf nodes = " << cnt;
   //cout<<"\n\t After sum property : ";
   //maintainSumProperty(root);
   //cout<<"\n\tAfter duplicate = ";
   //DuplicateTheTree(root);
   //printLevelWise(root);
   cout<<"\n\t Preorder sequence = ";
   iterativePre(root);
   cout<<"\n\t Inorder sequence =";
   iterativeIn(root);

   return 0;
}
