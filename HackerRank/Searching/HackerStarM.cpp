#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<fstream>

using namespace std;

//Successful submission

int possible[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int findWays(char **Array , int r, int c , int MX , int MY)
{
    int count = 0;
    for(int i = 0 ; i < 4 ;i++)
    {
        int x = possible[i][0] , y = possible[i][1];
        int currX = MX + x, currY = MY + y;
        if(currX >= 0 && currX < r && currY >= 0 && currY < c)
        {
            if(Array[currX][currY] == '.' || Array[currX][currY] == '*')
            {
                  count++;
            }
        }
    }
    return count;
}
bool findWaves(char **Array , int r , int c , int MX , int MY , int StarX , int StarY , int K)
{
    if(MX == StarX && MY == StarY)
      if(K == 0)
        return true;
      else
        return false;

    int ways = findWays(Array , r, c , MX , MY);
    cout<<ways<<" K= " << K<< " X = "<<MX << " Y = "<<MY<< "\n";
    if(ways > 1)
        K = K - 1;
    for(int i = 0 ; i < 4 ;i++)
    {
        int x = possible[i][0] , y = possible[i][1];
        int currX = MX + x, currY = MY + y;
        if(currX >= 0 && currX < r && currY >= 0 && currY < c)
        {
            if(Array[currX][currY] == '.' || (currX == StarX && currY == StarY) )
            {
                Array[currX][currY] = 'p';
                if(findWaves(Array , r , c , currX , currY, StarX , StarY , K ) == false)
                   Array[currX][currY] = '.';
                else
                    return true;
            }
        }
    }
    return false;

}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    ifstream inf("Input.txt");
    inf>>T;
    while(T--)
    {
        int r, c;
        inf>>r>>c;
        char **Array;
        Array = new char*[r];
        for(int i = 0 ; i < r ; i++)
            Array[i] = new char[c];

        int MX , MY, StarX, StarY;
        for(int i = 0 ; i < r ; i++)
        {
            for(int j = 0 ; j < c ;j++)
            {
                inf>>Array[i][j];
                if(Array[i][j] == '*')
                {
                    StarX = i ; StarY = j;
                }
                else if(Array[i][j] == 'M')
                {
                    MX = i ; MY = j;
                }
            }
        }
        int K ;
        inf>>K;
        if(findWaves(Array , r , c , MX , MY , StarX , StarY , K))
            cout<<"Impressed";
        else
            cout<<"Oops!";
        cout<<"\n";
    }
    return 0;
}
