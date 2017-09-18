#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void print(vector<vector<int> > v)
{
   for(int i = 0 ; i < v.size(); i++)
   {
      vector<int> p = v[i];
      cout<<p[0]<<"  "<<p[1]<<"  "<<p[2];
   }
   cout<<endl;
}
void printVector(vector<int> A)
{
   for(int i = 0  ; i < A.size() ; i++)
     cout<<"  "<<A[i];
   cout<<endl;
}
vector<vector<int> > threeSum(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin() , A.end());
    int i = 1;
    int n = A.size();
    printVector(A);
    for(int j = 1; j < n ; j++)
    {
        if(A[j] == A[j-1])
            continue;;
        A[i] = A[j];
        i++;
    }
    printVector(A);
    cout<<"Value of i = "<<i<<endl;;
     n = i;
    vector<vector<int> > v;
    for(int i = 0 ; i < n ; i ++)
    {

        int sum = -A[i];
        int left = i+1;
        int right = n - 1;
        while(left < right)
        {
            int s = A[left] + A[right];
            if(s == sum)
            {
                vector<int> p;
                p.push_back(A[i]);
                p.push_back(A[left]);
                p.push_back(A[right]);
                v.push_back(p);

                left++;
                right--;
            }
            else if(s < sum)
               left++;
            else
               right--;
        }
    }
    return v;
}

int main()
{
  int a[] = {1, -4, 0, 0, 5, -5, 1, 0, -2, 4, -4, 1, -1, -4, 3, 4, -1, -1, -3};
  int n = sizeof(a) / sizeof(a[0]);
  vector<int> p(a , a+n);
  vector<vector<int> > v = threeSum(p);
  print(v);
  return 0;
}
