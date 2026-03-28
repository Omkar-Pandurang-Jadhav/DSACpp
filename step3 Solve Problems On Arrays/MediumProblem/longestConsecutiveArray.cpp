# include<bits/stdc++.h>
using namespace std;

// This program is about to find longest consecutive array 
// for example arr[]={192,4,100,1,101,3,2,1,,1}
// consecutive sub arrau is {1
bool linearSearch(vector<int> arr,int num){
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]==num) return true;
    }
    return false;
}

// Brute Force Solution
int lengthOfLongestConsecutiveArrayElement(vector<int> arr){
    // Time complexity is O(N*N) and space complexity is O(1)
    int longest=1;
     for(int i=0;i<arr.size();i++){
        int cnt=1;
        int x=arr[i];
        while(linearSearch(arr,x+1)==true){
            x=x+1;
            cnt++;
        }
        longest=max(cnt,longest);
     }

     return longest;
}

// Better solution
int lengthOfLongestConsecutiveArrayElementdup1(vector<int> arr){

    // Time complexity is O(NlogN)+O(N) and space complexity is O(1)
    if(arr.size()==0) return 0;
    sort(arr.begin(),arr.end());
  int n=arr.size();
  int longest=1;
  int last_smaller=INT_MIN;
  int cnt=0;
  for(int i=0;i<n;i++){
     if(last_smaller==arr[i]-1){
       cnt++;
       last_smaller=arr[i];
     }
     else if(last_smaller!=arr[i]){
        last_smaller=arr[i];
        cnt=1;
     }
     longest=max(cnt,longest);
  }

  return longest;
}      

// Optimal Approach using set
int lengthOfLongestConsecutiveArrayElementdup2(vector<int> arr){
    // Here for best and average case tc for un_ordered set is O(1) and for worst case O(N)
    // for this problem time complexity is O(N)+O(2N) =O(3N)
    // Space compexity is O(N)
    int n=arr.size();
    if (n==0) return 0;
    unordered_set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    int longest=1;
    for(auto it : st){
        if(st.find(it-1)==st.end()){
         int cnt=1;
         int x=it;
         while(st.find(x+1)!=st.end()){
            x=x+1;
            cnt++;
         }
         longest=max(longest,cnt);
        }
    }

    return longest;
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
    // int longest=lengthOfLongestConsecutiveArrayElement(arr);
    // int longest=lengthOfLongestConsecutiveArrayElementdup1(arr);
    int longest=lengthOfLongestConsecutiveArrayElementdup2(arr);
    cout<<"The length of longest consecutive element of array is : "<<longest;

    return 0;
}