# include<bits/stdc++.h>
using namespace std;

// Here we have to find the middle of given linked list
struct Node{
    int data;
    Node *next;

    Node(int data1){
        data=data1;
        next=NULL;
    }
};

Node *insertTheElement(Node *head,int el){
    Node *newNode=new Node(el);
    if(head==NULL){
        return newNode;
    }

    Node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=newNode;

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


// Brute force solution 
Node *findMiddle(Node *head) {
    // If the list is empty or has only
    // one element, return the head as
    // it's the middle.

    // Time complexity is O(N)+O(N/2)
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* temp = head;
    int count = 0;

    // Count the number of nodes in the linked list.
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // Calculate the position of the middle node.
    int mid = count / 2 + 1;
    temp = head;

    // Traverse to the middle node by moving
    // temp to the middle position.
    while (temp != NULL) {
        mid = mid - 1;

        // Check if the middle
        // position is reached.
        if (mid == 0){
            // break out of the loop
            // to return temp
            break;
        }
        // Move temp ahead
        temp = temp->next;
    }

    // Return the middle node.
    return temp;
}


// Optimal solution
// Tortoise & Hare alogorithm
Node * middleElement(Node *head){

    // Time complexity is O(N/2)

    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *slow=head;
    Node *fast=head;

    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    if(fast->next==NULL){
        return slow;
    }
    else return slow->next;
}
int main(){
    cout<<"1)Insert an element at the end \n2)Display LL \n3)Find the middle of linked list \n4)Exit \n";
    int n;
    Node *head=NULL;
    do{
        cout<<"Enter the number based on your choice : ";
        cin>>n;
        if(n==1){
           cout<<"Enter the element you want to insert : ";
           int el;
           cin>>el;
           head=insertTheElement(head,el);
        }
        else if(n==2){
            cout<<"The LL is : \n";
            displayLinkedList(head);
        }
        else if(n==3){
            // Node * middle=findMiddle(head);
            Node * middle=middleElement(head);
            cout<<"The middle element is : "<<middle->data<<" . \n";
        }
    }while(n!=4);
    return 0;
}