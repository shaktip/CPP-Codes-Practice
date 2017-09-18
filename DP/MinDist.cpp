#include<iostream>

#define R 3
#define C 3



using namespace std;

int minCost(int cost[R][C] , int r , int c)
{
   int dp[R][C];
   dp[0][0] = cost[0][0];
   for(int i = 1 ; i < R ; i++)
      dp[i][0] = cost[i][0] + dp[i-1][0];
   for(int j = 1; j < C ; j++)
      dp[0][j] = cost[0][j] + dp[0][j-1];
   for(int i = 1 ; i < R ; i++)
   {
      for(int j = 1 ; j < C ; j++)
      {
           dp[i][j] = cost[i][j] + min(dp[i-1][j-1] , min(dp[i-1][j] , dp[i][j-1]));

      }
   }
   return dp[r][c];
}


int main()
{
   int cost[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
   cout<<minCost(cost, 2, 2);
   return 0;
}
