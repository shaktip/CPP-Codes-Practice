#include<iostream>
using namespace std;


void get2NonRepeatingElements(int arr[] , int n)
{
   int xOR = 0;
   for(int i = 0 ; i < n ; i++)
      xOR = xOR ^ arr[i];
   int lastSetBit = xOR & (-xOR + 1);

   int xi = 0 , yi = 0;
   for(int i = 0 ; i < n ;  i++)
      if(lastSetBit & arr[i])
        xi = xi ^ arr[i];
      else
         yi = yi ^ arr[i];
   cout<<" First Number = "<<xi << " Second Number = "<<yi;
}

int main()
{
  int arr[] = {2, 3, 7, 9, 11, 2, 3, 11};
  int n = sizeof(arr) / sizeof(arr[0]);
  get2NonRepeatingElements(arr , n);
  return 0;
}
