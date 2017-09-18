#include<iostream>
#include<string.h>

using namespace std;

struct Trie
{
   struct Trie *next[26];
   bool isLeaf;
   Trie()
   {
      for(int i = 0 ; i < 26 ; i++)
         next[i] = NULL;
      isLeaf = false;
   }
};

void insert(struct Trie *root , string s)
{
   for(int i = 0 ; i < s.size() ; i++)
   {
       int indx = int(s[i] - 'a');
       if(root->next[indx] == NULL)
          root->next[indx] = new Trie();
       root = root->next[indx];
   }
   root->isLeaf = true;
}

void print(struct Trie *root , string str)
{
    for(int i = 0 ; i < 26 ; i++)
    {
       if(root->next[i] != NULL)
       {
          str = str + char('a' + i);
          if(root->next[i]->isLeaf)
             cout<<str<<endl;
          print(root->next[i] , str);
          str = str.substr(0 , str.size() - 1);
       }
    }
}
string longestPrefix(Trie *root , string s)
{
   string maxOutput = "";
   string str;
   for(int i = 0 ; i < s.size() ; i++)
   {
      if(root->next[s[i]-'a'] != NULL)
      {
          str = str + s[i];
          if(root->next[s[i] - 'a']->isLeaf)
          {
             maxOutput = str;
          }
          root = root->next[s[i] - 'a'];
      }
      else
      {
        break;
      }
   }
   if(maxOutput.size() == 0)
       maxOutput = "Not found";
   return maxOutput;
}
int main()
{
   Trie *root = new Trie;
   insert(root, "are");
   insert(root , "area");
   insert(root , "base");
   insert(root , "cat");
   insert(root , "cater");
   insert(root , "basement");
   string str = "";
   print(root , str);
   cout<<"\n\tLongest prefix of caterer = "<<longestPrefix(root, "caterer");
   cout<<"\n\tLongest prefix of basement = "<<longestPrefix(root, "basement");
   cout<<"\n\tLongest prefix of are = "<<longestPrefix(root, "are");
   cout<<"\n\tLongest prefix of cyz = "<<longestPrefix(root, "cyz");
   cout<<"\n\tLongest prefix of arex = "<<longestPrefix(root, "arex");
   cout<<"\n\tLongest prefix of basemexz = "<<longestPrefix(root, "basemexz");

   return 0;
}
