# include<bits/stdc++.h>
using namespace std;

// This program is about to find the element appearing more than half the size of an array

// Brute force approach 
int elementOccursMoreThanHalf(vector<int> arr,int n){
    // Time complexity is O(N*N) and space complexity is O(N)
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]) cnt++;
        }
        if(cnt>n/2) return arr[i];
    }
    return -1;
}

// Another better approach is by using hashing
int elementOccursMoreThanHalfdup1(vector<int> arr,int n){
   // Time complexity is O(NLogN)+O(N) and space complexity is O(N)
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it : mpp){
        if(it.second>n/2) return it.first;
    }

    return -1;
}

// Another optimal solution is known as Moore Voting Algorithm
int elementOccursMoreThanHalfdup2(vector<int> arr,int n){
    // Time complexity is O(N)+O(N) and space complexity is O(1)
    int el;
    int cnt=0;
    for(int i=1;i<n;i++){
       if(cnt==0){
        cnt=1;
        el=arr[i];
       }
       else if(arr[i]==el) cnt++;
       else cnt --;
    }
    int cnt1=0;
    for(int i=0;i<n;i++){
        if(arr[i]==el)cnt1++;
    }
    if(cnt1>n/2) return el;

    return -1;
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
    // int el=elementOccursMoreThanHalf(arr,n);
    // int el=elementOccursMoreThanHalfdup1(arr,n);
    int el=elementOccursMoreThanHalfdup2(arr,n);
    cout<<"The elment occur more than half is "<<el;

    return 0;
}