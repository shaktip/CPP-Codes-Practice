#include <iostream>

using namespace std;
struct BST
{
    int data;
    struct BST *left , *right;
    BST(int d) {data = d ;  left = right = NULL;}
    BST() {data = 0 ; left  = right = NULL;}
};
void pre(BST *root)
{
    if(!root)
      return;
    cout<<root->data<<" ";
    pre(root->left);
    pre(root->right);
}
BST* constructBST(int a[]  , int start , int end)
{
    cout<<"start "<<start<<" end "<<end<<endl;;
    if(start > end)
      return NULL;
    if(start == end)
       return new BST(a[start]);
    int mid = start + (end - start + 1) / 2;
    BST *root = new BST(a[mid]);
    cout<<"Created for = "<<root->data;
    char ch; cin>>ch;
    root->left = constructBST(a , start , mid - 1);
    root->right = constructBST(a , mid + 1 , end);
    return root;
}
int main() {
	//code
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i = 0 ; i < n ; i++)
           cin>>a[i];
        BST *root = constructBST(a , 0, n-1);
        //pre(root);
        cout<<"\n";
    }
	return 0;
}
