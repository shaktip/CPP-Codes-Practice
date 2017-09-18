#include<iostream>
#include<queue>

using namespace std;
int getMin(queue<int> q2, queue<int> q3, queue<int> q5)
{
    int minElement;
    if(q2.front() < q3.front())
       minElement = q2.front();
    else
       minElement = q3.front();
    if(minElement > q5.front())
       minElement = q5.front();
    return minElement;

}
int getNthUglyNo1(int n)
{
   queue<int> q2,q3,q5;
   int count = 0;


   int minElement = 1;
   while(count < n)
   {
       q2.push(minElement * 2);
       q3.push(minElement * 3);
       q5.push(minElement * 5) ;
       if(minElement == q2.front())
         { q2.pop();  }
       if(minElement == q3.front())
         {q3.pop();  }
       if(minElement == q5.front())
         {q5.pop();  }
       count++;
       if(count == n)
         break;
       cout<<"count = "<<count<<" MinElement = "<<minElement<<endl;
       minElement = getMin(q2,q3,q5);
   }
   return minElement;
}


unsigned getNthUglyNo(unsigned n)
{
    unsigned ugly[n]; // To store ugly numbers
    unsigned i2 = 0, i3 = 0, i5 = 0;
    unsigned next_multiple_of_2 = 2;
    unsigned next_multiple_of_3 = 3;
    unsigned next_multiple_of_5 = 5;
    unsigned next_ugly_no = 1;

    ugly[0] = 1;
    for (int i=1; i<n; i++)
    {
       next_ugly_no = min(next_multiple_of_2,
                           min(next_multiple_of_3,
                               next_multiple_of_5));
       ugly[i] = next_ugly_no;
       if (next_ugly_no == next_multiple_of_2)
       {
           i2 = i2+1;
           next_multiple_of_2 = ugly[i2]*2;
       }
       if (next_ugly_no == next_multiple_of_3)
       {
           i3 = i3+1;
           next_multiple_of_3 = ugly[i3]*3;
       }
       if (next_ugly_no == next_multiple_of_5)
       {
           i5 = i5+1;
           next_multiple_of_5 = ugly[i5]*5;
       }
       cout<<"i ="<<i<<" NextUglyNo = "<<next_ugly_no<<endl;
    } /*End of for loop (i=1; i<n; i++) */
    return next_ugly_no;
}
int main()
{
    int n = 150;
    cout << getNthUglyNo1(n);
    return 0;
}
