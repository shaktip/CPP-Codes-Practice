#include <iostream>
using namespace std;

int main() {

        int N;
	    cin>>N;
	    int a[N][N];
	    for(int i = 0 ; i < N ; i++)
	    {
	        for(int j = 0 ; j < N ; j++)
	        {
	            cin>>a[i][j];
	        }
	    }
	    for(int i = 0 ; i < N ; i++)
	    {
	        for(int j = i + 1; j < N ; j++)
	        {
	            int temp = a[i][j];
	            a[i][j] = a[j][i];
	            a[j][i] = temp;
	        }
	    }
	    for(int j = 0 ; j < N ; j++)
	    {
	        for(int i = 0 ; i < N / 2; i++)
	        {
	            int temp = a[i][j];
	            a[i][j] = a[N-i-1][j];
	            a[N-i-1][j] = temp;
	        }
	    }
	    for(int i = 0 ; i < N ; i++)
	    {
	        for(int j = 0 ; j < N ; j++)
	          cout<<a[i][j] <<" ";
	    }
	    cout<<endl;

	return 0;
}
