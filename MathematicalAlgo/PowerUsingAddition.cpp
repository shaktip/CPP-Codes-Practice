#include<iostream>
using namespace std;

long pow(long n, int m)
{
    long p = n;
    for(int i = 1 ; i < m ; i++)
    {
       int x = 0;
       for(int j = 1; j <= p ; j++)
          x = x + n;
       n = x;
    }
    return n;
}

int main()
{
  int n , m;
  cin>>n>>m;
  cout<<pow(n,m);
  return 0;
}


