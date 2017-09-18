#include<iostream>
#include<algorithm>

using namespace std;
struct Edge
{
   int src , dest , weight;

};
struct Graph
{
   int V;
   int numberOfE;
   struct Edge *E;
   Graph(int v , int e)
   {
      V = v;
      numberOfE = e;
      E = new Edge[e];
   }
};
void insertEdge(Graph g , int i , int src , int dest ,int weight)
{
  g.E[i].src = src; g.E[i].dest = dest ; g.E[i].weight = weight;
}
int compare(const void *a , const void *b)
{
   struct Edge *p = (struct Edge *) a;
   struct Edge *q = (struct Edge *) b;
   return p->weight > q->weight;
}
struct SubSet
{
   int Parent;
   int Rank;
};

int find(struct SubSet subsets[] , int x)
{
   if(subsets[x].Parent != x)
      subsets[x].Parent = find(subsets , subsets[x].Parent);
   return subsets[x].Parent;
}
void Union(struct SubSet subsets[] , int x , int y)
{
   int xset = find(subsets , x);
   int yset = find(subsets , y);
   if(subsets[xset].Rank < subsets[yset].Rank)
       subsets[xset].Parent = yset;
   else if(subsets[xset].Rank > subsets[yset].Rank)
       subsets[yset].Parent = xset;
   else
   {
       subsets[xset].Parent = yset;
       subsets[yset].Rank++;
   }
}

void KruskalsMST(Graph g)
{
    qsort(g.E , g.numberOfE , sizeof(Edge) , compare);

    struct SubSet subsets[g.V];
    for(int i = 0 ; i < g.V ; i++)
    {
       subsets[i].Parent = i;
       subsets[i].Rank = 0 ;
    }

    int EdgeCount = 0;
    int i = 0;
    struct Edge Result[g.V - 1];

    while(EdgeCount < g.V - 1)
    {
       Edge newEdge = g.E[i++];
       int srcParent = find(subsets , newEdge.src);
       int destParent = find(subsets , newEdge.dest);
       cout<<srcParent << "  " << destParent << " " << i << " " << EdgeCount ;
       if(srcParent != destParent)
       {
           Result[EdgeCount++] = newEdge;
           Union(subsets , newEdge.src , newEdge.dest);
       }
       char ch; cin>>ch;
    }

    for(int i = 0 ; i < g.V - 1 ; i++)
       cout<<Result[i].src<<" "<<Result[i].dest<<" "<<Result[i].weight<<endl;;

}

int main()
{
  int V = 4;  // Number of vertices in graph
  int E = 5;  // Number of edges in graph
  struct Graph g(V , E);
  insertEdge(g , 0 , 0 , 1 , 10);
  insertEdge(g , 1 , 0 , 2 , 6);
  insertEdge(g , 2 , 0 , 3 , 5);
  insertEdge(g , 3 , 1 , 3 , 15);
  insertEdge(g , 4 , 2 , 3 , 4);
  KruskalsMST(g);
  return 0;
}
