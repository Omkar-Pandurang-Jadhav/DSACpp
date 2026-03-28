# include<bits\stdc++.h>
using namespace std;

// Hashing is something like pre-storing and fetching
// In normal counting the frequency of number in some case it can take 100 sec to run

// Imagine The maximum value of element in queries is 12 the we will make Hash array of size 13 and stores zero in 
// that hash array  whenever the element of array comes hash array will increment the value by 1 at that index of 
// Hash array

// Now consider the maximum element  of array can 10^9 but we cannot declare array of size 10^9+1
// The maximum size of array inside main function can be declared as 10^6
// arr[10^6] -> inside main if greater inside main like arr[10^7] ->inside main it will throw segmentation fault
//But if declare an array globally we can give upto size of 10^7
// arr[10^7]-> globally is okay
// For boolean
// arr[10^7]->inside int main and arr[10^8]-> globally
// 
//int arr[1e7];
//int Hash[100000000]={0};


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // precompute
    int Hash[13]={0};
    for(int i=0;i<n;i++){
        Hash[arr[i]]=Hash[arr[i]]+1;
    }
    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        
        // fetching :
        cout<<Hash[number]<<" ";
    }
    return 0;
}