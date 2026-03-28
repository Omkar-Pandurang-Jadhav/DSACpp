# include<bits/stdc++.h>
using namespace std;

// Cout subarray with XOR as K
int numberOfSubArrayWithSumKAsXOR(vector<int> arr,int k){
    int cnt=0;
    int n=arr.size();

    /*
     Time complexity is N^3
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
        int XOR=0;
           for(int k=i;k<=j;k++){
           XOR=XOR^arr[j];
           }
        if(XOR==k) cnt++;
        }
    }
    */

    // Time complexity is about N*N
    for(int i=0;i<n;i++){
        int XOR=0;
        for(int j=i;j<n;j++){
            XOR=XOR^arr[j];
            if(XOR==k) cnt++;
        }
    }
    return cnt;
}

// Optimal solution 
int numberOfSubArrayWithSumKAsXORdup1(vector<int> arr,int k){
    // Time complexity is O(N) or O(N*log(N));
    // Space complexity is O(N)
    int preXOR=0;
    int cnt=0;
    int n=arr.size();
    map<int,int> mpp;
    mpp[0]=1;
    for(int i=0;i<n;i++){
        preXOR=preXOR^arr[i];
        int x=preXOR^k;
        cnt=cnt+mpp[x];
        mpp[preXOR]++;
    }

    return cnt;
}

// Example array 4 2 2 6 4
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
    cout<<"Enter the sum XOR as k : ";
    cin>>k;
    
    // int cnt=numberOfSubArrayWithSumKAsXOR(arr,k);
    int cnt=numberOfSubArrayWithSumKAsXORdup1(arr,k);
    cout<<"The number of subarray is : "<<cnt;


    return 0;
}