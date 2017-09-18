#include<iostream>

using namespace std;
void printArray(int a[] , int n)
{
   for(int i = 0 ; i < n ; i++)
     cout<<a[i]<<"  ";
   cout<<endl;
}
void rearrange(int a[] , int n)
{
   int i = 0, j = n - 1;
   while(i < j)
   {
      while(i < n && a[i] < 0)
         i++;
      while(j >= 0 && a[j] > 0)
         j--;
      if(i >= j)
         break;
      swap(a[i],a[j]);

   }
   printArray(a, n);
   cout<<i << "  " << j << endl;
   int indx = 0;
   while(i < n && indx < i && a[indx] < 0)
   {

      swap(a[indx] , a[i]);
      indx += 2;
      i++;
   }
}
int main()
{
    int arr[] = {-1, -2, 3, -4, -5, -6, -7, -8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    rearrange(arr, n);
    printArray(arr, n);

  return 0;
}
