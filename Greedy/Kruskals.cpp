#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>


using namespace std;

struct Edge
{
   int src;
   int dest;
   int wt;
};
int myComp(const void *a, const void *b)
{
         struct Edge *a1 = (struct Edge *)a;
         struct Edge *b1 = (struct Edge *)b;
         return a1->wt > b1->wt;
}

class Graph
{
   vector<Edge> E;
   vector<Edge> Output;
   bool *visit;
   int n ;
   int v;
   public:
       Graph()
       {
       }
       void print()
       {
           cout<<"\n\t Graph with (Src, Dest, Wt) = ";
           for(int i = 0 ; i < E.size() ; i++)
             cout<<"\n\t"<<E[i].src<<" "<<E[i].dest<<" "<<E[i].wt;
       }
       void readGraph()
       {

           cout<<"\n\t Enter number of vertices of graph ="; cin>>v;
           visit = new bool[v];
           cout<<"\n\t Enter number of edges of graph ="; cin>>n;

           int s,d,w;
           Edge temp;
           for(int i = 0 ; i < n ; i++)
           {

               cout<<"\n\t Enter source Vertex :"; cin>>s;
               cout<<"\n\t Enter Destination vertex :"; cin>>d;
               cout<<"\n\t Enter weight of edge : "; cin>>w;
               temp.src = s;
               temp.dest = d;
               temp.wt = w;
               E.push_back(temp);
               visit[s] = false;
               visit[d] = false;

           }
       }
       int Find(int parent[] , int i)
       {
          if(parent[i] == -1)
            return i;
          return Find(parent, parent[i]);
       }
       void Union(int parent[] , int x, int y)
       {
            int xset = Find(parent, x);
            int yset = Find(parent, y);
            parent[xset] = yset;

       }
       void KruskalsPath()
       {
          qsort(&E[0] , E.size() , sizeof(Edge) , myComp);
          print();
          int *parent;
          parent = new int[v];
          for(int i = 0 ; i < v ; i++)
             parent[i] = -1;

          for(int i = 0 ; i < n ; i++)
          {
             if(Find(parent , E[i].src) == Find(parent, E[i].dest))
             {
                  continue;
             }
             Union(parent, E[i].src, E[i].dest);
             Output.push_back(E[i]);

          }
          cout<<"\n\t The output is (Src , Dest , Wt)::";
          for(int i = 0 ; i < Output.size() ; i++)
             cout<<"\n\t "<<Output[i].src<<" "<<Output[i].dest<<" "<<Output[i].wt;
       }

};
int main()
{
   Graph obj;
   obj.readGraph();
   obj.print();
   obj.KruskalsPath();
   return 0;
}
