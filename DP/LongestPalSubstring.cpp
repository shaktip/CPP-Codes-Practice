#include<iostream>

using namespace std;
string longestPalSubstr(string str)
{
   int n = str.length();
   bool dp[n][n];
   int maxLen = 0 , startIndex = -1;
   for(int len = 1 ; len <= n ; len++)
   {
      for(int i = 0 ; i <= n - len  ; i++)
      {
         int j = i + len - 1;
         if(len == 1)
         {dp[i][i] = true;}
         else
         {
            if(len == 2)
            {
               dp[i][j] = (str[i] == str[j]);
            }
            else
            {
               dp[i][j] = (str[i] == str[j]) ? dp[i+1][j-1] : false;
            }
         }
         if(dp[i][j])
         {
            if(maxLen < len)
            {maxLen = len ; startIndex = i;}
         }
      }
   }
   cout<<"startIndex "<<startIndex << " Max length = "<<maxLen;
   return str.substr(startIndex , maxLen);
}
int main()
{
    string str = "aaaaaabcaaaaaaaa";
    cout<<"Length is: " << longestPalSubstr( str ) ;
    return 0;
}
