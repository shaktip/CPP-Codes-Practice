#include<iostream>
#include<algorithm>
#include<limits.h>

using namespace std;
void printArray(int a[] , int N)
{
   cout<<"\n\t Array is =";
   for(int i = 0 ; i < N ; i++)
     cout<<a[i]<<"  ";

}
void findMedians(int a[] , int N , int M[] , int l, int h)
{
   int aux[5] = {0};
   int indx = 0, k = 0 , i;
   for(i = 0 ; i+5 < N ; i+=5)
   {
      //cout<<"\nEntered i ="<<i;
      indx = 0;
      for(int j = i ; j < i + 5; j++)
         aux[indx++] = a[l+j];
      sort(aux , aux+5);
      M[k++] = aux[2];
   }
   //cout<<"\n\t Value of k ="<<k; printArray(M , k);
   int median;

   if(i < N )
   {

       indx = 0 ;
       for( ; i < N ; i++)
           aux[indx++] = a[l+i];
       sort(aux, aux + indx);
       //cout<<"\n\tIndex is ="<<indx <<" Aux is ";
       //printArray(aux , indx);
       //cout<<"\n\t indx/2 value is = "<<(indx / 2);
       median = aux[(indx / 2)];

       M[k++] = median;
       //cout<<"\n\tMedian array in findMedian function :";
       //printArray(M , k);

   }
}
int findMedianOfMedians(int a[] , int l , int h, int N)
{
    int sz = (N+4)/5;
    int M[sz] = {0};
    findMedians(a, N , M , l , h);
    //cout<<"Median array is :";
    //printArray(M , sz);
    if(sz == 1)
      return M[0];
    else
      return findMedianOfMedians(M , 0, sz-1 , sz);
}
int partition(int a[] , int l , int h  , int pivot)
{
    int i;
    for(i = l ; i <= h ; i++)
       if(a[i] == pivot)
          break;
    swap(a[i] , a[h]);
    int j;
    i = l;
    for(j = l ; j < h ; j++)
       if(a[j] < pivot)
         swap(a[i++] , a[j]);
    swap(a[h] , a[i]);
    return i;
}

int  kthSmallest(int a[] , int l , int h , int k)
{
      if(l > h)
        return INT_MAX;
      if(l == h && l == k - 1)
         return a[l];
      if(l == h)
          return INT_MAX;
      int sz = (h - l + 1);
      int pivot = findMedianOfMedians(a , l , h , sz);
      cout<<"\n\tPivot element selected by median of medians is = "<<pivot;
      int pos = partition(a , l , h, pivot);
      if(pos == k -1)
         return a[pos];
      if(k <= pos)
         return kthSmallest(a , l , pos-1, k);
      else
         return kthSmallest(a , pos + 1, h , k);

}
int compare(const void *a, const void *b)
{
  return *(int *)a - *(int *)b;
}
int main()
{
   int a[] = {6,5,4,6,77,8,9,5,3,2,3,5,8,9,6,55,4,2,-2,-7,4,3,-2, 5,30,5,4,7,8,9,6,77,88,99,56,67,88,99,6,8,10,-1,0,5};
   int N = sizeof(a) / sizeof(a[0]);
   cout<<"Value of N = "<<N;
   printArray(a , N);

   int k;
   cout<<"\n\tEnter value of k =";   cin>>k;
   cout<<"Value of kth smallest = "<<kthSmallest(a, 0, N-1, k);
   cout<<"\n\t The sorted array is : "<<endl;

   qsort(a , N , sizeof(a[0]) , compare);
   printArray(a, N);
   return 0;
}
