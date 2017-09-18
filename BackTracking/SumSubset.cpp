//Subset sum into 2 parts for given sum.
//Divide the set into 2 parts of equal sum
//Divide the set into k parts of equal sum.
#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>


using namespace std;


int comp(const void *a, const void *b)
{
   return *(int *)a > *(int *)b;
}

bool findSubsetOfSum
    (int a[], int n , int requiredSum ,int sumTillNow , bool taken[], int currentIndex)
{
   if(sumTillNow == requiredSum)
     return true;
   for(int i = currentIndex ; i < n ;i++)
   {
     if(!taken[i])
     {
         if((sumTillNow + a[i]) <= requiredSum )
         {
             taken[i] = true;
             if(!findSubsetOfSum(a , n , requiredSum, sumTillNow + a[i] , taken , i+1))
                taken[i] = false;
             else
                return true;
         }
         else
            break;
     }
   }
   return false;
}


void printVector(vector<int> v)
{
   cout<<"\n\t The vector is  == ";
   for(int i = 0 ; i < v.size() ; i++)
     cout<<"  "<<v[i];
}

bool EqualSizePartition
  (int a[], int n , bool taken[], int requiredSum ,
      int sumTillNow[] , int kthPartition , int NumberOfPartitions,vector<int> v)
{
    if(sumTillNow[kthPartition] == requiredSum)
    {
       printVector(v);
       if(kthPartition == NumberOfPartitions - 2)
         return true;
       vector<int> v1;
       return EqualSizePartition(a, n , taken , requiredSum, sumTillNow , kthPartition + 1, NumberOfPartitions, v1);
    }
    for(int i = 0 ; i < n ; i++)
    {
       if(!taken[i])
       {
          if(sumTillNow[kthPartition] + a[i] <= requiredSum)
          {
              taken[i] = true;
              sumTillNow[kthPartition] += a[i] ;
              v.push_back(a[i]);
              if(!EqualSizePartition(a, n , taken ,requiredSum,sumTillNow,kthPartition , NumberOfPartitions , v))
              {
                taken[i] = false;
                sumTillNow[kthPartition] -= a[i];
                v.pop_back();
              }
              else
                return true;
          }
          else
            break;
       }
    }
    return false;
}

int main()
{
    int *a , n;
    cin>>n;
    a = new int[n];
    int total = 0;
    for(int i = 0 ; i < n ;i++)
    {
       cin>>a[i];
       total += a[i];
    }
    qsort(a , n , sizeof(int) , comp);
    int requiredSum;
    cout<<"\n\t Enter required sum = ";
    cin>>requiredSum;
    bool taken[n];
    memset(taken , false, n * sizeof(bool));
    bool flag;
    if(requiredSum < a[0] || requiredSum > total)
      flag = false;
    else
      flag = findSubsetOfSum(a, n , requiredSum , 0 , taken, 0);
    if(flag)
    {
       cout<<"\n\t Solution is possible : ";
       for(int i = 0 ; i < n ; i++)
       {
         if(taken[i])
           cout<<"  "<<a[i];
       }
    }
    else
       cout<<"\n\t Solution is not possible ";

    /*For equal sum , use requiredSum = sum/2 if sum is even, otherwise equal sum is not possible */
    memset(taken , false, n * sizeof(bool));

    requiredSum = total / 2;
    if(total % 2 != 0 || requiredSum < a[0] || requiredSum > total)
      flag = false;
    else
      flag = findSubsetOfSum(a, n , requiredSum , 0 , taken, 0);
    if(flag)
    {
       cout<<"\n\t Solution is possible : ";
       for(int i = 0 ; i < n ; i++)
       {
         if(taken[i])
           cout<<"  "<<a[i];
       }
    }
    else
      cout<<"\n\t Equal Sum Solution is not possible";

    int k;
    cout<<"\n\t Enter number of partitions of equal size required =";
    cin>>k;

    requiredSum = total / k;
    memset(taken, false, n * sizeof(int));

    if(k < 1 || k > n || total % k != 0 || requiredSum < a[0] || requiredSum > total)
       flag = false;
    else if (k == 1 )
       flag = true;
    else
    {
       int sumTillNow[k];
       memset(sumTillNow , 0 , k * sizeof(int));
       vector<int> v ;
       flag = EqualSizePartition(a, n , taken, requiredSum , sumTillNow , 0 , k, v);
    }
    if(flag)
       cout<<"\n\t Solution found";
    else
       cout<<"\n\t K size partition not possible";
    return 0;
}
