# include<bits/stdc++.h>
using namespace std;

void selectionSort(int n,int arr[]){
    // It first take min to the first position
    // Time complexity is near about O(N*N) for best , average and worst
    for(int i=0;i<n-1;i++){
        int temp=arr[i];
        for(int j=i+1;j<n;j++){
         if(arr[i]>arr[j]){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void bubbleSort(int n,int arr[]){
    // It pushes maximum to last by adjacent swaping
    // Time complexity is O(N*N) for average and best
    // if array is sorted then timecomplexity is time complexity is O(N) in best condition
    for(int i=n-1;i>=0;i--){
        int didswap=0;
         for(int j=0;j<i;j++){
            int temp;
            if(arr[j]>arr[j+1]){
              temp=arr[j];
              arr[j]=arr[j+1];
              arr[j+1]=temp;
              didswap=1;
            }
         }
         if(didswap==0){
            break;
         }
    }
   // cout<<"Runs "; 
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void insertionSort(int n,int arr[]){
    // Take an order and place it in its current position.
    // Time complexity for worst and average is O(N*N) and for best case where array is sorted it is O(N).
    
    for(int i=1;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;     
        }   
        
    }
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n;
    cout<<"Enter the size of an Array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the element for an array - \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"\n";
   // cout<<"Selection sort :\n";
   // selectionSort(n,arr);

   // cout<<"Bubble sort : \n";
   // bubbleSort(n,arr);

   cout<<"Insertion sort : \n";
   insertionSort(n,arr);


}
