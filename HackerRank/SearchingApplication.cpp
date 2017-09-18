#include<iostream>
#include<malloc.h>
#include<algorithm>
#include<vector>
/*
Hackerland Radio Transmitters
Successful
https://www.hackerrank.com/challenges/hackerland-radio-transmitters
*/
using namespace std;

void accept(vector<int> &a , int n)
{
   int x;
   for(int i = 0 ; i < n ; i++)
   {
     cout<<"\n\t Enter element [" << i << "]="; cin>>x;
     a.push_back(x);
   }
}
void display(vector<int> a , int n)
{
  cout<<"\n\t Array elements are :";
  for(int i = 0 ; i < n ; i++)
    cout<<" "<< a[i];
}
int main()
{
  vector<int> a;
  int n;
  cout<<"\n\t Enter size of array : "; cin>>n;

  accept(a, n);
  //display(a , n);
  sort(a.begin(), a.end());

  display(a, n);
  int k;
  cout<<"\n\t Enter value of k = " ; cin>>k;
  int cnt = 0;
  int i, low,x;
  for(i = 0 ; i < n; )
  {
       cout<<"\n\t Value of i ="<<i;
       low = a[i];
       while(low + k >= a[i+1] && i < n)
          i++;

       cnt++;
       if(i >= n)
       {
         cout<<"\n\t At " << (i-1);
         break;
       }
       cout<<"\n\t At "<<i;
       x = a[i];
       while(x + k >= a[i] && i < n)
          i++;
  }

  cout << " Count = " << cnt;
  return 0;
}

