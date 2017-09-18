#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector<int> searchRange(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int lb = lower_bound(A.begin() , A.end() , B) - A.begin();
    int ub = upper_bound(A.begin() , A.end() , B) - A.begin();
    vector<int> result;
    if(lb == 0 && A[lb] != B)
       lb = -1;
    if(ub == 0 && A[ub] != B)
       ub = -1;
    result.push_back(lb);
    result.push_back(ub - 1);
    return result;
}

int main()
{
  int a[] =  {0,1,2,4};
  int N = sizeof(a) / sizeof(a[0]);
  vector<int> A (a , a+N);
  int B = 3;
  vector<int> res = searchRange(A , B);
  cout<<res[0]<<"  "<<res[1];
  return 0;
}
