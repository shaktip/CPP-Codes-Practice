#include<iostream>
#include<algorithm>
#include<limits.h>

using namespace std;

int partition(int a[] , int l , int r)
{
   int pivot =  a[r];

   int i = l;
   for(int j = l ; j < r ; j++)
   {
       if(a[j] < pivot)
          swap(a[i++],a[j]);
   }
   swap(a[r] , a[i]);
   return i;
}
void printArray(int a[] , int N)
{
   cout<<"\n\t Array is : ";
   for(int i = 0 ; i < N ; i++)
     cout<<a[i]<<"  ";
}
int qsort(int a[] , int l , int h , int k , int N)
{
   if(l > h)
     return INT_MAX;
   if(l == h && l == k - 1)
      return a[l];
   if(l == h)
       return INT_MAX;

   int pos = partition(a, l, h);
   cout<<"\n\tPosition is = " << pos;
   printArray(a, N);
   if(pos == k - 1)
     return a[pos];
   if(k <= pos)
      qsort(a , l , pos - 1 , k , N);
   else
      qsort(a , pos + 1 , h , k , N);

}
int main()
{
   int a[] = {12, 3, 5, 7, 4, 19, 26};
   int N = sizeof(a) / sizeof(a[0]);
   int k;
   cout<<"Enter k = "; cin>>k;

   cout<<"\n\t Element is = " << qsort(a , 0 , N - 1 , k , N);
}
