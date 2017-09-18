#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int findCeil(char *s , int first, int left , int right)
{
   int ceilIndex = left;
   for(int i = left + 1 ; i <= right ; i++)
      if(first < s[i] && s[ceilIndex] > s[i])
          ceilIndex = i;
   return ceilIndex;
}
void reverse(char *s , int start , int end)
{
   while(start < end)
   {
      swap(s[start] , s[end]);
      start++; end--;
   }
}
void swap(char *a, char *b)
{
   char temp = *a;
   *a = *b;
   *b = temp;
}
void findNextPermutation(char *s)
{
    int n = strlen(s);
    int i;
    for(i = n - 2; i>=0 ; i-- )
       if(s[i] < s[i+1])
          break;
    //cout<<"Value of i= "<<i<<endl;
    if(i == -1)
      return;
    int ceilIndex = findCeil(s , s[i] ,  i+1 , n-1);
    //cout<<"CeilIndex = "<<ceilIndex<<endl;
    swap(s[i] , s[ceilIndex]);

    reverse(s , i+1 , n - 1);
    //cout<<"In findNextPermutation function s = "<<s;
}
int compare(const void *a, const void *b)
{
  return *(char *)a - *(char *)b;
}
void findPermutation(char *s)
{
   qsort(s , strlen(s) , sizeof(s[0]) , compare);
   //cout<<s;

   do
   {
     char *s1 = new char[strlen(s)];
     strcpy(s1 , s);
     cout<<s1<<endl;
     //char ch; cin>>ch;
     findNextPermutation(s);
     if(strcmp(s1 , s) == 0)
        break;
   }while(1);

}
int main()
{
    char p[] = "4554";
    char *s = new char[strlen(p) + 1];
    strcpy(s, p);
    findPermutation(s);
    return 0;
}
