//Find number of nodes in SLL - using iterative and recursive.

#include<iostream>
using namespace std;

struct SLL
{
   int data;
   struct SLL *next;
};

int countNodes(struct SLL *head)
{
  int cnt = 0 ;
  while(head != NULL)
  {
     cnt++;
     head = head->next;
  }
  return cnt;
}

int countNodesRec(struct SLL *head)
{
    static int cnt = 0;
    if(head == NULL)
      return cnt;
    cnt++;
    return countNodesRec(head->next);

}


void print(struct SLL *head)
{
   cout<<"\n\t";
   while(head != NULL)
   {
      cout<<head->data<<"  " ;
      head = head->next;
   }
}

int Search(struct SLL *head , int x)
{
   if(head == NULL)
      return 0;
   if(head->data == x)
      return 1;
   return Search(head->next , x);
}
struct SLL * swapNodesOfData(struct SLL *head , int x, int y)
{
   struct SLL *first = head , *second = head;
   if(head->next == NULL)
     return head;
   if(x == y)
     return head ;
   struct SLL *p = head , *q = head;
   if(head->data != x)
   {
      while(p->next != NULL && p->next->data != x)
         p = p->next;
      if(p->next == NULL)
      {
         cout<<x<<" Not found";
         return head;
      }
   }

   if(head->data != y)
   {
      while(q->next != NULL && q->next->data != y)
         q = q->next;
      if(q->next == NULL)
      {
         cout<<y<<" Not found";
         return head;
      }
   }

   if((head->data == x && q != head) || (p != head && head->data == y))
   {
      if(p == head)
         p = q;
      //Exchange head and next of p
      struct SLL *t1 = p->next;
      struct SLL *t2 = t1->next;
      t1->next = head->next;
      p->next = head;
      head->next = t2;
      head = t1;
      return head;
   }
   struct SLL *t1 , *t2;
   t1 = p->next;
   t2 = q->next;
   p->next = t2;
   q->next = t1;
   struct SLL *t3 = t1->next;
   t1->next = t2->next;
   t2->next = t3;
   return head;



}

struct SLL * FindMiddle(struct SLL *head)
{
   struct SLL *slowPointer ,*fastPointer;
   slowPointer = fastPointer = head;
   while(fastPointer && fastPointer->next)
   {
      slowPointer= slowPointer->next;
      fastPointer = fastPointer->next;
      if(fastPointer)
         fastPointer = fastPointer->next;
   }
   return slowPointer;

}
struct SLL * deleteSLL(struct SLL *head)
{
   struct SLL *p , *q;
   p = head;
   q = head->next;
   while(p != NULL)
   {
       cout<<"\n\tDeleting p->data = "<<p->data;
       delete(p);
       p = q;
       if(q)
        q = q->next;
   }

   head = NULL;
   return head;
}
struct SLL * ReverseSLL(struct SLL *head)
{
    struct SLL *a, *b ,*c;
    a = head;
    b = a->next;
    if(b)
      c = b->next;
    while(b != NULL)
    {
       b->next = head;
       a->next = c;
       head = b;
       b = c;
       if(c)
         c = c->next;
    }
    return head;
}


bool DetectingLoop(struct SLL *head)
{
   struct SLL *a, *b;

   a = b = head;

   while( a != NULL )
   {

      a = a->next;

      if(b && b->next)
      {
        b = b->next->next;
        if(a == b)
          return true;
      }
      else
        return false;
   }
   if(a == NULL)
     return false;

   return true;
}


int main()
{
   struct SLL *first = new SLL;
   struct SLL *second = new SLL;
   struct SLL *third = new SLL;
   struct SLL *fourth = new SLL;
   struct SLL *fifth = new SLL;
   struct SLL *sixth = new SLL;
   first->data = 10;
   first->next = second;
   second->data = 20;
   second->next = third;
   third->data = 30;
   third->next = fourth;
   fourth->data = 40;
   fourth->next = fifth;
   fifth->data = 50;
   fifth->next = NULL;
   /*
   fifth->next = sixth;
   sixth->data = 60;
   sixth->next = NULL;
*/
   print(first);
   cout<<"\n\t"<<countNodes(first);
   cout<<"\n\t"<<countNodesRec(first);
   cout<<"\n\t Search 3 = "<<Search(first , 30);
   cout<<"\n\t Search 10 = "<<Search(first , 100);
   first = swapNodesOfData(first , 10 , 40);
   print(first);
   struct SLL *p = FindMiddle(first);
   if(p != NULL)
      cout<<"Middle node = "<<p->data;
   //first = deleteSLL(first);
   //print(first);
   //first = ReverseSLL(first);
   //cout<<"\n\tAfter reverse = ";
   print(first);

   fifth->next = third;

   if(DetectingLoop(first))
     cout<<"\n\t Cycle exist ";
   else
     cout<<"\n\t Cycle does not exist ";
   return 0;
}
