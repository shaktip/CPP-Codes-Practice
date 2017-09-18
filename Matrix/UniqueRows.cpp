#include<iostream>
#include<map>
#include<string>

using namespace std;
#define ROW 4
#define COL 5

void printUnique(int M[][COL])
{
    map<string, int> mp;
    for(int i = 0 ; i < ROW ; i++)
    {
       string s = "";
       for(int j = 0 ; j < COL ; j++)
       {
          s = s + char(M[i][j] + 48);
       }
       if(mp.find(s) == mp.end())
          mp[s] = i;
    }
    for(map<string, int> :: iterator itr = mp.begin() ; itr != mp.end() ; itr++)
    {
        int r = itr->second;
        for(int j = 0 ;j < COL ; j++)
          cout<<M[r][j]<<" ";
        cout<<endl;
    }
}

int main()
{

   int M[ROW][COL] = {{0, 1, 0, 0, 1},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0}
    };
    printUnique(M);
   return 0;
}
