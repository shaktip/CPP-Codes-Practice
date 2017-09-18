#include<iostream>
#include<string.h>
using namespace std;
/*
  For the set[] = {'a' , 'b'}  k = 3 number of permutations possible are
    n^k = 2^3 = 8
    aaa
    aab
    aba
    abb
    baa
    bab
    bba
    bbb
*/
void printAllPermutations(string s , string prefix , int  n, int k  )
{
   if(k == 0)
   {
      cout<<"\n\t " << prefix;

      return;
   }
   for(int i = 0 ; i < n; i++)
   {
       string newprefix = prefix + s[i];
       printAllPermutations(s, newprefix , n , k-1);

   }

}
int main()
{
   string s;
   cout<<"\n\t Enter a string = ";
   cin>>s;
   string prefix = "";
   int k;
   cout<<"\n\t Enter k = "; cin>>k;
   printAllPermutations(s, prefix, s.length() , k);

   return 0;
}
