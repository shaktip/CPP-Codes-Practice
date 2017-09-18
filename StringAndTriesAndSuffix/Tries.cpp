#include<iostream>
#define No_Of_Chars 256
using namespace std;

struct Trie
{
   struct Trie *a[No_Of_Chars];
   bool isLeaf;
   Trie()
   {
      for(int i = 0 ; i < No_Of_Chars ; i++)
         a[i] = NULL;
      isLeaf = false;
   }
};

void insert_(Trie *root, string key)
{
    int N = key.length();
    Trie *tr = root;
    for(int i = 0 ; i < N ;i++)
    {
        if(tr->a[key[i]] == NULL)
        {
           Trie *newNode = new Trie();
           tr->a[key[i]] = newNode;
        }
        tr = tr->a[key[i]];
    }
    tr->isLeaf = true;
}
bool search_(Trie *root, string key)
{
  int N = key.length();
  Trie *tr = root;

  for(int i = 0 ; i < N ; i++)
  {
      if(tr->a[key[i]] != NULL)
         tr = tr->a[key[i]];
      else
         return false;
  }
  return tr->isLeaf;
}
int main()
{
  struct Trie *root = new Trie;
  string keys[] = {"This","test","testing","the","example","of","trie","and","its","implementation"};
  int N = 10;
  for(int i = 0 ; i < N ; i++)
      insert_(root, keys[i]);
  string test_keys[] = {"This","is","testing" , "values","available","or","not","and","nothing","test"};
  for(int i = 0 ; i < N ; i++)
      cout<<" Key = "<<test_keys[i]<<(search_(root, test_keys[i]) ? " Found" : " Not Found")<<endl;

  return 0;
}


