#include<iostream>
#include<stdio.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}


int main()
{
    int n1,n2,n3;

   
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    
    return 0;
}

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
   int countNodes (Node* head)
{
int count;
for (count = 0; head!= NULL; head = head -> next, count++);
return count;
}

int _getIntersectionNode(int diff, Node* head1, Node* head2)
{
   for (int count = 0; count < diff; count++, head1 = head1 -> next)
   if (!head1)
      return -1;
   for (; head1 && head2; head1 = head1 -> next, head2 = head2 -> next)
   if (head1 == head2)
      return head1 -> data;
   return -1;
}

int intersectPoint (Node* head1, Node* head2)
{
    int l1 = countNodes(head1);
    int l2 = countNodes(head2);
    int diff = abs(l1-l2);
    return (l1 > l2)? _getIntersectionNode(diff, head1, head2):
    _getIntersectionNode(diff, head2, head1);
}


