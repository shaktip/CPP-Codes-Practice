#include <iostream>
#include<map>
using namespace std;

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int N;
	    int Sum ;
	    map<int , int> mp;
	    cin>>N >> Sum;
	    int a[N];
	    int count = 0;
	    for(int i = 0 ; i < N ; i++)
	    {
	        cin>>a[i];
	        if(mp.find(Sum - a[i]) != mp.end())
	        {    count += mp[Sum - a[i]];  cout<<"\n Pair "<<a[i]<<" , "<<Sum-a[i]<<" "<<mp[Sum-a[i]];}
	        else
	            mp[a[i]] = 0;
	        mp[a[i]] += 1;
	    }
	    for(int i = 0 ; i < N ; i++)
	    {
	       int s = Sum - a[i];
	       for(int j = i + 1; j < N ;j++)
	         if(s == a[j])
	           cout<<a[i]<<" "<<a[j]<<endl;
	    }
	    cout<<count<<endl;
	}
	return 0;
}
