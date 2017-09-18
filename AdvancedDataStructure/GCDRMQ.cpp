#include<iostream>
#include<math.h>
#include<limits.h>

using namespace std;

int gcd(int a, int b)
{
  if(b == 0)
    return a;
  return gcd(b , a % b);
}

void constructSegTree(int *st, int indx , int arr[] , int a , int b)
{
    if(a == b)
    {
        st[indx] = arr[a];
        return;
    }
    if(a > b)
       return;

    constructSegTree(st , 2 * indx + 1 , arr , a , (a+b)/2 );
    constructSegTree(st , 2 * indx + 2 , arr , (a+b)/2 + 1 , b);
    st[indx] = gcd(st[2 * indx + 1] , st[2 * indx + 2]);
}

void printSegArray(int segArray[] ,int height ,  int n)
{
   int k = 0;
   for(int i = 0 ; i <= height ; i++)
   {
       for(int j = 0 ; j < (1<<i) ; j++)
          cout<<"  "<< segArray[k++];
       cout<<"\n";
   }
}
int * constructSegmentTree(int a[] , int n)
{
   int height = ceil(log2(n));

   int m = 2 * (1 << height) - 1;
   //cout<<m;
   int *segArray = new int[m];

   constructSegTree(segArray, 0 , a , 0 , n-1);
   printSegArray(segArray , height , m);
   return segArray;
}
int findRange(int *segArray , int segIndex, int l , int r, int a[] , int segS, int segE)
{
    if(l <= segS && r >= segE)
      return segArray[segIndex];
    if(l > segE || r < segS)
         return 0;
    int left = findRange(segArray , 2 * segIndex + 1 , l , r, a , segS , (segS + segE) / 2);
    int right = findRange(segArray , 2 * segIndex + 2 , l , r, a, (segS + segE)/2 + 1 , segE);
    return gcd(left , right);

}
int findRangeGcd(int *segArray , int l, int r, int a[], int n)
{
   if(l > r)
     return -1;
   return findRange(segArray , 0 , l , r, a , 0 , n -1);
}
int main()
{
    int a[] = {2, 3, 6, 9, 5};
    int n = sizeof(a)/sizeof(a[0]);

    // Build segment tree from given array
    int *segArray = constructSegmentTree(a, n);

    // Starting index of range. These indexes are 0 based.
    int l = 1;

    // Last index of range.These indexes are 0 based.
    int r = 4;
    cout << "GCD of the given range is:";
    cout << findRangeGcd(segArray , l, r, a, n) << "\n";

    return 0;
}
