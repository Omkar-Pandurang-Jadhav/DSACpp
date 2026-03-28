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

Node *insertAtTheHead(Node *head,int value){
    Node *p=new Node(value);
    p->next=head;
    head=p;

    return head;
}

Node *insertAtTheTail(Node *head,int value){
    Node *newNode=new Node(value);
    Node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=newNode;

    return head;
}

Node *insertAtTheKthPosition(Node *head,int k,int val){
    Node *newNode=new Node(val);
    if(head==NULL){
        if(k==1) return newNode;
        else return NULL;
    }
    if(k==1){
        newNode->next=head;
        head=newNode;
        return head;
    }
    Node *temp=head;
    Node *q=NULL;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            newNode->next=q->next;
            q->next=newNode;
            break;
        }
        q=temp;
        temp=temp->next;
    }

    if(cnt+1<k){
        cout<<"The position is out of bound . \n";
    }

    return head;
}

// Inserting an element before the value x
Node *insertBeforeValuex(Node *head,int x,int val){
    Node *newNode=new Node(val);
    if(head==NULL){
        cout<<"The LL is NULL so it cannot be inserted .";
        return NULL;
    }
    if(head->data==x){
        newNode->next=head;
        head=newNode;
        return head;
    }
    Node *temp=head;
    Node *q=NULL;
    int found=0;
    while(temp!=NULL){
        if(temp->data==x){
            newNode->next=temp;
            q->next=newNode;
            found=1;
            break;
        }
        q=temp;
        temp=temp->next;
    }
    if(found==0){
        cout<<"Element X not Found . \n";
    }
    return head;
}
int main(){
    Node *head=NULL;
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    
    head=convertArrayToLinkedlist(head,arr);
    displayLinkedList(head);
  
    cout<<"\n";
    cout<<"Enter the element u want to insert at the head : ";
    int val1;
    cin>>val1;
    head=insertAtTheHead(head,val1);
    cout<<"The linked after insertion at head is :\n";
    displayLinkedList(head);
    cout<<"\n";

    cout<<"Enter the element u want to insert at the tail : ";
    int val2;
    cin>>val2;
    head=insertAtTheTail(head,val2);
    cout<<"The linked after insertion at Tail is :\n";
    displayLinkedList(head);
    cout<<"\n";
  
    cout<<"Enter the Kth position you wnat to insert at in the linked list : ";
    int k;
    cin>>k;
    cout<<"Enter the element u want to insert at the Kth position : ";
    int val3;
    cin>>val3;
    head=insertAtTheKthPosition(head,k,val3);
    cout<<"The linked after insertion at Kth position is :\n";
    displayLinkedList(head);
    cout<<"\n";

  
    cout<<"Enter the element u want to insert before x : ";
    int x;
    cin>>x;
    cout<<"Enter the element u want to insert : ";
    int val4;
    cin>>val4;
    head=insertBeforeValuex(head,x,val4);
    cout<<"The linked after insertion of element before x is :\n";
    displayLinkedList(head);
    cout<<"\n";


    return 0;
}