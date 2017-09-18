/*
   Given a set of n numbers and sum=k find the subset which satisfies this
   steps
   1. Sort the set
   2. create an empty set t[]
   3. one by one include the elements in t[] and check whether its sum is less than or equal to
        k, if yes try other number.
        if not then discard the number, try next one t[]
   4. Use backtracking.

*/
#include<iostream>
#include<algorithm>
#include<string.h>


using namespace std;
int comp(const void *a, const void *b)
{
   return *(int *)a > *(int *)b;
}
void printArray(int t[],int n)
{
   cout<<"\n\tArray is :";
   for(int i = 0 ; i < n ; i++)
   {
      if(t[i] != -1)
        cout<<"  "<<t[i];
   }
}

void findSumOfSubset(int s[] , int n , int t[] , int tIndex , int sumTillNow , int k,int nextI)
{
    if(sumTillNow == k)
    {
       printArray(t , tIndex);
       return;
    }
    for(int i = nextI ; i < n; i++)
    {
       t[tIndex] = s[i];
       if(sumTillNow + s[i] <= k)
       {
          findSumOfSubset(s, n , t , tIndex + 1, sumTillNow + s[i] , k , i + 1);
       }
       else
       {
          break;
       }

    }

}



int main()
{
    int n,k;
    cout<<"\n\t Enter set size = " ; cin>>n;
    int *s,*t;
    s = new int[n];
    int total = 0;
    for(int i = 0 ; i < n ; i++)
    {
      cout<<"\n\t Enter s["<<i<<"]=";
      cin>>s[i];
      total += s[i];
    }
    qsort(s, n, sizeof(int),comp);

    cout<<"\n\t Enter k = "; cin>>k;
    if(k < s[0] || k > total)
    {
       cout<<"\n\t Solution does not exist";
       return 0;
    }
    t = new int[n];

    memset(t , -1 , n * sizeof(int));

    int tIndex = 0;

    findSumOfSubset(s , n , t , tIndex ,0 , k , 0);


    return 0;
}
