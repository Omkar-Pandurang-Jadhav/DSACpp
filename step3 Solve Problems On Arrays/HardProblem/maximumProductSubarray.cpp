# include<bits/stdc++.h>
using namespace std;

// Example arr={2,3,-2,4}
// Ans is 6

// Brute Force
int maximumProduct(vector<int> arr,int n){
    int maxi=INT_MIN;

    /*
    // Time complexity is O(N^3)
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int prod=1;
            for(int k=i;k<=j;k++){
                prod=prod*arr[k];
            }
            maxi=max(maxi,prod);
        }
    }  */

   // Time complexity is O(N^2) ans space complexity is O(1)
   for(int i=0;i<n;i++){
    int prod=1;
    for(int j=i;j<n;j++){
        prod=prod*arr[j];
        maxi=max(prod,maxi);
    }
   }
    return maxi;
}

// Optimal Solution 
int maximumProductdup1(vector<int> arr,int n){
    int prefix=1;
    int suffix=1;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        if(prefix==0) prefix=1;
        if(suffix==0) suffix=1;
        prefix=prefix*arr[i];
        suffix=suffix*arr[n-1-i];
        maxi=max(maxi,max(suffix,prefix));
    }

    return maxi;
}

int main(){
    cout<<"Enter the size of an array : ";
    int n;
    cin>>n;
     vector<int> arr(n);
    cout<<"Enter the element for an array : \n";
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }

    // int ans=maximumProduct(arr,n);
    int ans=maximumProductdup1(arr,n);
    cout<<"The maximum product is "<<ans<<" .";

    return 0;
}