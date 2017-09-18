#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;
int getNumber(char x)
{
   if(x >= '0' && x <= '9')
     return x - '0';
   return x - 'A' + 10;
}
char getAlpha(int n)
{
    if(n >= 0 && n <= 9)
       return n + '0';
    return n - 10 + 'A';

}
string addBase14(string s1 , string s2)
{
   int len1 = s1.length();
   int len2 = s2.length();
   string result = "";
   int carry = 0;
   for(int i = len1-1 , j = len2-1; i >= 0 || j >= 0 ; i--,j--)
   {
     int a = 0 , b = 0;
     if(i >= 0)
       a = getNumber(s1[i]);
     if(j >= 0)
       b = getNumber(s2[j]);
     int c = a+b+carry ;
     if(c >= 14)
     {
        c = c - 14;
        carry = 1;
     }
     else
        carry = 0;
     result = getAlpha(c) + result;
   }
   if(carry)
     result = '1' + result;
   return result;
}
#define MAX_POINTS 3
int arr[MAX_POINTS] = {1,2,3};

void print(vector<int> v)
{
   cout<<"\n\t ";
   for(int i = 0 ; i < v.size() ; i++)
   {
      cout<<v[i]<<"  ";
   }
   cout<<endl;
}
void printSol(int n, vector<int> v)
{

   if(n == 0)
   {
      print(v);
      return;
   }

   for(int i = 0 ; i < MAX_POINTS ; i++)
   {
       if(n >= arr[i])
       {
          v.push_back(arr[i]);
          printSol(n - arr[i] , v);
          v.pop_back();
       }
       else
          break;
   }
}
long power(int base , int pow)
{
  long ans = base;
  for(int i = 1 ; i < pow ; i++)
  {
     long result = 0;
     for(int j = 1 ; j <= base ; j++)
     {
         result = result + ans;
     }
     ans = result;
  }
  return ans;
}

bool isDivisible(int no)
{
   if(no == 0 || no == 7 || no == -7)
     return true;

   if(no < 0)
     isDivisible(-no);
   if(no < 10)
     return false;
   return isDivisible((no/10) - (2 * (no%10)));
}
void permute(string s ,int left  , int right)
{
  static string s1 = "";
  if(left == right /*&& s.compare(s1) != 0*/)
  {
     cout<<s<<endl;
     s1 = s;
  }
  for(int i = left ; i <= right ; i++)
  {
     //if(i == left || s[i] != s[left])
     {
      swap(s[i] , s[left]);
      permute(s , left + 1 , right);
      swap(s[i] , s[left]);
     }
  }
}
void printPermutations(string s)
{
    sort(s.begin() , s.end());
    permute(s , 0 , s.length() -1 );
}
int main()
{
/*
   string s1 = "123A45";
   string s2 = "C8B";

   cout<<"Add in base 14 : "<<addBase14(s1 , s2);
 */

 //  vector<int> v;
  // printSol(4,v);
  //cout<<" Power "<<power(5, 2);
  /*
  if(isDivisible(37))
     cout<<"True";
  else
     cout<<"False";
  */
  printPermutations("BCCA");
   return 0;

}
