#include <iostream>
using namespace std;

/*
Given an unsorted array arr[0..n-1] of size n,
find the minimum length subarray arr[s..e] such that sorting this subarray makes
the whole array sorted.
*/

int getMin(int x, int y)
{
    if(x < y)
      return x;
    return y;
}
int getMax(int x, int y)
{
   if(x > y)
     return x;
   return y;
}
int main() {
	//code
	int T;
	cin>>T;
	int i,startIndex, endIndex;

	while(T)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(i = 0 ; i < n ; i++)
	      cin>>a[i];

	    for(i = 1 ; i < n ; i++)
	        if(a[i] < a[i-1] )
	           break;

	    startIndex = i-1;
	    //cout<<startIndex<<"\n";
	    if(i < n)
	    {
	      int min = a[i];
	      for(; i < n ; i++)
	      {
	        if(min > a[i])
	           min = a[i];
	      }
	      while(a[startIndex] > min && startIndex >=0)
	        startIndex--;

	      startIndex+=1;
	    }

	    for(i=n-2; i >= 0 ; i--)
	       if(a[i] > a[i+1])
	          break;
	    endIndex = i+1;
	    if(i >= 0)
	    {
	      int max = a[i];
	      for(; i>=0 ; i--)
	        if(max < a[i])
	           max = a[i];
	    //cout<<endIndex<<"\n";
	      while(max > a[endIndex] && endIndex < n )
	         endIndex++;
	      endIndex -= 1;
	    }
	    cout<<startIndex<<" "<<endIndex<<"\n";
	    T--;
	}
	return 0;
}
