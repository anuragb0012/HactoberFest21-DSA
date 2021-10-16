#include<iostream>
using namespace std;

class Node
{
public:
    int Data;
    Node* next;

    Node(int Value)
    {
        Data=Value;
        next=NULL;
    }
};

void InsertAtTail(Node* &head,int Id)
{
    Node* n= new Node(Id);

    if(head==NULL)
    {
        head=n;
    }
    else
    {
        Node *temp=head;
        while(temp->next!=NULL)
        {
              temp=temp->next;
        }
        temp->next=n;
    }

}
void InsertAtHead(Node* &head,int Value)
{
    Node* n=new Node(Value);

    n->next=head;
    head = n;
}

void Traverse(Node* head)
{
    Node* n =head;
    while(n!=NULL)       ///Traverse complete linked list and show its data.
    {
        cout<<n->Data <<" ->";
        n=n->next;
    }
    cout<<"NULL"<<endl;
}

///Non Recursive Call for merging 2 sorted linked list.
Node* Merge(Node* &head1,Node* &head2)
{

    Node* p1=head1;
    Node* p2=head2;
    Node* DummyNode=new Node(-1);  
    Node* p3=DummyNode;

    while(p1!=NULL && p2!=NULL)
    {
        if(p1->Data<p2->Data)
        {
            p3->next=p1;
            p1=p1->next;
        }
        else
        {
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }

   while(p1!=NULL)   
   {
       p3->next=p1;
       p1=p1->next;
       p3=p3->next;
   }

   while(p2!=NULL)
   {
       p3->next=p2;
       p2=p2->next;
       p3=p3->next;
   }
   return DummyNode->next;

}

///Recursive call to merge 2 sorted LinkedList
Node* MergeRecursive(Node* &head1,Node* &head2)
{
    ///Base Cases
    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }

    Node* Result;
    if(head1->Data<head2->Data)
    {
        Result=head1;
        Result->next=MergeRecursive(head1->next,head2);
    }
    else
    {
        Result=head2;
        Result->next=MergeRecursive(head1,head2->next);
    }
}
int main()
{
   Node* head1=NULL;
   Node* head2=NULL;
   int arr1[]={1,4,5,7};
   int arr2[]={2,3,6};

   for(int i=0;i<4;i++)
   {
       InsertAtTail(head1,arr1[i]);
   }

   for(int i=0;i<3;i++)
   {
       InsertAtTail(head2,arr2[i]);
   }
   Traverse(head1);
   Traverse(head2);

  /// Node* NewHead=Merge(head1,head2);
   Node* NewHead=MergeRecursive(head1,head2);

   Traverse(NewHead);
}






























































