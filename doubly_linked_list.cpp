#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int d){
            this->data=d;
            this->prev=NULL;
            this->next=NULL;
        }
        ~Node(){
            cout<<this->data<<"is been removed"<<endl;
        }
};
void insertathead(int d,Node* &head,Node* &tail){
    if(head==NULL){
        Node* temp=new Node(d);
        head=temp;
        tail=temp;
    }else{
        Node* temp=new Node(d);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}
void insertattail(int d,Node* &head,Node* &tail){
    if(tail==NULL){
        Node* temp=new Node(d);
        tail=temp;
        head=temp;
    }else{
        Node* temp=new Node(d);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}
void insertatpos(int pos,int d,Node* &head,Node* &tail){
    if(pos==1){
        insertathead(d,head,tail);
        return ;
    }
    Node* temp=head;   
    int cnt=1;
    while(cnt<pos-1){
        temp=temp->next;
        cnt++ ;
    }
    if(temp->next==NULL){
        insertattail(d,head,tail);
        return ;
    }
    Node* newNode=new Node(d);
    newNode->next=temp->next;
    temp->next->prev=newNode;
    temp->next=newNode;
    newNode->prev=temp;
}
void show(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void remove(int pos,Node* &head,Node* &tail){
    if(pos==1){
        Node* temp=head;
        head=head->next;
        temp->next->prev=NULL;
        temp->next=NULL;
        delete temp;
    }else{
        Node* temp=NULL;
        Node* curr=head;
        int i=1;
        while(i<pos){
            temp=curr;
            curr=curr->next;
            i++;
        }
        curr->prev=NULL;
        temp->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
void reverse(Node* &head){

}
int main(){
    Node* head=NULL;
    Node* tail=NULL;
    insertathead(1,head,tail);
    insertattail(2,head,tail);
    insertatpos(1,10,head,tail);
    insertatpos(4,100,head,tail);
    show(head);
    remove(2,head,tail);
    show(head);
    return 0;
}