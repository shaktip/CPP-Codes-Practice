#include<iostream>
#include<vector>
#include<stack>


using namespace std;

//  Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

vector<int> postorderTraversal(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> v;
    if(!A)
      return v;
    stack<TreeNode*> st;
    do
    {
        while(A != NULL)
        {
            if(A->right != NULL)
               st.push(A->right);
            st.push(A);
            A = A->left;
        }
        A = st.top();
        st.pop();
        if(A->right != NULL && st.top() == A->right)
        {
            st.pop();
            st.push(A);
            A = A->right;
        }
        else
        {
            cout<<A->val << " ";
            char x; cin>>x;
            v.push_back(A->val);
            A = NULL;
        }
    }while(!st.empty());
    return v;
}
void print(vector<int> v)
{
   int n = v.size();
   for(int i = 0 ; i < n ; i++)
     cout<<v[i]<<"  ";
   cout<<endl;
}
int main()
{
   TreeNode *root = new TreeNode(1);
   root->left = new TreeNode(2);
   root->right = new TreeNode(3);
   root->right->left = new TreeNode(4);
   root->right->left->right = new TreeNode(5);
   vector<int> v = postorderTraversal(root);
   print(v);
   return 0;
}
