#include<iostream>
#include<limits.h>
using namespace std;

struct Edge
{
  int src, dest , wt;
  Edge(int s, int d , int w)
  {
    src = s ; dest = d ; wt = w;
  }
  Edge() { }
};
struct Graph
{
   int V;
   int E;
   Edge *edges;
   Graph(int v , int e)
   {
      V = v; E = e; edges = new Edge[E];
   }
};
void insertEdge(Graph g , int index, int src , int dest , int wt)
{
   g.edges[index].src = src;
   g.edges[index].dest = dest;
   g.edges[index].wt = wt;
}
void bellManFord(Graph g , int s)
{
   int dist[g.V];
   for(int i = 0 ; i < g.V ; i++)
      dist[i] = INT_MAX;
   dist[s] = 0;
   for(int i = 0 ; i < g.E ; i++)
   {
      for(int j = 0 ; j < g.V - 1 ; j++)
      {
         int u = g.edges[i].src; int v = g.edges[i].dest ; int w = g.edges[i].wt;
         if(dist[u] != INT_MAX && dist[v] > dist[u] + w)
           dist[v] = dist[u] + w;
      }
   }
   for(int i= 0 ; i < g.E ; i++)
   {
      int u = g.edges[i].src ; int v = g.edges[i].dest ; int w = g.edges[i].wt;
      if(dist[u] != INT_MAX && dist[v] > dist[u] + w)
      {
        cout<<"Negative edge weight cycle exists";
        break;
      }
   }
   for(int i = 0 ; i < g.V ; i++)
      cout<<"From "<<s<<" To "<<i<<" Dist is " << dist[i]<<endl;;
}
int main()
{
   Graph g(5 , 8);
   insertEdge(g , 0 , 0, 1 , -1);
   insertEdge(g , 1 , 0, 2 , 4);
   insertEdge(g , 2 , 1, 2 , 3);
   insertEdge(g , 3 , 1, 3 , 2);
   insertEdge(g , 4 , 1, 4 , 2);
   insertEdge(g , 5 , 3, 2 , 5);
   insertEdge(g , 6 , 3, 1 , 1);
   insertEdge(g , 7 , 4, 3 , -3);
   bellManFord(g,0);
   return 0;
}
