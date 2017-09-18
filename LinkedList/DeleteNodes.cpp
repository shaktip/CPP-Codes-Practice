#include<iostream>
using namespace std;
//Delete nodes which have higher values than it on right side
//Technique
//1. Reverse the linked list
//2. Consider the first one as the highest, and start traversing from second node
//3. Any node having value higher than max , change the max.
//4. Any node having value less than max, delete it.
//10 20 30 40 50 6 5 4 3 2 30
//Reverse is => 30 2 3 4 5 6 50 40 30  20 10
//              30 , delete 2 , delete 3 , delete 4 , delete 5 , delete 6, 50 , delete 40 , delete 30
//       delete 20 , delete 10.
//     30 , 50
//reverse the linked list => 50 30

struct SLL
{
  int data;
  struct SLL *next;
};

void reverseLL(struct SLL **head)
{

   struct SLL *h = *head;
   if(!h || !(h->next))
     return;
   struct SLL *hnext = h->next;
   h->next = NULL;
   struct SLL *nextNode = hnext->next;

     while(hnext)
    {
     hnext->next = h;
     *head = hnext;
     h = hnext;
     hnext = nextNode;
     if(nextNode)
        nextNode = nextNode->next;
    }

}

struct SLL * pushToNext(struct SLL **head, int x)
{
   struct SLL *h = *head;
   struct SLL *p = new SLL;

   p->data = x;
   p->next = NULL;

   if(h == NULL )
      *head = p;
   else
      h->next = p;
   return p;
}
void print(struct SLL *head)
{
   cout<<"\n\t The linked list is = ";
   while(head)
   {
      cout<<head->data<<" ";
      head = head->next;
   }
}
void deleteNodes(struct SLL **head)
{
   struct SLL *h = *head;
   if(!h)
     return;
   int mx = h->data;
   struct SLL *tr = h->next;
   struct SLL *pr = h;
   while(tr)
   {
      if(tr->data > mx)
      {
         mx = tr->data;
         tr = tr->next;
         pr = pr->next;
      }
      else if(tr->data < mx)
      {
         pr->next = tr->next;
         delete(tr);
         tr = pr->next;
      }
   }
}
void deleteNodesHavingGreaterValuesOnRHS(struct SLL **head)
{
    reverseLL(head);
    deleteNodes(head);
    reverseLL(head);

}
int main()
{
  struct SLL *head;
  head = NULL;
  struct SLL *p;

  p = pushToNext(&head , 10);
  p = pushToNext(&p , 20);
  p = pushToNext(&p , 30);
  p = pushToNext(&p , 40);
  p = pushToNext(&p , 50);
  p = pushToNext(&p , 60);
  p = pushToNext(&p , 5);
  p = pushToNext(&p , 2);
  p = pushToNext(&p , 1);
  print(head);
  deleteNodesHavingGreaterValuesOnRHS(&head);

  print(head);

  return 0;
}
