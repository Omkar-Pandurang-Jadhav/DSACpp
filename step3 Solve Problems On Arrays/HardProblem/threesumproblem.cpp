# include<bits/stdc++.h>
using namespace std;

// This program is about to return array of three element of an array whose sum is zero
// and array cannot be duplicate 
/* Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
*/

// brute force approach
vector<vector<int>> threeSumProblem(vector<int> arr){
    // Time complexity is O(N^3)*O(Log(no of unique triplet))
    // Space complexity is 2*O(no of unique triplet)
    int n=arr.size();
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                vector<int> temp;
                if(arr[i]+arr[j]+arr[k]==0){
                    temp={arr[i],arr[j],arr[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

// Better solution
vector<vector<int>> threeSumProblemdup1(vector<int>& nums) {
    // Time complexity is O(N^2)*O(Log(no of unique triplet))
    // space complexity is O(N)
        set<vector<int>> st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            set<int> hashset;
            for(int j=i+1;j<n;j++){
                int third=-(nums[i]+nums[j]);
              if(hashset.find(third)!=hashset.end()){
                vector<int> temp={nums[i],nums[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
              }
              hashset.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
}

// optimal solution
vector<vector<int>> threeSumProblemdup2(vector<int>& nums) {
    // time complexit O(NLog(N)) to sort thr array and O(N) for for loop  O(N) for 
    // while loop so total timpe complexity is O(Nlog(N))+O(N*N)
    // Space complexity is O(No of unique triplet)
    vector<vector<int>> ans;
    int n=nums.size();
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(i>0 && nums[i-1]==nums[i]) continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }
            else if(sum==0){
                vector<int> temp={nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && nums[j-1]==nums[j])j++;
                while(j<k && nums[k+1]==nums[k])k--;
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
    // vector<vector<int>> ans=threeSumProblem(arr);
    // vector<vector<int>> ans=threeSumProblemdup1(arr);
    vector<vector<int>> ans=threeSumProblemdup2(arr);
    cout<<"The three element of an array are : \n";
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