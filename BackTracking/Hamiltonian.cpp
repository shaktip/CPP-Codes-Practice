#include <iostream>
#include <vector>
#include<list>
#include<string.h>

//Hamiltonian Path detection, since it is path detection, you will have to test on multiple paths
//using different start vertices.
//few changes for hamiltonian cycle
//1. No need to check for different start vertex, just check for 0
//2. when all vertices are visited, then check whether currentVertex = 0 , if yes, then cycle exists,
// otherwise check other paths.

//10 14
//8 1 8 2 1 3 5 4 1 5 8 6 1 7 2 9 5 10 7 8 6 3 3 5 7 9 6 10

//10 14
//3 1 4 2 10 3 7 5 4 6 8 7 4 8 10 9 6 10 1 8 5 10 8 3 3 5 8 10


using namespace std;
bool allvisited(bool *visit , int V)
{
   for(int i = 0 ; i < V ; i++)
   {
      if(visit[i] == false)
        return false;
   }
   return true;
}
bool hamiltonian(vector< list<int> > graph, bool *visit, int V, int currentVertex)
{
   if(allvisited(visit , V))
     return true;
   list<int> currentList = graph[currentVertex];
   for(list<int> :: iterator itr = currentList.begin() ; itr != currentList.end() ; itr++)
   {
        if(visit[*itr] == false)
        {
            visit[*itr] = true;
            if(hamiltonian(graph, visit, V , *itr) == true)
              return true;
            visit[*itr] = false;
        }
   }
   return false;


}
int main() {
	//code

	int T, V , E;
	cin>>T;
	while(T--)
	{
	    cin>>V>>E;
	    int u,v;
	    vector< list<int> > graph;

	    bool *visit;
	    visit = new bool[V];
	    memset(visit, false, V*sizeof(bool));

	    for(int i = 0 ; i < V ; i++)
	       graph.push_back(list<int>());

	    for(int i = 0 ; i < E; i++)
	    {
	        cin>>u>>v;
	        graph[u-1].push_back(v-1);
	        graph[v-1].push_back(u-1);
	    }
	    bool flag = false;
	    for(int i = 0 ; i < V ; i++)
	    {
	      visit[i] = true;
	      if(hamiltonian(graph, visit,  V, i))
	      {
            flag = true;
 	        cout<<"1"<<endl;
 	        break;
	      }
          else
            memset(visit, false , V*sizeof(bool));
        }
        if(!flag)
          cout<<"0"<<endl;
        delete(visit);
	}

	return 0;
}
