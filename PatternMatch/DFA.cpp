#include<iostream>
#include<string.h>

#define d 26

using namespace std;

void constructDFA(int DFA[][d] , int states , int inputs , char pat[])
{
   for(int i = 0 ; i < inputs ;i++)
       DFA[0][i] = 0;

   DFA[0][pat[0]-'A'] = 1;

   for(int s = 1 ; s < states ; s++)
   {
      for(int i = 0 ; i < inputs ; i++)
      {
             if(s < strlen(pat) && pat[s] - 'A' == i)
                {DFA[s][i] = s+1; continue ; }

             int j;

             for(j = s - 1; j >= 0 ; j--)
             {
                 if(pat[j] - 'A' == i)
                 {
                     bool flag = true;
                     for(int k = j-1 , p = s - 1 ; k >= 0 ; k--,p--)
                     {
                         if(pat[k] != pat[p])
                         {flag = false; break;}
                     }
                     if(flag)
                     {
                        DFA[s][i] = j + 1;
                        break;
                     }
                 }
             }
             if(j == -1)
                DFA[s][i] = 0;
      }
   }
}
void print(int DFA[][d] , int m , int col)
{
   int i , j;
   for( i = 0 ; i < m  ; i++)
   {
      for(j = 0 ; j < col;  j++)
         cout<<DFA[i][j]<<" ";
      cout<<endl;
   }
}
void search(char pat[] , char txt[])
{
   int m = strlen(pat);
   int n = strlen(txt);
   int DFA[m+1][d];
   constructDFA(DFA , m+1 , d , pat);
   print(DFA , m+1 , d);
   int state = 0;
   int i;
   for(i = 0 ; i < n ; i++)
   {
      if(state == m)
      {
        cout<<"Pattern found at "<<i - state<<endl;;
      }
      state = DFA[state][txt[i] - 'A'];
   }
   if(state == m)
   {
     cout<<"Pattern found at " << i - state<<endl;
   }
}
int main()
{
    char txt[] = "AABBABAABAABAABAABBABAABAABAA";
    char pat[] = "AABA";

    search(pat, txt);
    return 0;
}
