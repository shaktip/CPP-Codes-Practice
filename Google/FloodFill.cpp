#include<iostream>

using namespace std;
#define M 8
#define N 8

int shiftX[] = {0,1,0,-1};
int shiftY[] = {1,0,-1,0};


void floodFill(int screen[M][N], int x, int y, int newC)
{
    int col = screen[x][y] ;
    screen[x][y] = newC;
    for(int i = 0 ; i < 4 ; i++)
    {
       int newx = x + shiftX[i]; int newy = y + shiftY[i];

       if(newx >= 0 && newx < M && newy >= 0 && newy < N && screen[newx][newy] == col)
       {
          floodFill(screen , newx , newy , newC);
       }
    }
}
int main()
{
    int screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 0, 1, 1, 0, 1, 1},
                      {1, 2, 2, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 2, 2, 0},
                      {1, 1, 1, 1, 1, 2, 1, 1},
                      {1, 1, 1, 1, 1, 2, 2, 1},
                     };
    int x = 4, y = 4, newC = 3;
    floodFill(screen, x, y, newC);

    cout << "Updated screen after call to floodFill: \n";
    for (int i=0; i<M; i++)
    {
        for (int j=0; j<N; j++)
           cout << screen[i][j] << " ";
        cout << endl;
    }
}
