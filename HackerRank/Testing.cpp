#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string.h>

using namespace std;
int compare(const void *a, const void *b)
{
    return *(long *) a > *(long *)b;
}
void print(long a[] ,int n)
{
    for(int i = 0 ; i <  n ; i++)
        cout<<a[i]<<"  ";
    cout<<endl;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin>>T;

    while(T--)
    {
        int n;
        long k;
        cin>>n;
        cin>>k;
        long a[n] , b[n];
        for(int i = 0  ; i < n ; i++)
              cin>>a[i];
        for(int i = 0 ; i < n ; i++)
            cin>>b[i];
        cout<<"Testing1"<<endl;

        qsort(a , n , sizeof(long) , compare);
        qsort(b , n , sizeof(long) , compare);

        print(a , n); print(b , n);

        int marked[n];

        memset(marked , 0 , sizeof(marked));

        int flag = true;

        for(int i = 0 ; i < n ; i++)
        {
            long long requiredElement = k - a[i];
            int indx = 0;
            while(indx != n)
            {
                indx = lower_bound(b + indx , b+n , requiredElement) - b;
                if(marked[indx] == 0)
                {
                     marked[indx] = 1;
                     break;
                }
                if(indx + 1 == n)
                {indx = indx+1; break;}
            }
            if(indx == n)
            {
                flag = false;
                break;
            }
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        cout<<"Done1"<<endl;;


    }
    return 0;
}
