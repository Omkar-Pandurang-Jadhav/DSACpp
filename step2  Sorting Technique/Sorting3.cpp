# include<bits/stdc++.h>
using namespace std;

// Quick Sort
//Step 1: Pick a pivot at any position of an array
// picking pivot as 1st element
// Pick up a pivot and place its in a correct place
// Step 2 : smaller on the left and larger on the right
int partitionElement(int arr[],int low,int high){
    // Time complexity is O(NLog(N))
    // Space Complexity is O(1)
     int pivot = arr[low];
     int i=low;
     int j=high;
     while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
     }

      swap(arr[low],arr[j]);
    return j;
}
void quickSort(int arr[],int low,int high){
    if(low<high){
        int pE=partitionElement(arr,low,high);
        quickSort(arr,low,pE-1);
        quickSort(arr,pE+1,high);
    }
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
    quickSort(arr,0,n-1);
    cout<<"The sorted array is : \n";
    for(int i=0;i<n;i++){
       cout<<arr[i]<<" ";
    }


    return 0;       
}