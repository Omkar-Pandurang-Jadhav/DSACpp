# include<bits/stdc++.h>
using namespace std;

// This program is about to find leader in array where all element to the right of that element is less

// Brute force approach
vector<int> LeaderOfAnArray(vector<int> arr){
    // Time complexity is O(N*N) and space complexity in worst case is O(N)
    vector<int> ans;
    int n=arr.size();
    for(int i=0;i<n;i++){
        bool leader=true;
        for(int j=i+1;j<n;j++){
          if(arr[j]>arr[i]){
            leader=false;
            break;
          }
        }
        if(leader==true)  ans.push_back(arr[i]);
    }

    sort(ans.begin(),ans.end());

    return ans;
}

// Anothe optimal solution is 
vector<int> LeaderOfAnArraydup(vector<int> arr){
    // Time complexity is O(N) 
    // And space complexity is O(N)  in worst case
    vector<int> ans;
    int maxi=INT_MIN;
    for(int i=arr.size()-1;i>=0;i--){
        if(arr[i]>maxi){
           ans.push_back(arr[i]);
        }
        maxi=max(arr[i],maxi);
    }
    // O(NlogN) if all element are sorted
    sort(ans.begin(),ans.end());

    return ans;
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

    // vector<int> ans=LeaderOfAnArray(arr);
    vector<int> ans=LeaderOfAnArraydup(arr);
    cout<<"The leader of an array arr are : \n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}