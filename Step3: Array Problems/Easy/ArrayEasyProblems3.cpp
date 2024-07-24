# include<bits/stdc++.h>
using namespace std;

// Missing Number In an array
// The number N will be gven and array contain N-1 number so we have to find missing number
// For Example N=5 arr[]={1,2,4,5} number 3 is missing

// Brute Force Solution
int missingNumber(int arr[],int n){
    // Time complexity is O(N*N) and space complexity is O(1)
    int flag;
     for(int i=1;i<=n;i++){
        flag=0;
        for(int j=0;j<n-1;j++){
            if(i==arr[j]){
                flag=1;
                break;
            }
        }
        if(flag==0) return i;
     }
}

// Better Solution

int missingNumberdup1(int arr[],int n){
    // This is using hashing method
    // Time complexity is O(2*N) and space complexity is O(N)

    int hash[n+1]={0};

    for(int i=0;i<n-1;i++){
        hash[arr[i]]=1;
    }

    for(int i=1;i<n;i++){
        if(hash[i]==0){
            return i;
        }
    }
}

// Optimal solution using sum method 
int missingNumberdup2(int arr[],int n,int sum){
    // Time complexity is O(N) and space complexity is O(1)          
    int sum1=0;
    for(int i=0;i<n-1;i++){
        sum1=sum1+arr[i];
    } 
    return sum-sum1;
}

// Optimal solutuion using XOR method
// For xor method 1^1=0 2^2=0 and 1^1^2^2=0 2^2^2^2=0 and 2^2^2^2^2=0^2=2
// XOR1=1^2^3^4^5 and XOR2=1^2^3^5 then XOR1^XOR2=0^4=4
int missingNumberdup3(int arr[],int n){
    //XOR Method is slightly better than sum method because in sum method the sum of n natural number may exeed the 
    // The range of integer so than we have to use long but in XOR method number never exceed the range of integer
    // Time complexity is O(N) and space complexity is O(1)
    int XOR1=0;
    int XOR2=0;
    for(int i=0;i<n-1;i++){
      XOR1=XOR1^(i+1);
      XOR2=XOR2^arr[i];
    }
    XOR1=XOR1^n;
    return XOR1^XOR2;
}

// The problem is to find maximum consecutive 1
// for example arr[]={1,1,0,1,1,1,0,1,1} here the answer is 3
int maximumConsecutiveOne(int arr[],int n){
    int max1=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            cnt++; 
            max1=max(max1,cnt);
        }
        else {
            cnt=0;
        }
    }
    return max1;
}

// The problem is the number that appears once and the other twice
// for example aarr[]={1,1,2 ,3,3,5,5} the ans is 2
// Brute Force appraoch
int numberAppearingOnce(int arr[],int n){
    // Time complexity is O(N*N) and Space complexity is O(1)
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
          if(arr[i]==arr[j]){
            cnt++;
          }
        }
        if(cnt==1) return arr[i];
    }
}
// Better method
// Here we can use hash method but hasing can endup taking unnececarry space since we have to make hash array of 
// size max element +1
// so instead we can use map or unoedered map
int numberAppearingOncedup1(int arr[],int n){
    /*
    // We cannot use hashing every time like when the size of int is 10^9 so that time we can use map
    like map<long long,int> mpp
    // Time complexity is O(3*N) and space complexity is O(maxi)
     int maxi=0;
    for(int i=0;i<n;i++){
      maxi=max(maxi,arr[i]);
    }
   int hash[maxi+1]={0};
   for(int i=0;i<n;i++){
    hash[arr[i]]++;
   }
   for(int i=0;i<n;i++){
    if(hash[arr[i]]==1){
        return arr[i];
    }
   }
   */
   
   // Time complexity is for ordered map is NlogM where N is number time loop is running and M is number of 
   // element in an map and for unordered map is O(N)
    map<int,int> mpp;
    // TC O(NlogM)
  for(int i=0;i<n;i++){
      mpp[arr[i]]++;
  }
   
   // TC is O(N/2+1) because only one element is occuring one time
  for(auto it : mpp){
    if(it.second==1){
        return it.first;
    }
  }
  // Total time complexity for ordered map is O(NlogM)+O(N/2+1) where M is N/2+1  and space complexity is O(N/2+1)
}

// Optimal solution for number appearing once
int numberAppearingOncedup2(int arr[],int n){
    int XOR=0;
    for(int i=0;i<n;i++){
        XOR=XOR^arr[i];
    }
    return XOR;
}
int main(){
    int n;
    cout<<"Enter the size of an array -";
    cin>>n;
    int arr[n-1];
    cout<<"Enter the element of an array - \n";
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
   // int missingNum=missingNumber(arr,n);
   // int missingNum=missingNumberdup1(arr,n);
   int sum=(n*(n+1))/2;
   // int missingNum=missingNumberdup2(arr,n,sum);
   int missingNum=missingNumberdup3(arr,n);
    cout<<"The missing number form array of size "<<n<<" is "<<missingNum ;
    cout<<"\n";
    int n1;
    cout<<"Enter the size of an array for consecutive 1 and 0 -";
    cin>>n1;
    int arr1[n1];
    cout<<"Enter the element of an array 1 and 0 - \n";
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    int consecutiveCount=maximumConsecutiveOne(arr1,n1);
    cout<<"The maximum numbwer of consecutive one is "<<consecutiveCount;
    cout<<"\n";
    int n2;
    cout<<"Enter the size of an array to find number appearing once -";
    cin>>n2;
    int arr2[n2];
    cout<<"Enter the element of an array to find number appearing once - \n";
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    // int num=numberAppearingOnce(arr2,n2); 
    // int num=numberAppearingOncedup1(arr2,n2);
    int num=numberAppearingOncedup2(arr2,n2);
    cout<<"The number appearing once is "<<num;
    return 0;
}