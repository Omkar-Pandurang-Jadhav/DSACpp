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
    cout<<"\n";
}

// Brute Force solution
Node *reverseTheLL(Node *head){

    // Time complexity is O(2*N) and space complexity is O(N)
    if(head==NULL && head->next==NULL){
        return head;
    }
    stack<int> st;
    Node *temp=head;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }

    return head;
}

// Optimal solution
Node *reverseTheLLdup1(Node *head){
    // Time complexity is O(N)
    if(head==NULL && head->next==NULL){
        return head;
    }

    Node *temp=head;
    Node *prev=NULL;
    while(temp!=NULL){
        Node *front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }

    return prev;
}

// Optimal solution using recurssion
Node *reverseTheLLdup2(Node *head){
    // Time complexity is O(N) and space complexity is O(N) which is recurssive stack space
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *newhead=reverseTheLLdup2(head->next);
    Node *front=head->next;
    front->next=head;
    head->next=NULL;

    return newhead;
}
int main(){
    Node *head=NULL;
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    head=convertArrayToLinkedlist(head,arr);
    cout<<"The linked list is : \n";
    displayLinkedList(head);
    cout<<"The linked list after reversing : \n";
    // head=reverseTheLL(head);
    // head=reverseTheLLdup1(head);
    head=reverseTheLLdup2(head);
    displayLinkedList(head);
    return 0;
}