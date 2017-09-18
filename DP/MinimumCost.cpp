#include<iostream>
#include<limits.h>

using namespace std;
#define R 3
#define C 3
int possible[][2] = {{1,0},{0,1},{1,1}};
int minimumCost;  bool flag = false;

/*
//Using Backtracking
int minCost(int cost[R][C] , int dr, int dc , int currentR , int currentC , int c)
{
    if(currentR == dr && currentC == dc)
    {
       cout<<"Cost is "<<c<<endl;
       if(!flag)
       {
          minimumCost = c;
          flag = true;
       }
       else
       {
          if(c < minimumCost)
            minimumCost = c;
       }
    }

    for(int i = 0 ; i < 3 ;  i++)
    {
       int x = possible[i][0], y = possible[i][1];
       if(currentR + x < R && currentC + y < C)
       {
           c = c + cost[currentR + x][currentC + y];
           minCost(cost, dr , dc , currentR + x , currentC + y , c);
           c = c - cost[currentR + x][currentC + y];
       }
    }
}
*/

//Using DP

int findMin(int cost[R][C],int dr , int dc)
{

    if(dr < 0 || dc < 0)
      return INT_MAX;
    if(dr == 0 && dc == 0)
      return cost[dr][dc];

    return cost[dr][dc] + min(min(findMin(cost , dr , dc -1) , findMin(cost, dr-1 ,dc))
                                   , findMin(cost , dr - 1, dc - 1));
}

//Using Memoization
int findMinNonRec(int cost[R][C], int dr , int dc)
{
   int c[dr+1][dc+1] = {INT_MAX};
   int i , j;
   c[0][0] = cost[0][0];

   for(i = 1 ; i <= dr ; i++)
      c[i][0] = cost[i][0] + c[i-1][0];
   for(j = 1 ; j <= dc ; j++)
      c[0][j] = cost[0][j] + c[0][j-1];
/*
   for(i = 0 ; i <= dr ; i++)
   {
     cout<<endl;
     for(j = 0 ; j <= dc ; j++)
       cout<<c[i][j]<<"  ";
   }
*/
   for(i = 1 ; i <= dr ; i++)
   {
     for(j = 1 ; j <= dc ; j++)
     {
            c[i][j] = cost[i][j] + min(c[i-1][j-1] , min(c[i-1][j] , c[i][j-1]));
     }
   }
/*
   cout<<"Final = ";
   for(i = 0 ; i <= dr ; i++)
   {
     cout<<endl;
     for(j = 0 ; j <= dc ; j++)
       cout<<c[i][j]<<"  ";
   }
*/
   return c[dr][dc];
}

int main()
{
  int cost[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
  cout<<findMin(cost, 2, 2)<<endl;
  cout<<"\n\tFinal cost = ";
  cout<<findMinNonRec(cost , 2 , 2 )<<endl;
  //minCost(cost , 2, 2 , 0 , 0 , cost[0][0]);
  //cout<<minimumCost;
  return 0;
}
