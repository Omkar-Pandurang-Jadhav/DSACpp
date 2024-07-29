# include<bits/stdc++.h>
using namespace std;


// Subarray means contigous part of the array
// Ex arr[]={1,2,3,1,1,1,1,4,2,3}
// sub array can be {1,2,3} and {1,1,1,1} and {4,2,3}
// but {2,1,4} can not be subarray
// length ofLongest subarray with sum K [positive element only]

// Brute force approach
// generate all the subarray
 int lengthOfLongestSubArrayWithSumK(int arr[],int n,int sum1){
   
    int length=0;
     // Approx time complexxity is O(N*N*N) and space complexity is O(1) 
   /*
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum=sum+arr[k];
            }
            if(sum==sum1) length=max(length,j-i+1);
        }
    }
    */
   // Another brute force 
   // Approx time complexxity is O(N*N) and space complexity is O(1) 
   for(int i=0;i<n;i++){
    int sum=0;
    for(int j=i;j<n;j++){
      sum=sum+arr[j];
      if(sum==sum1) length=max(length,j-i+1);   
    }
   }

    return length;
 }

 // Better approach
int lengthOfLongestSubArrayWithSumKdup1(int arr[],int n,int sum1){
    // Time complexity is O(NlogN)  for ordered map and O(N*1) for unordermap in average and best case and for worst
    // case it is O(N*N)
    // spac complexity is O(N)
    // This solution is optimal solution if array contains -ve and +ve element both
   int sum=0;
   int maxLen=0;
   map<int,int> maxPreSum;
   for(int i=0;i<n;i++){
    sum=sum+arr[i];
    if(sum==sum1){
        maxLen=max(maxLen,i+1);
    }
    int rem=sum-sum1;

    if(maxPreSum.find(rem) != maxPreSum.end()){
        int len=i-maxPreSum[rem];
        maxLen=max(maxLen,len);
    }

    if(maxPreSum.find(sum) == maxPreSum.end()){
        maxPreSum[sum]=i;
    }
   }
   return maxLen;   
}

// Optimal solution 
int lengthOfLongestSubArrayWithSumKdup2(int arr[],int n,int sum1){
    // This solution is for only +ve and zeros
    // Here we will use two pointer approach
    // Thought process is we take one point and another pointer increment to the left and if do summation the 
    // summation is bound to increase and if it increase beyond K we will trim it from  the left

    // Time complexity is O(2*N) for worst case and space complexity is 
    int maxLen=0;
    int right=0;
    int left=0;
    int sum=arr[0];
    while(right<n){
        while(left<=right && sum>sum1){
            sum=sum-arr[left];
            left++;
        }
        if(sum==sum1){       
            maxLen=max(maxLen,right-left+1);
        }
        right++;
        if(right<n){
        sum=sum+arr[right];
        }
    }

    return maxLen;
}
int main(){
    int n;
    cout<<"Enter the size of an array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the element of an array : \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the number you want sum of longest subarray : ";
    int K;
    cin>>K;
   // int length=lengthOfLongestSubArrayWithSumK(arr,n,K);
   // int length=lengthOfLongestSubArrayWithSumKdup1(arr,n,K);
      int length=lengthOfLongestSubArrayWithSumKdup2(arr,n,K);
    cout<<"The length of longest sub array with sum K is : "<<length<<"\n";

    return 0;
}