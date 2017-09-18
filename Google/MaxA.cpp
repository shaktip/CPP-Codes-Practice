#include<iostream>
using namespace std;

int findoptimal(int N)
{
   if(N <= 6)
     return N;
   int screen[N];

   for(int i = 1 ; i <= 6 ; i++)
     screen[i - 1] = i;
   for(int i = 7 ; i <= N ; i++)
   {
       screen[i-1] = 0;
       for(int b = i - 3 ; b >= 1 ; b--)
       {
          int curr = (i - b - 1) * screen[b - 1];
          if(screen[i-1] < curr)
            screen[i-1] = curr;
       }
   }
   return screen[N - 1];
}
int main()
{
   int N;

    // for the rest of the array we will rely on the previous
    // entries to compute new ones
    for (N=1; N<=20; N++)
        cout<<"Maximum Number of A's with "<< N << " keystrokes is " <<
               findoptimal(N) << endl;

}
