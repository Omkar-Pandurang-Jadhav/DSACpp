# include<bits/stdc++.h>
using namespace std;

// This program is about to find the maximum subarray sum

// Brute force approach
int sumOfMaxSubArray(vector<int> arr,int n){
    // Time complexity is O(N*N*N) and space complexity is O(1)
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum=sum+arr[k];
            }
             maxi=max(sum,maxi);
        }
   }

    return maxi;
}

// Another better approach 
int sumOfMaxSubArraydup1(vector<int> arr,int n){
    // Time complexity is O(N*N) and space complexity is O(1)
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
          sum=sum+arr[j];
           maxi=max(sum,maxi);
        }
    }
    return maxi;
}

// Optimal approach is known as Kadane's Algorithm
void sumOfMaxSubArraydup2(vector<int> arr,int n){
    // Time complexity is O(N) and space complexity is O(1)
    int maxi=INT_MIN;
    int sum=0;
    int start,ansStart=-1,ansEnd=-1;
    for(int i=0;i<n;i++){
        if(sum==0) start=i;
       sum=sum+arr[i];

       if(sum>maxi){
        maxi=sum;
        ansStart=start;
        ansEnd=i;
       }

       if(sum<0){
        sum=0;
       }

       if(maxi<0) maxi=0;
    }
    cout<<"The maximum sum of sub array is "<<maxi<<"\n";
    cout<<"The sub array with maximum sum is : \n";
    for(int i=ansStart;i<=ansEnd;i++){
        cout<<arr[i]<<" ";
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
    // int maxsum=sumOfMaxSubArray(arr,n);
    // int maxsum=sumOfMaxSubArraydup1(arr,n);
    // cout<<"The maximum sum of sub array is "<<maxsum;
    sumOfMaxSubArraydup2(arr,n);

    return 0;
}