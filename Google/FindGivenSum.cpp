#include<iostream>
#include<map>

using namespace std;
void subArraySum(int arr[], int n, int sum)
{
   int curr_sum = 0;
   map<int , int> mp;
   for(int i = 0 ; i < n ; i++)
   {
      curr_sum = curr_sum + arr[i];
      if(curr_sum == sum)
      {
         cout<<"\nFound at 0 to "<<i;
         break;
      }
      if(mp.find(curr_sum - sum) != mp.end())
      {
          cout<<"\nSum found between "<<mp[curr_sum - sum] + 1 << " And "<<i;
          return;
      }
      mp[curr_sum] = i;
   }
}
int main()
{
    int arr[] = {10, 2, -2, -20, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = -20;

    subArraySum(arr, n, sum);
    return 0;
}
