#include <iostream>
#include<vector>
#include<string.h>

using namespace std;

void insertEdge(vector< vector<int> >& adj , int  u , int v)
{
    adj[u].push_back(v);
}
bool HamCycle(vector< vector<int> > adj , bool visit[] , int V , int source , int count)
{
   if(count == V)
     return true;
   for(vector<int> :: iterator itr = adj[source].begin() ; itr != adj[source].end() ; itr++)
   {
        cout<<"*itr = "<<*itr<<endl;
       if(visit[*itr] == false)
       {
          visit[*itr] = true;
          if(HamCycle(adj , visit , V , *itr , count + 1) == true)
             return true;
          else
          {
             visit[*itr] = false;
          }
       }
   }
   return false;
}
int main() {
	//code
	//4 4
//1 2 2 3 3 4 2 4
     int V = 4 , E = 4;
     vector< vector<int> > adj(V+1);
     insertEdge(adj , 1 , 2);
     insertEdge(adj , 2 , 3);
     insertEdge(adj , 3 , 4);
     insertEdge(adj , 2 , 4);
     bool visit[V];
     memset(visit , false , sizeof(visit));
     visit[1] = 1;
     HamCycle(adj , visit , V , 1 , 1) ? cout<<"1" : cout<< "0" ;

	/*
	int T;
	cin>>T;
	while(T--)
	{
	    int V , E;
	    cin>>V>>E;
	    vector< vector<int> > adj(V);
        while(E--)
        {
           int u , v;
           cin>>u>>v;
           insertEdge(adj , u , v);
        }
           bool visit[V+1];
           memset(visit , false , sizeof(visit));
           cout<<HamCycle(adj , visit , V , 1 , 1);



	}
	*/
	return 0;
}
