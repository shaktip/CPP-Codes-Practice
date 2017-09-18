#include<iostream>
using namespace std;

struct SLL
{
   int data;
   struct SLL *next;
};

void print(struct SLL *head)
{
   cout<<"\n SLL is : ";
   while(head)
   {
      cout<<head->data<<" ";
      head = head->next;
   }
}
void push(struct SLL **head , int x)
{
  struct SLL *first = *head;
  struct SLL *node = new SLL;
  node->data = x;
  node->next = first;
  *head = node;

}
void SplitSLL(struct SLL *head, struct SLL **firstHalf , struct SLL **secondHalf)
{
   struct SLL *slow, *fast;
   slow = head;
   fast = head->next;

   if(!slow || !(slow->next))
   {

      *firstHalf = head ; *secondHalf = NULL;
      return ;
   }
   while(fast)
   {
      fast = fast->next;
      if(fast)
      {
        fast = fast->next;
        slow = slow->next;
      }
   }
   *firstHalf = head;
   *secondHalf = slow->next;
   slow->next = NULL;


}
struct SLL * Merge2SortedSLL(struct SLL *first , struct SLL *second)
{

   if(!first)
     return second;
   if(!second)
     return first;
   struct SLL *result;
   if(first->data < second->data)
   {
      result = first;
      result->next = Merge2SortedSLL(first->next , second);
   }
   else
   {
      result = second;
      result->next = Merge2SortedSLL(first , second->next);
   }
   return result;
}
void MergeSortSLL(struct SLL **head)
{
    struct SLL *firstHalf , *secondHalf;
    struct SLL *h = *head;
    if(!h || !h->next)
      return ;
    SplitSLL(*head , &firstHalf , &secondHalf);
    MergeSortSLL(&firstHalf);
    MergeSortSLL(&secondHalf);
    *head = Merge2SortedSLL(firstHalf , secondHalf);
}
void SwapAdjNodes(struct SLL **head)
{
  struct SLL *h = *head;
  if(!h || !(h->next))
    return;
  struct SLL *first , *second;
  first = h;
  second = h->next;
  if(second->next)
     SwapAdjNodes(&(second->next) );
  first->next = second->next;
  second->next = first;
  *head = second;
}

struct SLL * ReverseGroupOfK(struct SLL **head , struct SLL *nextNode, struct SLL *prev , int K , int n)
{
   if(!nextNode || n == K -1)
     return nextNode;
   struct SLL *h = *head;
   struct SLL *p = nextNode->next;
   h->next = prev;
   nextNode->next = h;
   *head = nextNode;
   n++;
   return ReverseGroupOfK(head , p , h, K , n);
}

void ReverseInGroupOfK(struct SLL **head , int K)
{
   struct SLL *h = *head;
   struct SLL *nextNode;
   nextNode = ReverseGroupOfK(&h , h->next , NULL, K , 0);

   *head = h;
   cout<<"\n\t First node data is  "<<h->data;
   cout<<"\n\t p data is "<<nextNode->data;
   struct SLL *NN;
   while(nextNode != NULL)
   {
       int i = 1;
       for(;i<K;i++)
          h = h -> next;

       NN = ReverseGroupOfK(&nextNode , nextNode->next , NULL, K , 0);
       h->next = nextNode;
       h = h->next;
       nextNode = NN;
   }


}

void ReverseSLLRec(struct SLL **head , struct SLL *nextNode , struct SLL *prev)
{
   if(!nextNode)
      return;
   struct SLL *h  = *head;
   struct SLL *p = nextNode->next;
   h->next = prev;
   nextNode->next = h;
   *head = nextNode;
   ReverseSLLRec(head , p , h);

}
void deleteAlternate(struct SLL *head)
{
   if(!head || !(head->next))
     return;
   struct SLL *first = head;
   struct SLL *second = head->next;
   //cout<<"\nFirst data = " << first->data <<" Second data = "<< second->data;
   if(second->next)
      deleteAlternate(second->next);
   first->next = second->next;
   delete(second);
}
int main()
{
  struct SLL *first;
  first = NULL;
  push(&first, 10);
  push(&first , 20);
  push(&first , 5);
  push(&first , 7);
  push(&first , 1);
  push(&first , 6);
  push(&first , 8);
  push(&first , 30);
  push(&first , 11);
  push(&first , 34);
  print(first);
  MergeSortSLL(&first);
  print(first);
  SwapAdjNodes(&first);
  print(first);


  int K;
  cout<<"Enter value of K =";
  cin>>K;
  ReverseInGroupOfK(&first , K);
  print(first);
  //ReverseSLLRec(&first , first->next , NULL);
  //print(first);
  //deleteAlternate(first);
  //print(first);
  return 0;
}
