//Iterative Quick Sort
//Note : Create struct stk locally in IterativeQSort method and then
//creating its vector is not allowed, so the def of struct stk has to be
//moved outside.

#include<iostream>

#include<vector>

using namespace std;
struct stk
{
    int left;
    int right;
};

class QuickSort
{
   vector<int> a;
   public:
       QuickSort()
       {
          int n,x;
          cout<<"\n\t Enter n ="; cin>>n;
          for(int i = 0 ; i < n ; i++)
          {
             cout<<"\n\tEnter a["<<i<<"]="; cin>>x;
             a.push_back(x);
          }
       }
       void print()
       {
          cout<<"\n\t The elements are = ";
          for(int i = 0 ; i < a.size() ; i++)
            cout<<"  " << a[i];
       }
       int Partition(int low, int high)
       {
          int up, down, x;
          up = high;
          down = low;
          x = a[low];
          while(down < up)
          {
              while(a[down] <= x && down < up)
                 down++;
              while(a[up] > x)
                  up--;
              if(down < up)
                 swap(a[down], a[up]);
          }
          swap(a[low] ,a[up] );
          return up;
       }

       void IterativeQSort()
       {
          vector<stk> s;
          s.push_back(stk());
          s[0].left = 0;
          s[0].right = a.size() - 1;

          while(s.size() != 0)
          {
              stk topElement = s.back();
              s.pop_back();

              int l = topElement.left;
              int r = topElement.right;

              int  p = Partition(l , r);
              if(p-1 > l)
              {
                 s.push_back({l,p-1});
              }
              if(p+1 < r)
              {
                 s.push_back({p+1 , r});
              }
          }


       }
};
int main()
{
   QuickSort obj;
   obj.print();
   obj.IterativeQSort();
   obj.print();
   return 0;
}
