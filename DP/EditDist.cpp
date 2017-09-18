#include<iostream>

using namespace std;
int editDistDP(string s1 , string s2 , int m , int n)
{
   int edit[m + 1][n + 1];
   for(int i = 0 ; i <= m ; i++)
   {
      for(int j = 0 ; j <= n ; j++)
      {
         if(i == 0)
         {
            edit[i][j] = j; continue;
         }
         else if(j == 0)
         {edit[i][j] = i ; continue;}
         if(s1[i-1] == s2[j-1])
            edit[i][j] = edit[i-1][j-1];
         else
         {
            edit[i][j] = 1 + min(edit[i][j-1] , min(edit[i-1][j] , edit[i-1][j-1]));
         }
      }
   }
   return edit[m][n];
}
int main()
{
   // your code goes here
    string str1 = "sunday";
    string str2 = "saturday";

    cout << editDistDP(str1, str2, str1.length(), str2.length());

    return 0;

}
