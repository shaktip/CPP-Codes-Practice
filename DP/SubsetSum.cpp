#include<iostream>
using namespace std;
bool findSum(int a[] , int  n , int sum)
{
   bool dp[n][sum+1];

   for(int s = 0 ; s < sum + 1 ; s++)
      dp[0][s] = false;
   for(int i = 0 ; i < n ; i++)
      dp[i][0] = true;

   dp[0][a[0]] = true;

   for(int i = 1 ; i < n ; i++)
   {
      for(int j = 1 ; j < sum + 1 ; j++)
      {

         if(a[i] > j)
            dp[i][j] = dp[i-1][j];
         else
            dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i]] ;

      }
   }
   return dp[n-1][sum];
}
bool findPartition(int a[] , int n)
{
   int sum = 0;
   for(int i = 0 ; i < n ; i++)
      sum = sum + a[i];
   if(sum % 2 != 0)
     return false;
   cout<<"Method called"<<endl;
   return findSum(a , n , sum /2);
}

int main()
{
  int arr[] = {3, 2, 6, 9, 12};
  int n = sizeof(arr)/sizeof(arr[0]);
  if (findPartition(arr, n) == true)
     cout << "Can be divided into two subsets of equal sum";
  else
     cout << "Can not be divided into two subsets of equal sum";
  return 0;
}
