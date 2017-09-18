#include<iostream>
#include<string.h>
//Antology and protogy

using namespace std;
struct Trie
{
    struct Trie * next[26];
    bool leafFlag;
    Trie()
    {
       leafFlag = false;
       for(int i = 0 ; i < 26 ; i++)
          next[i] = NULL;
    }
};


void insert(Trie *root , char str[])
{
   Trie *p = root;
   for(int i = 0 ; i < strlen(str) ; i++)
   {
      if(p->next[str[i] - 'a'] == NULL)
      {
         Trie *curr = new Trie;
         //p->leafFlag = false;
         p->next[str[i] - 'a'] = curr;
      }
      p = p->next[str[i] - 'a'];
   }
   p->leafFlag =  true;

}

void traverse(struct Trie *root , string str)
{
    for(int i = 0 ; i < 26 ; i++)
    {
       if(root->next[i] != NULL)
       {
          cout<<char(i + 'a')<<endl;

          cout<< (root->next[i]->leafFlag ? 1 : 0)<<endl;;
          str = str + char(i  + 'a');
          if(root->next[i]->leafFlag)
             cout<<"---"<<str<<endl;
          traverse(root->next[i]  , str);
          str = str.substr(0, str.size() - 1);
       }
    }
}

int search(Trie *root , string str)
{
   for(int i = 0 ; i < str.size() ; i++)
   {

      if(root->next[str[i] - 'a'] != NULL)
      {
         root = root->next[str[i] - 'a'];
         //cout<<(root->leafFlag?1:0)<<"  "<<str[i]<<endl;
      }
      else
         return 0;
   }
   return root->leafFlag?1:0;
}
int main()
{
  struct Trie *root = new Trie();
  char keys[][8] = {"the", "a", "there", "answer", "any",
                     "by", "bye", "their"};
  int size = sizeof(keys) / sizeof(keys[0]);
  for(int i = 0 ; i < size ; i++)
  {
      cout<<"Inserting "<<keys[i]<<endl;
      insert(root , keys[i]);
  }
  string str = "";
  traverse(root , str);
  int flag = search(root , "Test");
  cout<<flag <<endl;
  flag = search(root , "a");
  cout<<flag <<endl;
  return 0;
}
