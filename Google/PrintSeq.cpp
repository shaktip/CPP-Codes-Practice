#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

void print(string str)
{
  queue<string> q;
  q.push(str);
  while(!q.empty())
  {
     string str = q.front() ; q.pop();
     int i = 0;
     while(i < str.length() && str[i] != '?')
         i++;
     if(i < str.length())
     {
         str[i] = '0';
         string str1 = str;
         str[i] = '1';
         string str2 = str;
         q.push(str1); q.push(str2);
     }
     else
        cout<<"\n"<<str;
  }
}
int main()
{
    string str = "1??0?101";

    print(str);

    return 0;
}
