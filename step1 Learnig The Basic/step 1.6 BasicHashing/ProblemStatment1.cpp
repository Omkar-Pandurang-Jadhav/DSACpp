# include<bits\stdc++.h>
using namespace std;

// Given an array we have to found the number of occurrence of ech element in the array.
void countFrequency(int a[],int n){
    // Time complexity is O(N*N) and space complexity is O(N)
   vector<bool> visited(n,false);
   for(int i=0;i<n;i++){
    if(visited[i]==true)
        continue;
    
    int count=1;
    for(int j=i+1;j<n;j++){
        if(a[i]==a[j]){
            visited[j]=true;
            count++;
        }
    }
    cout<<a[i]<<" "<<count<<"\n";
   }
}
int main(){
    /*
    // Array Hash takes lot of space 
  int arr[]={10,5,10,15,10,5};

  int Hash[16]={0};

  for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
      Hash[arr[i]]+= 1;
  }
  cout<<"Element-Occurence \n";
  for(int i=0;i<sizeof(Hash)/sizeof(Hash[0]);i++){
    if(Hash[i]!=0){
        cout<<i<<"-"<<Hash[i]<<"\n";
    }
  }
  */
 /*
    int arr[]={10,5,10,15,10,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Element-Occurence \n";
    countFrequency(arr,n);
  */
 // Using Map
 // Time Complexity is O(N)
 int arr[]={10,5,10,15,10,5};
 int n=sizeof(arr)/sizeof(arr[0]);
  unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
      mpp[arr[i]]++;
    }
    cout<<"Element-Occurence \n";
    for(auto it : mpp){
        cout<<it.first<<" "<<it.second<<"\n";
    }
    

    return 0;
}