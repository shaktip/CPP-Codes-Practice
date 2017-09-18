#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<utility>


using namespace std;
int comp(const void *a, const void *b)
{
   return *(char *)a > *(char *)b;

}
void printPermutation(char *a, int l , int r)
{
   if(l == r)
   {
      cout<<"\n\t"<<a;
      return;
   }
   for(int  i  = l ; i <= r; i++)
   {
      if((a[l] != a[i] && i != l) || i == l)
      {
       swap(a[l] , a[i]);
       printPermutation(a, l+1, r);
       swap(a[l] , a[i]);
      }
   }
}

void permuteWithouRepeatation(char *a, int l, int r)
{
   qsort(a, strlen(a), sizeof(char) , comp);
   printPermutation(a, l , r);
}
void permute(char *a, int l, int r)
{
   int i;
   if (l == r)
     printf("%s\n", a);
   else
   {
       for (i = l; i <= r; i++)
       {
          swap(a[l], a[i]);
          permute(a, l+1, r);
          swap(a[l], a[i]); //backtrack
       }
   }
}
int main()
{
  char *s = new char[100];
  //strcpy(s, "ABC");
  cout<<"\n\t Enter a string  = " ;
  cin>>s;

  cout<<"\n\t Entered string is "<<s <<"\n";

  //cout<<"\n\tLeTngth of string is " << s.length();
  cout<<"\n\t Permutations with repeatations = \n";
  permute(s, 0, strlen(s) - 1);
  cout<<"\n\t Permutations without repeatations = \n";
  permuteWithouRepeatation(s, 0 , strlen(s) - 1);
  return 0;
}
