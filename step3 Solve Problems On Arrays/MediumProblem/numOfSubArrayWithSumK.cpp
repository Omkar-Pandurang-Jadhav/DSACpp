# include<bits/stdc++.h>
using namespace std;

// Brute force solution
int numberOfSubArrayWithSumK(vector<int> arr,int K){
  int n=arr.size();
  int cnt=0;
  
  // Time complexity is O(N*N*N)
  /*
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        int sum=0;
        for(int k=i;k<=j;k++){
            sum=sum+arr[k];
        }
        if(sum==K) cnt++;
    }
  }
  */

 // Time complexity is O(N*N)
 for(int i=0;i<n;i++){
    int sum=0;
    for(int j=i;j<n;j++){
       sum=sum+arr[j];
       if(sum==K) cnt++;
    }
 }

  return cnt;
}

// Optimal Approach
int numberOfSubArrayWithSumKdup1(vector<int> arr,int K){
    map<int,int> mpp; //mpp<sum,count>
    int n=arr.size();
    int preSum=0;
    int cnt=0;
    mpp[0]=1;
    for(int i=0;i<n;i++){
       preSum=preSum+arr[i];
       int remove=preSum-K;
       cnt=cnt+mpp[remove];
       mpp[preSum]++;
    }
    return cnt;
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
    int k;
    cout<<"Enter the number which will be sum of subarray : ";
    cin>>k;

   // int cnt=numberOfSubArrayWithSumK(arr,k);
   int cnt=numberOfSubArrayWithSumKdup1(arr,k);
    cout<<"The number of sub array with sum k is : "<<cnt;


    return 0;
}