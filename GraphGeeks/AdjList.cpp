//Adjacency List for Graph Representation
#include<iostream>
#include<queue>
#include<stack>


using namespace std;

struct NodeList
{
   int data;
   NodeList *next;
   NodeList(int d)
   {
     data = d; next = NULL;
   }
};
struct Graph
{
   int V;
   NodeList **headArray;
   Graph(int v)
   {
      V = v;
      headArray = new NodeList*[V];
      for(int i = 0 ; i < V ; i++)
      {
        headArray[i] = NULL;
      }
   }
};
void printGraph(Graph g)
{
   for(int i = 0 ; i < g.V ; i++)
   {
      NodeList *tr = g.headArray[i];
      while(tr)
      {
         cout<<" "<<tr->data;
         tr = tr->next;
      }
      cout<<"\n";
   }
}
Graph createGraph(int V)
{
    Graph g(V);
    return g;
}
void insertEdge(Graph g , int u , int v)
{
    NodeList *tr = g.headArray[u];
    if(tr == NULL)
    {
       g.headArray[u] = new NodeList(v);
    }
    else
    {
      while(tr->next)
        tr = tr->next;
      tr->next = new NodeList(v);
    }
    tr = g.headArray[v];
    if(tr == NULL)
    {
        g.headArray[v] = new NodeList(u);
    }
    else
    {
       while(tr->next)
          tr = tr->next;
       tr->next = new NodeList(u);
    }
}
void DFSUtil(Graph g , bool visited[] , int vertex)
{
   visited[vertex] = true;
   cout<<vertex<<"  ";
   NodeList *tr = g.headArray[vertex];
   while(tr)
   {
       if(visited[tr->data] == false)
          DFSUtil(g , visited , tr->data);
       tr = tr->next;
   }
}
void DFS(Graph g)
{
  bool visited[g.V];
  for(int i = 0 ; i < g.V ; i++)
     visited[i] = false;

  for(int i = 0 ; i < g.V ; i++)
  {
     if(visited[i] == false)
       { DFSUtil(g , visited , i);}
  }
}
void BFSUtil(Graph g , bool visited[] , int i)
{
   queue<int> q ;
   q.push(i);
   while(!q.empty())
   {
     i = q.front(); q.pop();
     if(visited[i] == false)
     {  visited[i] = true;
        cout<<" " << i;
     }
     NodeList *tr = g.headArray[i];
     while(tr)
     {
      if(visited[tr->data] == false)
        q.push(tr->data);
      tr = tr->next;
     }
   }
}
void BFS(Graph g)
{

    bool visited[g.V];
    for(int i = 0 ;i < g.V ; i++)
       visited[i] = false;
    for(int i = 0 ; i < g.V ; i++)
    {
        if(visited[i] == false)
           BFSUtil(g , visited , i);
    }
}
void TopologicalOrdering(Graph g , stack<int> &s , bool visited[] , int vertex)
{
    visited[vertex] = true;
    NodeList *tr = g.headArray[vertex];
    while(tr)
    {
       if(visited[tr->data] == false)
          TopologicalOrdering(g , s , visited , tr->data);
       tr = tr->next;
    }
    s.push(vertex);
}
void TopologicalSort(Graph g)
{
    stack<int> stk;
    bool visited[g.V];
    for(int i = 0 ; i < g.V ; i++)
       visited[i] = false;
    for(int i = 0 ; i < g.V ; i++)
    {
       if(visited[i] == false)
          TopologicalOrdering(g , stk , visited , i);
    }
    while(!stk.empty())
    {
        int x = stk.top() ; stk.pop();
        cout<<"  "<< x;
    }
}
void DFSIterativeUtil(Graph g , bool visited[] , stack<int> &s , int vertex)
{

  s.push(vertex);
  while(!s.empty())
  {
      vertex = s.top() ; s.pop();
      if(visited[vertex] == false)
      {
        visited[vertex] = true;
        cout<<"  "<<vertex;
      }
      NodeList *itr = g.headArray[vertex];
      while(itr)
      {
          if(visited[itr->data] == false)
          {
             s.push(itr->data);
          }
          itr = itr->next;
      }
  }
}
void DFSiterative(Graph g)
{
   stack<int> stk;
   bool visited[g.V];
   for(int i = 0 ; i < g.V ; i++)
      visited[i] = false;
   for(int i = 0 ; i < g.V ; i++)
   {
      if(visited[i] == false)
         DFSIterativeUtil(g , visited , stk , i);
   }
}
bool CheckCycle(Graph g , bool visited[] , int vertex , int parent)
{
   visited[vertex] = true;
   NodeList *tr = g.headArray[vertex];
   while(tr)
   {
      if(visited[tr->data] == false)
          CheckCycle(g , visited , tr->data , vertex);
      else  if(tr->data != parent)
        return true;
      tr = tr->next;
   }
   return false;
}
bool detectCycle(Graph g)
{
    bool visited[g.V];
    for(int i = 0 ; i < g.V ; i++)
        visited[i] = false;
    for(int i = 0 ; i < g.V ; i++)
    {
       if(visited[i] == false)
       {
          if(CheckCycle(g , visited , i , -1) == true)
            return true;
       }
    }
    return false;
}
int main()
{
   Graph g = createGraph(5);
   //insertEdge(g , 5 , 0);
   //insertEdge(g , 5 , 2);
   //insertEdge(g , 4 , 0);
   //insertEdge(g , 4 , 2);
   //insertEdge(g , 2 , 3);
   //insertEdge(g , 1 , 3);
   //insertEdge(g , 3 , 4);
   insertEdge(g , 1 , 0);
   insertEdge(g , 2, 1);
   insertEdge(g , 3 , 4);
   insertEdge(g , 4 , 0);
   insertEdge(g , 2 , 3);
   printGraph(g);
   cout<<"\n\t Graph Traversal - DFS - "; DFS(g);
   cout<<"\n\t Graph Traversal - BFS - "; BFS(g);
   cout<<"\n\t Topological ordering "; TopologicalSort(g);
   cout<<"\n\t Iterative DFS "; DFSiterative(g);

   if(detectCycle(g))
     cout<<"\nCycle Exist";
   else
     cout<<"\nCycle does not Exist";
   return 0;
}
