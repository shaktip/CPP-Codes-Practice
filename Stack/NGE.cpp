#include<iostream>
#include<stack>


using namespace std;

void nextGreaterElement(int a[] , int N , int S[])
{
   stack<int> stk;

   for(int i = 0 ; i < N ; i++)
      S[i] = N;

   for(int i = N -1 ; i >= 0 ; i--)
   {

       while(!stk.empty() && a[stk.top()] < a[i])
          stk.pop();
       if(!stk.empty())
          S[i] = stk.top();
       stk.push(i);
   }

}
void printArray(int S[] , int N)
{
   cout<<"Array is =  ";
   for(int i = 0  ; i < N ;i++ )
     cout<<"  "<<S[i];
}
int main()
{
  int a[]= {10, 20, 30, 50, 10, 70, 30};
  int N = sizeof(a) / sizeof(int);
  int S[N];
  nextGreaterElement(a , N , S);
  printArray(S , N);
  return 0;
}
