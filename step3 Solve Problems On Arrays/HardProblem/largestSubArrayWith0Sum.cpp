# include<bits/stdc++.h>
using namespace std;
// Brute force solution is 
int largestSubArrayWithSum0(vector<int> arr){
    // Time complexity is O(N^3)
    int n=arr.size();
    int length=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum=sum+arr[k];
            }
            if(sum==0){
               length=max(length,j-i+1);
            }
        }
    }
    return length;
}

// Better solution
int largestSubArrayWithSum0dup1(vector<int> arr){
    // Time complexity is O(N^2)
    int n=arr.size();
    int length=INT_MIN;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum=sum+arr[j];
            if(sum==0){
                length=max(length,j-i+1);
            }
        }
    }
    return length;
}
// optimal solution
int largestSubArrayWithSum0dup2(vector<int> arr){
    // Time complexity is O(N) and space complexity is O(N)
    int n=arr.size();
    int length=INT_MIN;
    int sum=0;
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
        if(sum==0){
            length=i+1;
        }
        
        if(mpp.find(sum)!=mpp.end()){
            length=max(length,i-mpp[sum]);
        }
        else {
            mpp[sum]=i;
        }
        
    }
    return length;
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
    // int length=largestSubArrayWithSum0(arr);
    // int length=largestSubArrayWithSum0dup1(arr);
    int length=largestSubArrayWithSum0dup2(arr);
    cout<<"The length of longest subarray with sum 0 is : "<<length;
    
    return 0;
}