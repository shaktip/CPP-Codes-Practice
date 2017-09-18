/* The structure of the Node is */
#include<iostream>
#include<math.h>
#include<stdlib.h>



using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};

Node* insertInBST(Node *node , Node *curr)
{
    if(node == NULL)
      return curr;

    if(curr->data  < node->data)
       node->left = insertInBST(node->left , curr);
    else
       node->right = insertInBST(node->right ,  curr);
    int nlh = 0 , nrh = 0;
    if(node->left)
       nlh = node->left->height;
    if(node->right)
       nrh = node->right->height;

    node->height = max(nlh , nrh) + 1;
    return node;

}
/*You are required to complete this method */
void findLastImbalancedNode(Node *node, Node * &p)
{
    if(node == NULL || (node->left == NULL && node->right==NULL))
       return;
    int htDiff = 0;
    if(node->left && node->right == NULL)
       htDiff = node->left->height;
    else if(node->left == NULL && node->right)
       htDiff = node->right->height;
    else
       htDiff = node->left->height - node->right->height;
    if(abs(htDiff) > 1 )
       p = node;
    findLastImbalancedNode(node->left , p);
    findLastImbalancedNode(node->right , p);

}
Node * findParent(Node *root, Node *p)
{
    Node *q = NULL;

    while(root)
    {
      if(root == p)
        return q;
      q = root;
      if(p->data < root->data)
        root = root->left;
      else
        root = root->right;
    }
    return q;
}
Node * rightRotation(Node *p)
{
    Node *leftRight = p->left->right;
    Node *left = p->left;
    left->right = p;
    p->left = leftRight;
    int pLH = 0 , pRH = 0, lLH = 0 , lRH = 0;
    if(p->left)
       pLH = p->left->height;
    if(p->right)
       pRH = p->right->height ;

    p->height = max(pLH , pRH) + 1;

    if(left->left)
       lLH = left->left->height ;
    if(left->right)
       lRH  = left->right->height;
    left->height = max(lLH, lRH) + 1;
    return left;
}

Node *leftRotation(Node *p)
{
    Node *rightLeft = p->right->left;
    Node *right = p->right;
    right->left = p;
    p->right = rightLeft;
    int pLH = 0 , pRH = 0 , rLH = 0 , rRH = 0;
    if(p->left)
       pLH = p->left->height;
    if(p->right)
       pRH = p->right->height ;

    p->height = max( pLH , pRH ) + 1;
    if(right->left)
       rLH = right->left->height ;
    if(right->right)
       rRH  = right->right->height;
    right->height = max(rLH, rRH) + 1;
    return right;
}
void print(Node *root)
{
    if(!root)
      return;
    print(root->left);
    cout<<"(Data = "<<root->data << ", Height = " << root->height<< ")  ";
    print(root->right);
}


Node* insertToAVL( Node* node, int data)
{
    Node *p = NULL;
    Node *curr = new Node();
    curr->data = data; curr->height = 1 ; curr->left = curr->right = NULL;
    if(node == NULL)
    {node = curr; return node;}
    node = insertInBST( node , curr);
    cout<<"\n\t  Inserted in BST Contents : " ; print(node);
    findLastImbalancedNode(node , p);

    if(p == NULL)
      return node;
    cout<<"\n\t Imbalance Node Found : " <<p->data;

    Node *parent = findParent(node , p);
    char ch1 , ch2;
    int pRH = 0 , pLH = 0;
    if(p->right)
       pRH = p->right->height;
    if(p->left)
       pLH = p->left->height;
    if(pRH > pLH )
       ch1 = 'R';
    else
       ch1 = 'L';

    Node *q;

    if(ch1 == 'R')
        q = p->right;
    else
        q = p->left;
    int qRH = 0 , qLH = 0;
    if(q->right)
       qRH = q->right->height;
    if(q->left)
       qLH = q->left->height;
    if(qRH > qLH)
        ch2 = 'R';
    else
        ch2 = 'L';

    if(parent != NULL)
       cout<<"\n\t Parent Found "<<parent->data;
    cout<<"\n\t Rotation Case is "<<ch1 << ch2;

    Node *rotationResult;
    if(ch1 == 'R' && ch2 == 'R')
       rotationResult = leftRotation(p);
    else if(ch1 == 'L' && ch2 == 'L')
       rotationResult = rightRotation(p);
    else if(ch1 == 'L' && ch2 == 'R')
    {
        rotationResult = leftRotation(p->left);
        p->left = rotationResult;
        rotationResult = rightRotation(p);
    }
    else
    {
        rotationResult = rightRotation(p->right);
        p->right = rotationResult;
        rotationResult = leftRotation(p);
    }
    if(parent)
    {
       if(p == parent->left)
         parent->left = rotationResult;
       else
         parent->right = rotationResult;
    }
    else
       node = rotationResult;



    return node;
    //Your code here
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
