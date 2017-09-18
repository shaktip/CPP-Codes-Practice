
#include<iostream>
#include<algorithm>


using namespace std;
int searchFZ(int a[] , int l , int h, int x)
{
  if(l > h)
    return -1;
  if(l == h && a[l] == x)
    return l;
  int mid = (l + h) / 2;
  if(a[mid] == x && a[mid-1] != x)
    return mid;
  if(a[mid] > x)
    return searchFZ(a , mid+1 , h , x);
  return searchFZ(a , l , mid - 1, x);
}
int searchFirstZero(int a[] , int N , int x)
{
   int p = searchFZ(a , 0 , N-1 , x);
   return p;
}
int mycomp(int a, int b)
{
   return a > b;
}
int main()
{
    int a[] = {0,0,0,0,0,0,0};
    int N = sizeof(a) / sizeof(a[0]);
    int FirstZero = searchFirstZero(a , N , 0);

    cout<<FirstZero<<endl;

    int arr[] = {1,2,3,4,5,5,5,5,6,7,8,8,8,9,15,15,16};
    int M = sizeof(arr) / sizeof(arr[0]);

    pair<int * , int * > bound;
    bound = equal_range(arr , arr+M , 19);
    cout<<"  "<< bound.first - arr<<"  "<<bound.second - arr << endl;

    int b[] = {7,6,5,5,5,4,3,3,2,2,1,1,0};
    int sz = sizeof(b) / sizeof(b[0]);
    pair<int * , int *> bnd;
    bnd = equal_range(b , b + sz , 5,mycomp);
    cout<<"  "<<bnd.first - b << "  " << bnd.second - b << endl;;


    return 0;
}
