#include<iostream>
#include<vector>


using namespace std;

string findLongestString(vector<string> dict, string str)
{
   int n = dict.size();
   string result = "";
   for(int i = 0 ; i < n ; i++)
   {
      string p = dict[i];
      int j , k;
      for(j = 0, k = 0 ; j < p.length() && k < str.length(); k++)
      {
         if(p[j] == str[k])
            j++;
      }
      if(j == p.length())
         if(result.length() < p.length())
           result = p;
   }
   return result;
}

int main()
{
    vector <string> dict;
    dict.push_back("ale"); dict.push_back("apple") ; dict.push_back("monkey");
    dict.push_back("plea");
    string str = "abpcplea" ;
    cout << findLongestString(dict, str) << endl;
    return 0;
}
