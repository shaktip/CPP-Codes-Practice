#include<iostream>
#include<vector>

using namespace std;

void printComb(vector<int> v , int a[] , int n , int sumTillNow)
{
   if(n == sumTillNow)
   {
      cout<<"\n\t Combination : ";
      for(vector<int> :: iterator itr = v.begin() ; itr != v.end() ; itr++)
         cout<<" "<<*itr;

   }
   for(int i = 0; i < 3 ; i++)
   {
        if(sumTillNow + a[i] <= n)
        {
            vector<int> v1(v);
            v1.push_back(a[i]);
            printComb(v1 , a, n , sumTillNow + a[i]);
        }
   }

}

int main()
{
  vector<int> v;
  int n;
  cin>>n;
  int a[] = {1,2,3};
  printComb(v , a, n , 0);
  return 0;
}
