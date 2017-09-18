#include<iostream>
#include<limits.h>
#include<string.h>

using namespace std;
int points[] = {3,5,10};
int ways(int n , int pos)
{
  static int count = 0;
  if(n < 0)
    return 0;
  if(n == 0)
  {
    count++;
    return count;
  }
  for(int i = pos ; i < 3 ; i++)
     if(points[i] <= n)
        ways(n-points[i] , i);
     else
       break;
  return count;
}
int NoOfWays(int n)
{
  return ways(n , 0);
}

int NonRecWays(int n)
{
  int table[n+1];

  memset(table, 0 , sizeof(table));
  table[0] = 1;
  for(int i = 3; i <= n ; i++)
     table[i] = table[i] + table[i - 3];
  for(int i = 5; i <= n ; i++)
     table[i] = table[i] + table[i - 5];
  for(int i = 10 ; i <= n ; i++)
     table[i] = table[i] + table[i - 10];

  return table[n];
}
int main()
{
  int  n = 11;
  cout<<"No of ways to reach the goal ="<<NoOfWays(n)<<endl;;
  cout<<"Non Recursive ways = " << NonRecWays(n)<<endl;
  return 0;
}
