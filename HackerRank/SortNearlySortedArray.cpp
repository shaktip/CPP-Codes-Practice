//Sort Nearly sorted array, every element is at most k positions away from its location
// Strategy: Create a min heap of size k, remove the minimum element, and insert k+1 th element
//repeat the process till n elements.
//Complexity O(nlogk)

#include<iostream>
#include<malloc.h>
using namespace std;

class Heap
{
   int *a;
   int n;
   int *heap;
   int k;
   int *output;

   public:
        Heap(int s, int k)
        {
           n = s;
           a = new int[n];
           this->k = k;
           heap = new int[k];
           output = new int[n];
        }
        void readElements()
        {
           for(int i = 0 ; i < n ; i++)
           {
              cout<<"\n\tEnter a["<<i<<"]=";
              cin>>a[i];
           }
        }
        void printInput()
        {
           cout<<"\n\t Array elements are";
           for(int i=0; i < n ; i++)
             cout<<"  "<<a[i];
        }
        void printOutput()
        {
           cout<<"\n\t Output array is ";
           for(int i = 0  ; i < n ; i++)
             cout<<"  "<<output[i];
        }
        void heapify(int i, int sz)
        {
            int x = heap[i],y,z;
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int mn = x, mnIndex = i;
            if(left < sz)
            {
               y = heap[left];
               if(mn > y)
               {
                  mnIndex = left;
                  mn = y;
               }
            }
            if(right < sz)
            {
               z = heap[right];
               if(mn > z)
               {
                  mn = z;
                  mnIndex = right;
               }
            }
            if(x != mn)
            {
                swap(heap[i], heap[mnIndex]);
                heapify(mnIndex , sz);
            }
        }
        void sortUsingHeap()
        {
            for(int i = 0 ; i < k && i < n ; i++)
                heap[i] = a[i];
            for(int i = k/2 ; i >= 0; i--)
                heapify(i , k);
            int outputIndex = 0;
            for(int i=0,j=k; j < n ; j++)
            {
                output[outputIndex++] = heap[0];
                heap[0] = a[j];
                heapify(0, k);
            }
            for(int i=k-1; i > 0 ; i--)
            {
               output[outputIndex++] = heap[0];
               heap[0] = heap[i];
               heapify(0,i);
            }
            output[outputIndex++] = heap[0];


        }
};
int main()
{
   int n,k;
   cout<<"\n\t Enter n and k :"; cin>>n>>k;

   Heap obj(n,k);
   obj.readElements();
   obj.sortUsingHeap();
   obj.printInput();
   obj.printOutput();

   return 0;
}
