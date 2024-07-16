# include<bits/stdc++.h>
using namespace std;

// Divide and Merge
    // Merge sort divide the array hypothiticaly
    // For example arr[]={3,1,2,4,1,5,2,6,4}
    // We can divide the array of size 9 in 4/5 part or 5/4 part
    //{3,1,2,4,1} and {5,2,6,4} we can further  divide these two array again
    // {3,1,2} , {4,1} and {5,2} , {6,4}
    //{3,1} ,{2} ,{4} ,{1} and {5},{2},{6},{4}
    //{3},{1},{2} ,{4} ,{1} and {5},{2},{6},{4} and we will merge it
    //{1,3},{2} ,{1,4} and {2,5},{4,6}
    //{1,2,3} ,{1,4} and {2,5} , {4,6}
    //{1,1,2,3,4} and {2,4,5,6}
    // {1,1,2,2,3,4,4,5,6}


void merge(int arr[],int low,int mid,int high){
    int l=low,h=high;
    int midplusone=mid+1;
      vector<int> v;
      
      while(low<=mid && midplusone<=high){
        if(arr[low]<=arr[midplusone]){
            v.push_back(arr[low]);
            low++;
        }
        else{
            v.push_back(arr[midplusone]);
            midplusone++;
        }
      }
      while(low<=mid){
        v.push_back(arr[low]);
        low++;
      }
      while(midplusone<=high){
        v.push_back(arr[midplusone]);
        midplusone++;
      }

      for(int i=l;i<=h;i++){
        arr[i]=v[i-l];
      }
      
}
void MergeSort(int arr[],int low ,int high){
    if(low>=high) return;
    int mid=(low+high)/2;
    MergeSort(arr,low,mid);
    MergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main(){
    // Time complexity is O(N*Log2(N)) and space complexity is at worst case is O(N).
    int n;    
    cout<<"Enter the size of an Array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elemwnt for an Array : \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    MergeSort(arr,0,n-1);
    cout<<"\n";
    cout<<"The sorted array is : \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}