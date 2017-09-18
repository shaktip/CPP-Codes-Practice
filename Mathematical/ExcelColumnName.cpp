#include<iostream>
using namespace std;
int main()
{
    int no = 26;
    string str = "";
    while(no != 0)
    {
      int r = no % 26;
      char ch;
      if(r == 0)
      {
         ch = 'Z';
         no = no / 26 - 1;
      }
      else
      {
         ch = r - 1 + 'A';
         no = no / 26;
      }
      str = ch + str;

    }
    cout<<str;
    return 0;
}
