#include<iostream>
using namespace std;
int main()
{
   int a[] = {1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1};
   int N  = sizeof(a) / sizeof(a[0]);
   int prevZeroIndex = -1 , currZeroIndex = -1;
   int i = 0 ;
   int maxDiff = INT_MIN;
   int indx = -1;
   while( i < N )
   {
      while( i < N && a[i] == 1)
        i++;
      if(i == N)
         break;
      if(prevZeroIndex == -1)
         prevZeroIndex = i;
      else
      {
          currZeroIndex = i;
          int diff = currZeroIndex - prevZeroIndex - 1;
          if(diff > maxDiff)
          {
              maxDiff = diff;
              indx = prevZeroIndex;
          }
          prevZeroIndex = currZeroIndex;

      }

   }

}
