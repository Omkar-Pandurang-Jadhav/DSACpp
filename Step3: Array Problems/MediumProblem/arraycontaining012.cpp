# include<bits/stdc++.h>
using namespace std;

// This program is about  how sort an array that only contain 0,1 and 2

void merge(vector<int> &arr,int low,int mid,int high){
    int l=low;
    int m=mid;
    int midplusone=mid+1;
    int h=high;
    vector<int> temp;
    while(l<=m && midplusone<=h){
        if(arr[l]<=arr[midplusone]){
           temp.push_back(arr[l]);
           l++;
        }
        else{
            temp.push_back(arr[midplusone]);
            midplusone++;
        }
    }
    while(l<=m){
        temp.push_back(arr[l]);
        l++;
    }
    while(midplusone<=h){
        temp.push_back(arr[midplusone]);
        midplusone++;   
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
// Brute force approach is to use any sorting tecnique like MergeSort
void mergeSort(vector<int> &arr,int low ,int high){
    // Time complexity is O(NLogN) and space complexity is O(N)
    if(low==high) return;
    int mid=(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

// Another better apprach is usinhg three counter
void threeCounter(vector<int> &arr,int n){
    // Time complexity is O(2*N) and space complexity is O(1)
    int cnt0=0;
    int cnt1=0;
    int cnt2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) cnt0++;
        else if(arr[i]==1) cnt1++;
        else if(arr[i]==2) cnt2++;
    }
    for(int i=0;i<cnt0;i++) arr[i]=0;
    for(int i=cnt0;i<(cnt0+cnt1);i++) arr[i]=1;
    for(int i=(cnt1+cnt0);i<(cnt0+cnt1+cnt2);i++) arr[i]=2;
}
              
// Another optimal solution know as Dutch National Flag Problem
void dutchNationalFlagProblem(vector<int> &arr,int n){
    // Time complexity is O(N) and space complexity is O(1)    
    int low=0,mid=0,high=n-1;
     while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
          mid++;
        }
        else if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
        }
     }
}
int main(){
    int n;
    cout<<"Enter the size of an array : ";
    cin>>n;
    
    vector<int> arr(n);
    cout<<"Enter the element of an array : \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   // mergeSort(arr,0,n-1);
   // threeCounter(arr,n);
   dutchNationalFlagProblem(arr,n);
    cout<<"The sorted array of 0,1 and 2 is : \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}