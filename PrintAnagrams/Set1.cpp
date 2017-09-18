#include<iostream>
#include<algorithm>

using namespace std;
struct Arr
{
   string word;
   int indx;

};
int cmp(Arr a , Arr b)
{
    //string *p = (string *)a;
    //string *q = (string *)b;
    string first = a.word , second = b.word;
    return (first.compare(second) <= 0) ;
}
void printArr(Arr arr[] , int size)
{
   for(int i = 0 ; i < size; i++)
      cout<<arr[i].word<<" "<<arr[i].indx<<endl;;
   cout<<endl;
}
int compare(char a, char b)
{
  return a <= b;
}
string sortWord(string word)
{
    sort(word.begin() , word.end() , compare);
    return word;
}
void printWordsFromOriginalArray(string words[] , Arr arr[] , int size)
{
   cout<<"Anagrams together => ";
   for(int i = 0 ; i < size ; i++)
      cout<<(words[arr[i].indx])<< "  ";
}
void printAnagramsTogether(string words[] , int size)
{
  Arr arr[size];

  for(int i = 0 ; i < size; i++)
     arr[i].word = sortWord(words[i]) , arr[i].indx = i;
  sort(arr , arr+size , cmp);
  printArr(arr , size);
  printWordsFromOriginalArray(words , arr , size);
}
int main()
{
    string wordArr[] = {"cat", "dog", "tac", "god", "act"};
    int size = sizeof(wordArr) / sizeof(wordArr[0]);
    printAnagramsTogether(wordArr, size);
    return 0;
}
