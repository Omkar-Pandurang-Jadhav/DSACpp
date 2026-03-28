# include<bits/stdc++.h>
using namespace std;

// Brute force solution
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // Time complexity is O(N^4)
    // Sc O(no of quads)*2
        int n=nums.size();
        set<vector<int>> st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        long long sum=nums[i]+nums[j];
                        sum+=nums[k];
                        sum+=nums[l];
                        vector<int> temp;
                        if(sum==target){
                          temp={nums[i],nums[j],nums[k],nums[l]};
                          sort(temp.begin(),temp.end());
                          st.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
}

// better approach 
vector<vector<int>> fourSumdup1(vector<int>& nums, int target) {
    //  Time complexity is O(N^3 x Log(m)) m is number of element in hashset
    // Sc complexity is O(N)+O(quads) *2
        int n=nums.size();
        set<vector<int>> st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                set<long long> hashset;
                for(int k=j+1;k<n;k++){
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    long long fourth=target-sum;
                    if(hashset.find(fourth)!=hashset.end()){
                        vector<int> temp={nums[i],nums[j],nums[k],(int)fourth};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
}
// Optimal solution
vector<vector<int>> fourSumdup2(vector<int>& nums, int target) {
    // Time complexity is O(N^2 * N)==O(N^3)
    // Space complexity is O(no of quads) using space to return the ans not to solve the
    // problem
       int n=nums.size();
       sort(nums.begin(),nums.end());
       vector<vector<int>> ans;
       for(int i=0;i<n;i++){
        if(i>0 && nums[i-1]==nums[i]) continue; 
        for(int j=i+1;j<n;j++){
            if(j>i+1 && nums[j-1]==nums[j]) continue;
         int k=j+1;
         int l=n-1;
         while(k<l){
            long long sum=nums[i];
            sum+=nums[j];
            sum+=nums[k];
            sum+=nums[l];
            if(sum<target){
                k++;
            }
            else if(sum>target){
                l--;
            }
            else if((int)sum==target){
                vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                ans.push_back(temp);
                k++;
                l--;
                while(k<l && nums[k]==nums[k-1]) k++;
                while(k<l && nums[l]==nums[l+1]) l--;
            }
         }
        }
       }
       return ans;
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
    int target;
    cout<<"Enter the target element : ";
    cin>>target;
    // vector<vector<int>> ans=fourSum(arr);
    // vector<vector<int>> ans=fourSum1(arr);
    vector<vector<int>> ans=fourSumdup2(arr,target);
    cout<<"The four element of an array are : \n";
    int r=ans.size();
    int c=ans[0].size();
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}