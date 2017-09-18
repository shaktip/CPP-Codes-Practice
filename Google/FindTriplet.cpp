#include<iostream>
#include<algorithm>


using namespace std;
int compare(const void *a, const void *b)
{
    int *p = (int *)a; int *q = (int *)b;
    return *p > *q;
}
void findTriplets(int a[] , int n)
{
    qsort(a , n , sizeof(a[0]) , compare);
    for(int i = 0 ; i < n ; i++)
    {
       int  l = i+1 , r = n-1 ;
       while(l < r)
       {
           if(i == l)
              l++;
           if(i == r)
              r--;
           if(l >= r)
              break;
           int sum = a[i] + a[l] + a[r];
           if(sum == 0)
           {
              cout<<"\n\t "<<a[i] << " "<<a[l]<<" "<<a[r];
              break;
           }
           if(sum > 0)
              r--;
           if(sum < 0)
              l++;
       }
    }

}


int main()
{
    int arr[] = {0, -1, 2, -3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"\n\t";
    findTriplets(arr, n);
    return 0;
}
