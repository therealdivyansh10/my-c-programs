#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
        ~Node(){
            int value=this->data;
            if(this->next!=NULL){
                delete next;
                this->next=NULL;
            }
            cout<<"memory is free for "<<value<<endl;
        }
};
void show(Node*  &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void remove(int pos,Node* &head,Node* &tail){
    if(pos==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* temp=NULL;
        Node* curr=head;
        int i=1;
        while(i<pos){
            temp=curr;
            curr=curr->next;
            i++;
        }
        temp->next=curr->next;   
        curr->next=NULL;
        delete curr;
    }
}
void insertathead(int d,Node* &head){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}
void insertatend(int d,Node* &tail){
    Node* temp=new Node(d);
    tail->next=temp;
    temp=tail;
}
void insertatposition(int value,int pos,Node* &head,Node* &tail){
    if(pos==1){
        insertathead(value,head);
        return;
    }
    Node* temp=head;
    int i=1;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    if(temp->next==NULL){
        insertatend(value,tail);
    }
    Node* newvalue=new Node(value);
    newvalue->next=temp->next;
    temp->next=newvalue;
}
void reverse(Node* &head){
    Node* curr=head;
    Node* prev=NULL;
    while(curr!=NULL){
        Node* temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }  
    head=prev;
}
int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    insertathead(9,head);
    insertatend(11,tail);
    insertatposition(100,2,head,tail);
    show(head);
    remove(4,head,tail);
    show(head);
    reverse(head);
    show(head);
    return 0;
}