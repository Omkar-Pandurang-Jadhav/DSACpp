# include<bits/stdc++.h>
using namespace std;

//  We have given an array of size n and the array contain element of 1 to n 
//  in array there is 1 repeating  number and 1 missing number we have to return
//  those two numbers

// Example
//  arr={4,3,6,2,1,1} n=6 here repeating is 1 and missing is 5

// Brute force
pair<int,int> returnMissingAndReapeting(vector<int> arr,int n){
    // Time complexity is O(N*N)
    // Space complexity is O(1)
    int missing=-1;
    int reapeting=-1;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(arr[j]==i) cnt++;
        }
        if(cnt==0){
            missing=i;
        }
        else if(cnt==2){
            reapeting=i;
        }
        if(missing!=-1 && reapeting!=-1) break;
    }
    return {missing,reapeting};
}

// Better Solution
pair<int,int> returnMissingAndReapetingdup1(vector<int> arr,int n){
    // Time complexity is O(2N)
    // Space complexity is O(N+1)
    vector<int> hash(n+1,0);
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    int missing=-1;
    int reapeting=-1;
    for(int i=1;i<=n;i++){
        if(hash[i]==2){
            reapeting=i;
        }
        else if(hash[i]==0){
            missing=i;
        }
    }
    return {missing,reapeting};
}

// Optimal Solution using maths
// Let x be reapeting and x be missing 
//  x-y=sumofarray-sumofnaturalnumber
//  x^2-y^2=sumofsquareofarray-sumofsquareofnarturalnumber;
//  x+y=(x^2-y^2)/(x-y)

pair<int,int> returnMissingAndReapetingdup2(vector<int> arr,int n){
    // Time complexity is O(N) and space complexity is O(N)
    int sumofnaturalnumber=(n*(n+1))/2;
    int sumofsquareofnaturalnumber=(n*(n+1)*(2*n+1))/6;
    int sum=0;
    int square=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
        square=square+arr[i]*arr[i];
    }
    int a=sum-sumofnaturalnumber;
    int b=square-sumofsquareofnaturalnumber;
    int c=b/a;
    int x=(a+c)/2;
    int y=x-a;

    return {y,x};
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

    // pair<int,int> ans=returnMissingAndReapeting(arr,n);
    // pair<int,int> ans=returnMissingAndReapetingdup1(arr,n);
    pair<int,int> ans=returnMissingAndReapetingdup2(arr,n);
    cout<<"The missing and repeating number is "<<ans.first<<" and "<<ans.second<<" .";

    return 0;
}