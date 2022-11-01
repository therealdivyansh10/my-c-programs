#include <iostream>
using namespace std;
class Node{
    public:
        Node* next;
        Node* prev;
        int data;
        Node(int d){
            this->data=d;
            this->prev=NULL;
            this->next=NULL;
        }
};
void insertathead(Node* &head,int d,Node* &tail){
    if(head==NULL){
        Node* temp=new Node(d);
        head=temp;
        tail=temp;
    }
    else{
        Node* temp=new Node(d);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}
void insertattail(Node* &tail,int d,Node* &head){
    if(tail==NULL){
        Node* temp=new Node(d);
        tail=temp;
        head=temp;
    }
    Node* temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
void insertatplace(int pos,int d,Node* &head,Node* &tail){
    if(pos==1){
        insertathead(head,d,tail);
        return;
    }
    Node* precur=NULL;
    Node* curr=head;
    int cnt=1;
    while(cnt<pos){
        precur=curr;
        curr=curr->next;
    }
    if(curr->next==NULL){
        insertattail(tail,d,head);
        return;
    }
    Node* newNode=new Node(d);
    newNode->next=precur->next;
    precur->next->prev=newNode;
    precur->next=newNode;
    newNode->prev=precur;
}
void show(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
    }
    cout<<endl;
}
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    insertathead(head,3);
    insertattail(tail,4);
    insertatplace(2,10,head,tail);
    show(head);
    return 0;
}