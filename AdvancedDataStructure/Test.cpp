#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Trie
{
    struct Trie *next[10];
    bool isLeaf;
    Trie()
    {
        for(int i = 0 ; i < 10 ; i++)
            next[i] = NULL;
         isLeaf = false;
    }
};
bool insert(Trie *root, string s)
{
    bool flag  = false;
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(root->next[s[i] - 'a'] == NULL)
        {
            root->next[s[i] - 'a'] = new Trie();
            flag = true;
        }
        else
        {
            if(root->next[s[i] - 'a']->isLeaf)
                  return false;

        }
        root = root->next[s[i] - 'a'];
    }
    if(flag == false)
      return false;
    root->isLeaf = true;
    return true;
}

#include<fstream>
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ifstream din;
    din.open("TrieInput1.txt");
    int n;
    din>>n;
    Trie *root = new Trie();
    while(n--)
    {
        string s;
        din>>s;
        cout<<"Read string "<<s; char ch; cin>>ch;
        if(insert(root , s) == false)
         {  cout<<"BAD SET\n"<<s; break; }
    }

    if(n == 0)
        cout<<"GOOD SET";
    return 0;
}
