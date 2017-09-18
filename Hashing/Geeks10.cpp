#include<iostream>
#include<map>
#include<list>


using namespace std;

void findReverseMap(map<string, list<string> > &revMap, map<string, string> mp)
{
   for(map<string, string> :: iterator itr = mp.begin() ; itr!= mp.end(); itr++)
   {
       //if(revMap.find(itr->first) == revMap.end())
       //      revMap[itr->first] = list;
       revMap[itr->second].push_back(itr->first);
   }
}
void display(map<string, list<string> > revMap)
{
   for(map<string, list<string> > :: iterator x = revMap.begin() ; x != revMap.end() ; x++)
   {
       cout << "\n" << x->first << " --> ";
       list<string> temp = x->second;
       for(list<string> :: iterator itr = temp.begin() ; itr != temp.end() ; itr++)
         cout<<"  " << *itr;

   }
}
int getCount(map<string, list<string> > revMap , string p)
{
   if(revMap.find(p) == revMap.end())
     return 0;
   int cnt = 0;

   list<string> temp = (revMap.find(p))->second;
   cnt = cnt + temp.size();
   for(list<string> :: iterator itr = temp.begin() ; itr != temp.end() ; itr++)
   {
      if(*itr != p)
        cnt = cnt + getCount(revMap , *itr);
      else
        cnt = cnt - 1;
   }
   return cnt;
}
int main()
{
   map<string, string> mp;
   mp["A"] = "C";
   mp["B"] = "C";
   mp["C"] = "F";
   mp["D"] = "E";
   mp["E"] = "F";
   mp["F"] = "F";
   map<string , list<string> > reverseMap;
   findReverseMap(reverseMap , mp);
   display(reverseMap);

   for(map<string, string > :: iterator itr = mp.begin() ;
        itr != mp.end() ; itr++)
   {
        cout<<"\n\t";
        cout<<" For " << itr->first << " Count is " << getCount(reverseMap, itr->first);
   }
   return 0;

}
