#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;
bool NoOfUniques(int count[] , int k)
{
  int u = 0;
  for(int i = 0 ; i < 26 ; i++)
    if(count[i] != 0)
      u++;
  return u >= k;
}
void kUniques(string s , int k)
{


    int u = 0;
    int count[26] = {0};
    for(int i = 0 ; i < s.length() ; i++)
       if(count[s[i] - 'a'] == 0)
          u++;
    if(u < k)
    {
      cout<<"Solution not possible";
      return ;
    }
    memset(count , 0  , sizeof(count));
    int left = 0 , right = 0, len = 1 , unique = 1;
    count[s[0] - 'a']++;
    int leftR = 0 , rightR = 0;
    for(int i = 1 ; i < s.length()  ; i++)
    {

        if(count[s[i] - 'a'] == 0)
        {

           if(unique < k)
              unique++;
           else
           {
              while(left < right && NoOfUniques(count , k) )
              { count[s[left] - 'a']--; left++;}

              unique--;
           }
        }
        count[s[i] - 'a']++;
        right++;

        if(len < right - left + 1)
        {
           leftR = left ; rightR = right;
           len = right - left + 1;
        }
        cout<<"At i = " << i << " Unique " << unique<<endl;;
        cout<<" Left "<<left<< " Right" << right<<endl;;
        cout<<" Length "<< len<<endl;;

    }
    cout<<"Length is = "<<len<<" From "<<leftR<< " To "<<rightR;
}



int main()
{
    string s = "aabacbebebe";

    int k = 3;
    kUniques(s, k);
    return 0;
}

