#include<iostream>
#include<map>
using namespace std;

bool findSymmetricPair(int a[][2] , int rows)
{
    bool flag = false;
    map<int , int> mp;

    for(int i = 0 ; i < rows ; i++)
    {
       int first = a[i][0];
       int second = a[i][1];
       map<int , int> :: iterator temp = mp.find(second);
       if(temp != mp.end() && temp->second == first )
       {
           cout<<"\n\t("<<first<<" , "<<second<<")";
           flag = true;
       }
       if(temp == mp.end())
          mp[first] = second;
    }
    return flag;

}

int main()
{
   int a[][2] = {
         {11,20} , {30,40} , {5,10} ,{40,30} , {10,5}
        };
   int rows = sizeof(a) / (sizeof(a[0]));


   if(!findSymmetricPair(a,rows))
     cout<<"\n\t Not found";
   return 0;
}
