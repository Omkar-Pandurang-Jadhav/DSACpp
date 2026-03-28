# include<bits/stdc++.h>
using namespace std;

// Count Inversion states that you will be given an array 
// We have to return the count of pair such that
// i<j and {a[i]>a[j]}
// Example arr[]={5,3,2,4,1}
// ans are (5,3) (5,4) (5,2) (5,1) (3,2) (3,1) (2,1) (4,1)

// Brute Force Solution
int countInversion(vector<int> arr,int n){
    // Time complexity is O(N^2) and space complexity is O(1)
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                cnt++;
            }
        }
    }
    return cnt;
}

int  merge(vector<int> &arr,int low,int mid,int high){
    int l=low,h=high;
    int midplusone=mid+1;
    int cnt=0;
      vector<int> v;
      
      while(low<=mid && midplusone<=high){
        if(arr[low]<=arr[midplusone]){
            v.push_back(arr[low]);
            low++;
        }
        else{
            v.push_back(arr[midplusone]);
            cnt=cnt+mid-low+1;
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
      return cnt;
}

int MergeSort(vector<int> &arr,int low ,int high){
  // Time complexity is O(NlogN) and space complexity is O(N)
    int cnt=0;
    if(low>=high) return cnt;
    int mid=(low+high)/2;
    cnt=cnt+MergeSort(arr,low,mid);
    cnt=cnt+MergeSort(arr,mid+1,high);
    cnt=cnt+merge(arr,low,mid,high);
    return cnt;
}

// Optimal solution using merge sort
int countInversiondup1(vector<int> arr,int n){
    // Time complexity is O(NlogN) and space Complexity is O(N)
    int ans=MergeSort(arr,0,n-1);
    return ans;
}
int main(){
    int n;
    cout<<"Enter the size of an array : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the element for an array : \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // int ans=countInversion(arr,n);
    int ans=countInversiondup1(arr,n);
    cout<<"The number of pairs in giver array are "<<ans<<" .";


    return 0;
}