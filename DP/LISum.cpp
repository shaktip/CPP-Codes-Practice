#include<iostream>
#include<limits.h>

using namespace std;

int maxSumIS(int arr[] , int n)
{
   int sum[n];
   for(int i = 0 ; i < n ; i++)
     sum[i] = arr[i];

   for(int i = 1 ; i < n ; i++)
   {
      for(int j = 0 ; j < i ; j++)
      {
          if(arr[j] < arr[i] && sum[i] < arr[i] + sum[j])
             sum[i] = arr[i] + sum[j];
      }
   }
   int mx = INT_MIN;
   for(int i = 0 ; i < n ; i++)
      mx = max(mx , sum[i]);
   return mx;
}

int main()
{
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Sum of maximum sum increasing subsequence is "<<
           maxSumIS( arr, n ) ;
    return 0;
}
