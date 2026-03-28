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

Node * deleteHead(Node *head){
    if(head==NULL){
        return head;
    }
    Node *p=head;
    head=p->next;
    delete p;
    return head;
}
Node *deleteTail(Node *head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node *p=head;
    Node *q=head;
    while(p->next!=NULL){
        q=p;
        p=p->next;
    }
    q->next=NULL;
    delete p;
    return head;
}

Node *deleteKthElement(Node *head,int k){
    Node *p=head;
    if(head==NULL){
        return head;
    }
    
    if(k==1){
        Node *temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    Node *temp=head;
    Node *q=NULL;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            q->next=temp->next;
            delete temp;
            break;
        }
        q=temp;
        temp=temp->next;
    }
    return head;
}

Node *deleteValueInNode(Node *head,int val){
     Node *p=head;
    if(head==NULL){
        return head;
    }

    if(head->data==val){
        Node *temp=head;
        head=head->next;
        delete temp;
        return head;
    }

    Node *temp=head;
    Node *q=NULL;
    
    while(temp!=NULL){
        if(temp->data==val){
            q->next=temp->next;
            delete temp;
            break;
        }
        q=temp;
        temp=temp->next;
    }
    return head;
}
int main(){
    Node *head=NULL;
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    
    head=convertArrayToLinkedlist(head,arr);
    displayLinkedList(head);

    cout<<"\n";
    cout<<"The linked List After deletion of head :\n";
    head=deleteHead(head);
    displayLinkedList(head);

    cout<<"\n";
    cout<<"The linked List After deletion of tail :\n";
    head=deleteTail(head);
    displayLinkedList(head);

    cout<<"\n"; 
    cout<<"The the kth number position at which node should be deletef : ";
    int k;
    cin>>k;
    head=deleteKthElement(head,k);
    cout<<"The linked list after deletion of kth element is : \n";
    displayLinkedList(head);

    cout<<"\n";
    cout<<"Enter the element u want to delete : ";
    int val;
    cin>>val;
    head=deleteValueInNode(head,val);
    cout<<"The linked list after deletion of element is \n";
    displayLinkedList(head);
   
    return 0;
}