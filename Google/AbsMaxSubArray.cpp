#include<iostream>
#include<limits.h>
#include<math.h>
#include<stdlib.h>



using namespace std;
void getLeftMin(int a[] , int n , int leftMin[])
{
   int currSum = a[0] , minElem = a[0] ; leftMin[0] = a[0];
   for(int i = 1 ; i < n ; i++)
   {
      currSum = min(a[i] , currSum + a[i]);
      minElem = min(minElem , currSum);
      leftMin[i] = minElem;
   }
}
void getLeftMax(int a[] , int  n , int leftMax[])
{
   int currSum = a[0] , maxElem = a[0] ; leftMax[0] = a[0];
   for(int i = 1 ; i < n ; i++)
   {
      currSum = max(a[i] , currSum + a[i]);
      maxElem = max(maxElem , currSum);
      leftMax[i] = maxElem;
   }
}
void getRightMin(int a[] , int  n , int rightMin[])
{
  int currSum = a[n-1] , minElem = a[n-1] ; rightMin[n-1] = a[n-1];
  for(int i = n-2 ; i >= 0 ; i--)
  {
     currSum = min(a[i] , currSum + a[i]);
     minElem = min(minElem , currSum);
     rightMin[i] = minElem;
  }
}
void getRightMax(int a[] , int  n , int rightMax[])
{
  int currSum = a[n-1] , maxElem = a[n-1] ; rightMax[n-1] = a[n-1];
  for(int i = n - 2 ; i >= 0 ; i--)
  {
     currSum = max(a[i] , currSum + a[i]);
     maxElem = max(maxElem , currSum);
     rightMax[i] = maxElem;
  }
}
int getAbsDiff(int a[] , int n)
{
   int leftMin[n], leftMax[n] , rightMin[n] , rightMax[n];
   getLeftMin(a , n , leftMin);
   getLeftMax(a , n , leftMax);
   getRightMin(a , n , rightMin);
   getRightMax(a , n , rightMax);
   int result = INT_MIN;
   for(int i = 0 ; i < n -1 ; i++)
   {
      int diff = max(abs(leftMin[i] - rightMax[i+1]) ,
                    abs(leftMax[i] - rightMin[i+1])
                    );
      result = max(result , diff);
   }
   return result;
}
int main()
{
  int a[] = {2, -1, -2, 1, -4, 2, 8};
  int n = sizeof(a) / sizeof(a[0]);
  cout<<getAbsDiff(a , n);
  return 0;
}
