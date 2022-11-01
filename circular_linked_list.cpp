#include <iostream>
using namespace std;
class Node{
    public:
        Node* next;
        int data;
        Node(int d){
            this->data=d;
            this->next=NULL;
        }
};
void insertNode(int element,int d,Node* &tail){
    if(tail==NULL){
        Node* temp=new Node(d);
        tail=temp;
        temp->next=temp;
        return;
    }else{
        Node* temp=new Node(d);
        Node* curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        temp->next=curr->next;
        curr->next=temp;
    }
}
void print(Node* tail){
    Node* temp=tail;
    if(tail==NULL){
        cout<<"list is empty"<<endl;
        return ;
    }
    do{
        cout<<tail->data<<" ";
        tail=tail->next;

    }while(temp!=tail);
}
void remove(Node* &tail,int value){
    if(tail==NULL){
        cout<<"empty list"<<endl;
    }
    
        Node* temp=tail;
        Node* curr=temp->next;
        while(curr->data!=value){
            temp=curr;
            curr=curr->next;
        }
        temp->next=curr->next;
        curr->next=NULL;
        delete curr;

}
int main(){
    Node* tail=NULL;
    insertNode(1,20,tail);
    insertNode(20,30,tail);
    insertNode(30,40,tail);
    print(tail);
    remove(tail,30);
    print(tail);
}