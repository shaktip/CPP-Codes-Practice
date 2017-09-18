#include<iostream>
#include<malloc.h>
#include<string.h>

//Graphs - BFS
using namespace std;
struct Nodes
{
   int data;
   struct Nodes *next;
   Nodes(int d)
   {
     data = d;
     next = NULL;
   }
};
struct NodeHead
{
   struct Nodes *head;
};

struct Graph
{
  int V;
  struct NodeHead *heads;
  Graph(int v)
  {
     V = v;
     heads = new NodeHead[V];
     for(int i = 0 ; i < V ;i++)
        heads[i].head = NULL;
  }
};
void printGraph(struct Graph* g)
{
  int i ;
  for(i = 0 ; i < g->V ;i++)
  {
     struct NodeHead heads = g->heads[i];
     struct Nodes *p = heads.head;
     cout<<"List of "<<i<<" Node = ";
     while(p != NULL)
     {
       cout<<p->data << "  ";
       p = p->next;
     }
     cout<<"\n\t";

  }
}
Graph* createGraph(int v)
{
   Graph* g = new Graph(v);
   printGraph(g);
   return g;
}
void addEdge(Graph* g , int source , int dest)
{
   if(source > g->V || dest > g->V)
   {
     cout<<"Invalid Edge";
     return;
   }

   struct Nodes *p = new Nodes(dest);
   p->next = g->heads[source].head;
   g->heads[source].head = p;

   struct Nodes *q = new Nodes(source);
   q->next = g->heads[dest].head;
   g->heads[dest].head = q;


}
#define MAX 500
void performBFS(Graph *g ,bool visit[] , int source)
{
   visit[source] = true;

   cout<<source<<" ";
   struct Q
   {
      int fr , rear;
      int a[MAX];
      Q()
      {
        fr = rear = 0;
      }
   };
   Q q;
   q.a[q.rear++] = source;
   while(q.fr != q.rear)
   {
      int s = q.a[q.fr++];
      struct Nodes *tr = g->heads[s].head;
      while(tr != NULL)
      {
         if(!visit[tr->data])
         {
           q.a[q.rear++] = tr->data;
           visit[tr->data] = true;
           cout<<tr->data<<" ";
         }
           tr = tr->next;

      }
   }
}
void BFS(Graph *g)
{
   bool visit[g->V];
   memset(visit , false , g->V *sizeof(bool));
   cout<<"BFS list : ";
   for(int i = 0 ; i < g->V ; i++)
   {
       if(visit[i] == false)
          performBFS(g, visit, i);
   }

}

void performDFS(Graph *g , bool visit[], int source)
{
    visit[source] = true;
    cout<<source << "  ";
    struct Nodes *tr = g->heads[source].head;
    while(tr != NULL)
    {
       if(visit[tr->data] == false)
       {
          performDFS(g , visit, tr->data);
       }
       tr = tr->next;
    }
}

void DFS(Graph *g)
{
   bool visit[g->V];
   memset(visit , false, g->V * sizeof(bool));
   cout<<" DFS list :";
   for(int i = 0 ; i < g->V ;i++)
   {
      if(visit[i] == false)
        performDFS(g , visit , i);
   }
}
int main()
{
  int v = 9;
  //cout<<"Enter number of vertices :"; cin>>v;
  Graph* g = createGraph(v);
  addEdge(g , 0, 1);
  addEdge(g, 0, 7);

  addEdge(g , 1, 2);
  addEdge(g, 1, 7);

  addEdge(g , 2, 3);
  addEdge(g, 2, 5);
  addEdge(g, 2, 5);

  addEdge(g, 3, 4);
  addEdge(g, 3, 5);

  addEdge(g, 4, 5);

  addEdge(g, 5, 6);

  addEdge(g, 6, 7);
  addEdge(g, 6, 8);

  addEdge(g, 7, 8);

  printGraph(g);
  BFS(g);
  DFS(g);
  return 0;
}
