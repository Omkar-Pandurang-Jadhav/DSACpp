# include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data1){
        data=data1;
        next=NULL;
    }
}; 

Node *convertArrayToLinkedlist(Node * head,vector<int> arr){
    int n=arr.size();
    /*
    for(int i=0;i<n;i++){
        Node *newNode=new Node(arr[i]);
        if(head==NULL){
            head=newNode;
        }
        else{
            Node *p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=newNode;
        }
    }
    */
   // Optimal way
   head=new Node(arr[0]);
   Node *p=head;
   for(int i=1;i<n;i++){
    Node *newNode=new Node(arr[i]);
    p->next=newNode;
    p=newNode;
   }
    
    return head;
}
void displayLinkedList(Node *head){
    Node *p=head;
    while(p!=NULL){
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL";
}
int lengthOfLinkedList(Node *head){
    int cnt=0;
    Node *p=head;
    while(p!=NULL){
        cnt++;
        p=p->next;
    }
   return cnt;
}
int main(){
    Node *head=NULL;
    vector<int> arr={1,2,3,4,5,6};
    head=convertArrayToLinkedlist(head,arr);
    displayLinkedList(head);
    cout<<"\n";
    int ans=lengthOfLinkedList(head);
    cout<<"The length of a linked list is "<<ans;
    return 0;
}