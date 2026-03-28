# include<bits/stdc++.h>
using namespace std;

// Brute force approach
pair<int,int> sumOfTwoArrayElement(vector<int> arr,int target){
    int n=arr.size();
     pair<int,int> p;
     // Approx time complexity is O(N*N) and space complexity is O(2)
    for(int i=0;i<n;i++){
       for(int j=i+1;j<n;j++){
        if(arr[i]+arr[j]==target){
           p={i,j};
           return p;
        }
       }
    }
    return p={-1,-1};
}
// Better Approach
pair<int,int> sumOfTwoArrayElementdup1(vector<int> arr,int target){
    int n=arr.size();
    // Space complexity is O(NlogN) for ordered map and for unorderd map is O(N) for best and average case and O(N*N)
    // for worst case and space complexity is O(N)
    map<int,int> mpp;
    
    for(int i=0;i<n;i++){
        int num=arr[i];
        int more=target-num;
        if(mpp.find(more) != mpp.end()){
            return {mpp[more],i};
        }
        mpp[num]=i;
    }
    return {-1,-1};
}

// Another optimal approac if we cant  use map
pair<int,int> sumOfTwoArrayElementdup2(vector<int> arr,int target){
    // Time complexity is O(N)+O(NlogN) and space complexity is O(N)
    int n=arr.size();
    vector<int> dup=arr;
    sort(dup.begin(),dup.end());
    int right=n-1;
    int left=0;
    while(left<right){
        int sum=dup[left]+dup[right];
        if(sum==target){
        return {find(arr.begin(),arr.end(),dup[left])-arr.begin(),find(arr.begin(),arr.end(),dup[right])-arr.begin()};
        }
        else if(sum<target)left++;
        else right--;
    }

    return {-1,-1};
}

int main(){
    int n;
    cout<<"Enter the size of an array : ";
    cin>>n;
    //int arr[n];
    vector<int> arr(n);
    cout<<"Enter the element of an array : \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int target;
    cout<<"Enter the number you want sum of two array element : ";
    cin>> target;
    //pair<int,int> p=sumOfTwoArrayElement(arr,target);
    //pair<int,int> p=sumOfTwoArrayElementdup1(arr,target);
    pair<int,int> p=sumOfTwoArrayElementdup2(arr,target);
    cout<<"Two element of array whose sum is " <<target<< " is present at index "<<p.first<<" and "<<p.second;
    return 0;
}