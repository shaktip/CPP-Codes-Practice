#include <iostream>
#include<limits.h>
#include<fstream>

#include<vector>

using namespace std;
int maxRow(vector< vector<int> >v , int m , int n)
{
    int maxSize = 0;
    int maxIndex = 0;
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
           cout<<"  "<<v[i][j];
        cout<<endl;
        int index = lower_bound(v[i].begin() , v[i].end() , 1) - v[i].begin();
        cout<<"Row No "<<i<<" Number of 1's = "<<n - index+1<<endl;;
        //cout<<index<<endl;
        if(index != n && maxSize < (n - index + 1))
           maxSize = n - index + 1 , maxIndex = i;
    }
    return maxIndex;
}
int main() {
    int T;
    ifstream din("TestCase.txt");
    din>>T;
    while(T--)
    {
        int m , n;
        din>>m>>n;
        vector< vector<int> > v;
        for(int i = 0 ; i < m ; i++)
        {
            vector<int> temp;
            for(int j = 0 ; j < n ; j++)
            {
                int x; din>>x;
                temp.push_back(x);
            }
            v.push_back(temp);
        }

        cout<<maxRow(v , m , n) << endl;;

    }
	//code
	return 0;
}
