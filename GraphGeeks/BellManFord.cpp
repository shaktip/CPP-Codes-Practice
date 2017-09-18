#include<iostream>
#include<limits.h>

using namespace std;
struct Edge
{
   int src , dest , weight;
};
struct Graph
{
  int V , E;
  struct Edge *edges;
  Graph(int v , int e)
  {
     V = v; E = e; edges = new Edge[E];
  }
};

void insertEdge(Graph g , int i , int s , int d , int wt)
{
   g.edges[i].src = s;
   g.edges[i].dest = d;
   g.edges[i].weight = wt;
}
void BellMan(Graph g , int source)
{
   int dist[g.V];
   for(int i = 0 ; i < g.V ; i++)
      dist[i] = INT_MAX;
   dist[source] = 0;
   for(int i = 0 ; i < g.V ; i++)
   {
      for(int i = 0 ; i < g.E ; i++)
      {
          struct Edge nextEdge = g.edges[i];
          int src = nextEdge.src;
          int dest = nextEdge.dest;
          int wt = nextEdge.weight;

          if(dist[src] != INT_MAX && dist[dest] > dist[src] + wt)
             dist[dest] = dist[src] + wt;
      }
   }
   for(int i = 0 ; i < g.E ; i++)
   {
       struct Edge nextEdge = g.edges[i];
       int src = nextEdge.src;
       int dest = nextEdge.dest;
       int wt = nextEdge.weight;

       if(dist[src] != INT_MAX && dist[dest] > dist[src] + wt)
       {
          cout<<"-ve weight cycle exist";
          return;
       }
   }
   for(int i = 0 ; i < g.V ; i++)
      cout<<"Dist of "<<i<<" from source = "<<source << " is "<<dist[i]<<endl;;

}
int main()
{
  int V = 6 , E = 8;
  Graph g(V , E);
  insertEdge(g , 0 , 0 , 1, -1);
  insertEdge(g , 1 , 2 , 0, 2);
  insertEdge(g , 2 , 1 , 2, -3);
  insertEdge(g , 3 , 1 , 3, 2);
  insertEdge(g , 4 , 1 , 4, 2);
  insertEdge(g , 5 , 3 , 2, 5);
  insertEdge(g , 6 , 3 , 1, 1);
  insertEdge(g , 7 , 4 , 3, -3);
  BellMan(g , 0);
  return 0;
}
