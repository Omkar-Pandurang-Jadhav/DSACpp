# include<bits/stdc++.h>
using namespace std;

// Recursive Bubble sort Method
void BubbleSort(int arr[],int n){
    // Time complexity is O(N*N) for average and worst case and O(N) for best case .
    // Space complexity is O(N);
    if(n==1) return;
    int didswap=0;
    for(int j=0;j<n;j++){
        if(arr[j]>arr[j+1]){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            didswap=1;
        }
    }
    if(didswap==0) return;
    BubbleSort(arr,n-1);
}
//Recursive Insersion Sort Method

void InsersionSort(int arr[],int i,int n){
    // Time complexity is O(N*N) for average and worst case and O(N) for best case .
    // Space complexity is O(N);
  if(i==n) return;
  int j=i;
    while(j>0 && arr[j-1]>arr[j]){
         int temp=arr[j];
         arr[j]=arr[j-1];
         arr[j-1]=temp;
         j--;
    }
    InsersionSort(arr,i+1,n);
}
int main(){
     int n;
    cout<<"Enter the size of an Array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the element for an Array : \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
     BubbleSort(arr,n-1);
    cout<<"The sorted array by recursive bubblesort is : \n";
    for(int i=0;i<n;i++){
       cout<<arr[i]<<" ";
    }


    cout<<"\n";

    int n1;
    cout<<"Enter the size of an Array : ";
    cin>>n1;
    int arr1[n1];
    cout<<"Enter the element for an Array : \n";
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    InsersionSort(arr1,1,n1);
    cout<<"The sorted array by recursive insersionsort is : \n";
    for(int i=0;i<n1;i++){
       cout<<arr1[i]<<" ";
    }
    return 0;
}