
//Failed on hackerrank - Timeout issues
//https://www.hackerrank.com/challenges/coin-change

#include<iostream>
#include<algorithm>

using namespace std;

long cnt = 0;
void getWays(long n, int m, long int* c,long sumTillNow, int iValue)
{
    // Complete this function
    if(sumTillNow == n)
    {

      cnt++;
      cout<<"\n\t Count is incremented "<<cnt;
      return;
    }
    for(int i = iValue ; i < m ;i++)
    {
       cout<<"\n\tSTN = "<<sumTillNow << " i = " << i << " c[i] = " << c[i];
       if(sumTillNow + c[i] <= n)
          getWays(n , m , c, sumTillNow + c[i] , i);
       else
         break;
    }
}

int comp(const void *a , const void *b)
{
  return *(long *)a > *(long *)b;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    long *c = new long[m];
    for(int c_i = 0; c_i < m; c_i++){
       cin>>c[c_i];
    }
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    qsort(c, m, sizeof(long),comp );
    getWays(n , m , c , 0 , 0);
    cout<<cnt;

    delete(c);
    return 0;
}
