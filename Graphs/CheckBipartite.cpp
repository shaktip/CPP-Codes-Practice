#include<iostream>
#include<string.h>

using namespace std;
//Using BFS check bipartite
#define MAX 20
struct Q
{
   int fr , rear;
   int a[MAX];
   Q()
   {
     fr = rear = 0;
   }
};
void Insert(Q &q, int x)
{
   q.a[q.rear++] = x;
}
int rem(Q &q)
{
   return q.a[q.fr++];
}
bool isEmpty(Q q)
{
  return q.fr == q.rear;
}
bool TraverseBFS(int **g, bool visited[] , char color[] , int V, int currentV)
{

  visited[currentV] = 1;
  Q q;
  Insert(q , currentV);
  while(!isEmpty(q))
  {
      int u = rem(q);
      char requiredColor = 'R';
      if(color[u] == 'R')
         requiredColor = 'B';
      for(int i = 0 ; i < V ; i++)
      {
         if(g[u][i] == 1)
         {
            if(visited[i])
            {
               if(color[i] != requiredColor)
                 return false;
            }
            else
            {
                Insert(q, i);
                color[i] = requiredColor;
                visited[i] = true;
            }
         }
      }
  }
  return true;

}
bool checkBipartite(int **g , int V)
{
  bool visited[V];
  memset(visited, false , V * sizeof(bool));
  char color[V];
  memset(color , '0' , V * sizeof(char));
  color[0] = 'R';

  for(int i = 0 ; i < V ; i++)
  {
      if(!visited[i])
      {
         if(TraverseBFS(g,visited,color,V,i) == false)
           return false;
      }
  }
  return true;
}

int main()
{
  int V;
  cout<<"\n\tEnter number of vertices = " ;
  cin>>V;
  int **g;
  g = new int *[V];
  for(int i = 0 ; i < V ; i++)
     g[i] = new int[V];

  for(int i = 0  ; i < V ; i++)
  {
    for(int j = i+1 ; j < V ;j++)
    {
       cout<<"\n\tEnter (1/0) for edge of (" << i << " , " << j << ") = ";
       cin>>g[i][j];
    }
  }
  if(checkBipartite(g,V))
    cout<<"Yes";
  else
     cout<<"No";
  for(int i = 0 ; i < V ;i++)
     delete g[i] ;
  delete g;
  return 0;
}
