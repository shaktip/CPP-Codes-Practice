//m - coloring using backtracking
#include<iostream>
#include<string.h>

using namespace std;

bool isSafe(bool **graph, int v, int *color, int newcolor, int vertex)
{
   for(int i = 0 ; i < v;i++)
   {
     if(graph[i][vertex] && color[i] == newcolor)
       return false;
   }
   return true;
}
bool applyColor(bool **graph, int v, int *color, int m, int vertex)
{
   if(vertex == v)
   {
     return true;
   }
   for(int i = 1; i <= m ; i++)
   {
      color[vertex] = i;
      if(isSafe(graph, v, color, i, vertex) == true)
         if(applyColor(graph, v, color, m, vertex + 1) == true)
           return true;
      else
         color[vertex] = 0;
   }
   return false;
}
void inputGraph(bool **graph, int v)
{
   int i,j;
   for(int i = 0 ; i < v; i++)
   {
     for(int j = 0 ; j < v ; j++)
     {
       cout<<"\n\t Enter (1/0) for edge between ("<<i<<","<<j<<") = ";
       cin>>graph[i][j];
     }
   }
}
void displayColors(int *color, int v)
{
   for(int i=0; i < v; i++)
     cout<<"\n\t Color of "<<i<<" is "<<color[i];
}
int main()
{
    int v,m ;
    cout<<"\n\tEnter number of vertices :";
    cin>>v;
    bool **graph;
    graph = new bool*[v];
    for(int i = 0 ; i < v ; i++)
       graph[i] = new bool[v];

    cout<<"\n\tEnter number of colors :";
    cin>>m;
    int *color;
    color = new int[v];
    memset(color, 0, v * sizeof(int));
    inputGraph(graph,v);
    if(applyColor(graph, v, color, m,0) == false)
    {
       cout<<"\n\t No solution exist";
    }
    else
       displayColors(color, v);

    for(int i = 0 ; i < v; i++)
      delete graph[i];
    delete graph;
    delete color;
    return 0;

}
