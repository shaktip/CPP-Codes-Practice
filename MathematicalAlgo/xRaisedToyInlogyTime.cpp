//Use divide and conquer

#include<iostream>
using namespace std;
double pow(long base , int power)
{
   if(power == 0)
     return 1;
   double temp = pow(base, power / 2);
   if(power % 2 == 0)
      return temp * temp;
   else
   {
      if(power > 0)
         return temp * temp * base;
      else
         return (temp * temp) / base;
   }

}




int main()
{
   int base , power;
   cin>>base >>power;
   cout<<pow(base , power);
   return 0;
}
