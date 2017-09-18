#include<iostream>
#include<string.h>

using namespace std;

void update(int BIT[] , int indx, int newValue , int n)
{
    while(indx < n)
    {

       BIT[indx] += newValue;
       indx = indx + (indx & (-indx));
    }
}
int sum(int BIT[], int indx)
{
  int sum = 0;
  while(indx > 0)
  {
      sum += BIT[indx];
      indx = indx - (indx & (-indx));
  }
  return sum;
}
void print(int BIT[] , int n)
{
   for(int i =  0 ; i < n ; i++)
     cout<<"At index "<< i << " Value is = "<<BIT[i]<<endl;
}
int main()
{
   int arr[] = {10,20,30,40,50,60,70,80,90};
   int n = sizeof(arr) / sizeof(arr[0]);
   int BIT[n+1];

   memset(BIT , 0 , sizeof(BIT));

   for(int i = 0 ; i < n ; i++)
   {
      update(BIT , i+1 , arr[i] , n+1);
   }
   print(BIT , n+1);

   for(int i = 0 ; i < n ; i++)
   {
      for(int j = i ; j < n ; j++)
      {
         cout<<"\nSum of Range("<<i<<","<<j<<") = "<<sum(BIT , j+1) - sum(BIT , i+1-1) ;
      }

   }
   cout<<"\n\t New Array is = \n";
   for(int i = 0 ; i < n ; i++)
   {
      int newvalue = i;

      update(BIT , i+1 , i - arr[i] , n+1);
      arr[i] = newvalue;
      cout<<arr[i]<<"   ";
   }


    print(BIT , n+1);


   cout<<"\n";
   for(int i = 0 ; i < n ; i++)
   {
      for(int j = i ; j < n ; j++)
      {
         cout<<"\nSum of Range("<<i<<","<<j<<") = "<<sum(BIT , j+1) - sum(BIT , i+1-1) ;
      }

   }

   return 0;
}
