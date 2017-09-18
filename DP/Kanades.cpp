#include<iostream>
#include<limits.h>

using namespace std;
int maxSubArraySum(int arr[] , int n)
{
   int curr_sum = 0;
   int max_so_far = INT_MIN;
   int startIndex = 0 , endIndex = 0;
   int start = 0;
   for(int i = 0 ; i < n ; i++)
   {
     curr_sum = max(arr[i] , curr_sum+arr[i]);
     if(max_so_far < curr_sum)
     {
         max_so_far = curr_sum;
         endIndex = i; start = startIndex;
     }
     if(curr_sum < 0)
     {
        curr_sum = 0;
        startIndex = i+1;
     }

   }
   cout<<"StartIndex = "<<start << " End Index = "<<endIndex<<endl;;
   return max_so_far;
}
int main()
{
    int a[] = {-2, 2, -4, -3, -2, -1, -5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout<<max_sum;
    return 0;
}
