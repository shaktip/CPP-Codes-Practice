#include<iostream>
using namespace std;
//number is lucky if it is present after taking every gap of 2 elements, then
//every gap of 3 numbers, then taking every gap of 4 numbers, and so on from
// a series of 1.....n numbers. The operation is in succession.


bool isLucky(int n, int cnt)
{
   if(cnt > n )
     return 1;

   if(n % cnt == 0)
      return 0;
   n = n -  n / cnt;
   cnt++;
   isLucky(n , cnt);
}
int main()
{
   int n;
   cin>>n;
   cout<<"  n is lucky?? = "<<isLucky(n,2);
   return 0;
}
