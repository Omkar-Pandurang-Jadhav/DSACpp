# include<bits/stdc++.h>
using namespace std;

// This program is about finding the next permutation of an array


void reverse(vector<int> &arr,int start,int end){
    
    while(start<end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}
//Better approach is by using STL
vector<int> nextPermutation(vector<int> &arr,int n){
    next_permutation(arr.begin(),arr.end());

    return arr;
}
// Optimal approach
vector<int> nextPermutationdup1(vector<int> &arr,int n){
    // Time complexity is O(3*N) and space complexity is O(1)
    int ind=-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            ind=i;
            break;
        }
    }
    for(int i=n-1;i>ind;i--){
        if(arr[ind]<arr[i]){
            swap(arr[i],arr[ind]);
            break;
        }
    }
    reverse(arr,ind+1,n-1);

    return arr;
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
    // vector<int> permutation=nextPermutation(arr,n);
    vector<int> permutation=nextPermutationdup1(arr,n);
    cout<<"The next permutation of an array is : \n";
    for(int i=0;i<n;i++){
        cout<<permutation[i]<<" ";
    }


}