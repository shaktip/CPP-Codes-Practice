#include<iostream>
using namespace std;
#define MAX 100
struct Stack
{
   int top;
   int a[MAX];
   Stack()
   {
     top = -1;
   }
};

int pop(struct Stack &s)
{
   return s.a[s.top--];
}
void push(struct Stack &s, int x)
{
   s.a[++(s.top)] = x;
}
bool isEmpty(struct Stack &s)
{
  return s.top == -1;
}
int peek(struct Stack &s)
{
  return s.a[s.top];
}
void pushInSorted(struct Stack &s, int x)
{
   if(isEmpty(s))
      push(s, x);
   else
   {
      if(peek(s) > x)
      {
           int elem = pop(s);
           pushInSorted(s , x);
           push(s , elem);
      }
      else
        push(s , x);
   }
}

void sortStack(struct Stack &s)
{
   if(!isEmpty(s))
   {
      int elem = pop(s);
      sortStack(s);
      pushInSorted(s, elem);

   }
}
void printStack(struct Stack s)
{
   cout<<"Stack elements = ";
   while(!isEmpty(s))
   {
      int elem = pop(s);
      cout<<"  "<<elem;
   }
}
int main()
{
   struct Stack s;
   push(s , 10);
   push(s , 5);
   push(s , 20);
   push(s , 3);
   push(s , 1);
   push(s , 50);
   push(s , 15);
   sortStack(s);
   printStack(s);
   return 0;
}
