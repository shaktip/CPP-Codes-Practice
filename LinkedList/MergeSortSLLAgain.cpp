#include<iostream>
using namespace std;

struct Node
{
   int data;
   struct Node *next;
   Node()
   {data = 0; next = NULL;}
   Node(int d)
   {data = d ; next = NULL;}
};
void printSLL(struct Node *head)
{
  struct Node *p = head;
  while(p)
  {
    cout<<p->data <<" ";
    p = p->next;
  }
  cout<<endl;
}
void Split(struct Node *h, struct Node **a, struct Node **b)
{
    *a = h;

    Node *slow , *fast;
    slow = h;
    fast = h->next;
    while(fast)
    {
      fast = fast->next;
      if(fast)
      {
         slow = slow->next;
         fast = fast->next;
      }
    }
    *b = slow->next;
    slow->next = NULL;

}
struct Node * Merge(struct Node *a , struct Node *b)
{
    if(a == NULL)
      return b;
    if(b == NULL)
      return a;
    struct Node *result;
    if(a->data < b->data)
    {
       result = a;
       result->next = Merge(a->next , b);
    }
    else
    {
        result = b;
        result->next = Merge(a , b->next);
    }
    return result;
}
void MergeSort(struct Node **head)
{
   struct Node *h = *head;
   if(h == NULL || h->next == NULL)
     return ;
   struct Node *a , *b;
   Split(h , &a , &b);
   MergeSort(&a);
   MergeSort(&b);
   *head = Merge(a , b);
}
int main()
{
   Node *head = new Node(10);
   head->next = new Node(20);
   struct Node *p = head;
   p = p->next;
   p->next = new Node(30);
   p = p->next;
   p->next = new Node(5);
   p = p->next;
   p->next = new Node(15);
   p = p->next ;
   p->next = new Node(20);
   p = p->next ;
   p->next = new Node(25);
   MergeSort(&head);

   printSLL(head);
   return 0;
}
