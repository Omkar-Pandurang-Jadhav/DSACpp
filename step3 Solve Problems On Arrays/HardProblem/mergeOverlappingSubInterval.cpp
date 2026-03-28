# include<bits/stdc++.h>
using namespace std;

// Brute Force
vector<vector<int>> mergeOverlappingInterval(vector<vector<int>> arr,int n){
    // Time complexity is O(N*Log(N))+O(N)
    // Space complexity in worst case is O(N)
    vector<vector<int>> a=arr;
    sort(a.begin(),a.end());
    vector<vector<int>> ans;
    ans.push_back(a[0]);
    for(int i=1;i<n;i++){
        vector<int> temp=ans.back();
        if(a[i][0]<=temp[1] && a[i][0]>=temp[0]){
            ans.pop_back();
            vector<int> b={temp[0],max(a[i][1],temp[1])};
            ans.push_back(b);
        }
        else if(a[i][0]<temp[1] && a[i][0]<temp[0]){
            ans.pop_back();
            vector<int> b={a[i][0],max(a[i][1],temp[1])};
            ans.push_back(b);
        }
        else if(a[i][0] > temp[1]){
            ans.push_back(a[i]);
        }
    }

    return ans;
}

// Example (1,3)(2,6)(8,9)(9,11)(8,10)(2,4)(15,18)(16,17)
// ans=(1,6)(8,11)(15,18)
int main(){
    int n;
    cout<<"Enter the number of pairs : ";
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(2,0));
    cout<<"Enter the pairs : \n";
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<" pair : ";
        cin>>arr[i][0]>>arr[i][1];
    }
    vector<vector<int>> ans=mergeOverlappingInterval(arr,n);
    cout<<"The final intervals are : \n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
    }

    return 0;
}