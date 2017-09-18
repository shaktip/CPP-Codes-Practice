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

void createLL(struct Node **head)
{
   *head = new Node(10);
   (*head)->next = new Node(20);
   struct Node *p = *head;
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
}
void ReverseLL(struct Node **head)
{
   struct Node *h = *head;
   struct Node *prev = NULL;
   struct Node *curr = h;
   struct Node *curr_next;
   while(curr)
   {
      curr_next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = curr_next;
   }
   *head = prev;
}

int main()
{
   struct Node *head1;
   createLL(&head1);
   struct Node *head2;
   createLL(&head2);
   struct Node *head3;
   createLL(&head3);
   printSLL(head1);
   printSLL(head2);
   printSLL(head3);
   struct Node *rev = NULL;
   ReverseLL(&head1, &rev, NULL);

   printSLL(head1);
   //sortAscLL(&head2);
   //sortDescLL(&head3);

   return 0;
}
