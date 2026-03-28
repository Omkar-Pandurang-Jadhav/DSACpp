# include<bits/stdc++.h>
using namespace std;

// Brute force approach
vector<int> majorityElementMoreThanThreeTime(vector<int> arr){
    // Time complexity is O(N*N) and space complexity is O(1)
   int n=arr.size();
   vector<int> ans;
   for(int i=0;i<n;i++){
        //selected element is v[i]:
        // Checking if v[i] is not already
        // a part of the answer:
      if(ans.size()==0 || ans[0]!=arr[i]){
        int cnt=0;
        for(int j=0;j<n;j++){
          // counting the frequency of v[i]
          if(arr[i]==arr[j]){
            cnt++;
          }
        }
        // check if frequency is greater than n/3:
        if(cnt>(n/3)){
            ans.push_back(arr[i]);
        }
        if(ans.size()==2) break;
      }
   }
   sort(ans.begin(),ans.end());

   return ans; 
}

// Better approach
vector<int> majorityElementMoreThanThreeTimedup1(vector<int> arr){
    // Time complexity is O(NlogN) for map and for un_ordered map is O(N) for
    // best and average and for worst is O(N*N) and space complexity is O(N)
    vector<int> ans;
    map<int,int> mpp;
    int n=arr.size();
    int min=(n/3)+1;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
        if(mpp[arr[i]]==min){
            ans.push_back(arr[i]);
        }
        if(ans.size()==2){
            break;
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

// Optimal approach
vector<int> majorityElementMoreThanThreeTimedup2(vector<int> arr){
    // Time complexity is O(N)+O(N) and space complexity is O(1)
    int n=arr.size();
    vector<int> ans;
    int cnt1=0;
    int cnt2=0;
    int el1;
    int el2;

    // applying the Extended Boyer Moore's Voting Algorithm:
    for(int i=0;i<n;i++){
       if(cnt1==0 && arr[i]!=el2){
        cnt1=1;
        el1=arr[i];
       }
       else if(cnt2==0 && arr[i]!=el1){
        cnt2=1;
        el2=arr[i];
       }
       else if(arr[i]==el1) cnt1++;
       else if(arr[i]==el2) cnt2++;
       else {
        cnt1--;
        cnt2--;
       }
    }
    cnt1=0;
    cnt2=0;
    // Manually check if the stored elements in
    // el1 and el2 are the majority elements:
    for(int i=0;i<n;i++){
        if(arr[i]==el1){
            cnt1++;
        }
        if(arr[i]==el2){
            cnt2++;
        }
    }
    // Uncomment the following line
    // if it is told to sort the answer array:
    // sort(ls.begin(), ls.end()); //TC --> O(2*log2) ~ O(1);
    int min=n/3;
    if(cnt1>min) ans.push_back(el1);
    if(cnt2>min) ans.push_back(el2);

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
    
    // vector<int> ans=majorityElementMoreThanThreeTime(arr);
    // vector<int> ans=majorityElementMoreThanThreeTimedup1(arr);
    vector<int> ans=majorityElementMoreThanThreeTimedup2(arr);
    cout<<"Element that are appearing more than three times are : \n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}