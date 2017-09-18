#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

void search(char pat[] , char txt[] , int q)
{
    int m = strlen(txt);
    int n = strlen(pat);
    int d = 26;
    int h = long(pow(d , n - 1)) % q;
    int encodePat = 0 , encodeTxt = 0;
    for(int i = 0 ; i < n ; i++)
    {
       encodePat = (encodePat * d + pat[i])  % q;
       encodeTxt = (encodeTxt * d + txt[i]) % q;
    }
    for(int s = 0 ; s < m - n ; s++)
    {
       if(encodePat == encodeTxt)
       {
          bool flag = true;
          for(int i = 0 ; i < n ; i++)
             if(pat[i] != txt[s+i])
             {  flag = false;  break;}
          if(flag)
            cout<<"Pattern match found at " << s << endl;;
       }
       else
       {
          encodeTxt = ((encodeTxt - (txt[s] * h) % q) * d + txt[n + s]) % q;
       }
    }


}
int main()
{
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";
    int q = 101; // A prime number
    search(pat, txt, q);
    return 0;
}
