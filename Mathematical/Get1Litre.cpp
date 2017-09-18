#include<iostream>
using namespace std;
struct vessel
{
   int capacity; int current;
   vessel(int cap){capacity = cap ; current = 0;}
};
int gcd(int a, int b)
{
  return b ? gcd(b , a % b) : a;
}
void printSol(vessel v1 , vessel v2)
{
   if(gcd(v1.capacity , v2.capacity) != 1)
   {
     cout<<"Solution is not possible";
     return;
   }
   while(v1.current != 1)
   {
        if(v1.current == 0)
          v1.current = v1.capacity;
        cout<<"V1 current = "<<v1.current << " V2 Current = " << v2.current << endl;;
        //char ch; cin>>ch;
        if(v2.capacity - v2.current >= v1.current)
        {
           v2.current = v2.current + v1.current;
           v1.current = 0;
        }
        else
        {
           v1.current = v1.current - (v2.capacity - v2.current);
           v2.current = 0;
        }
        if(v2.current == v2.capacity)
          v2.current = 0;

   }
   cout<<"V1 current = "<<v1.current << " V2 Current = " << v2.current << endl;;
}
int main()
{
   vessel v1(9) , v2(7);
   printSol(v1 , v2);
   return 0;
}
