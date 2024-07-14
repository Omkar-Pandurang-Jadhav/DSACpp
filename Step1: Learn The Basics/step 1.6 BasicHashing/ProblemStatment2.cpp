# include<bits/stdc++.h>
using namespace std;

// Given an array of size N.Find the highest and lowest frequency element.

void Frequency(int a[],int n){
  // Time complexity is O(N)
  // Using map
   int maxKey,maxOccur=0,minKey,minOccur=n;
   map<int,int> mpp;
   for(int i=0;i<n;i++){
    mpp[a[i]]++;
   }
   for(auto it : mpp){
    if(maxOccur<it.second){
      maxOccur=it.second;
      maxKey=it.first;
    }
    if(minOccur>it.second){
      minOccur=it.second;
      minKey=it.first;
    }
   }
   cout<<"The element which occur maximum time is "<<maxKey<<" with frequency "<<maxOccur<<" . \n";
   cout<<"The element which occur minimum time is "<<minKey<<" with frequency "<<minOccur<<" . \n";
  
}
void countFrequency(int a[],int n){
    // Time complexity is O(N*N) and space complexity is O(N)
   vector<bool> visited(n,false);
  int maxKey,maxOccur=0,minKey,minOccur=n;
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
    if(maxOccur<count){
      maxOccur=count;
      maxKey=a[i];
    }
    if(minOccur>count){
      minOccur=count;
      minKey=a[i];
    }
   }
   cout<<"The element which occur maximum time is "<<maxKey<<" with frequency "<<maxOccur<<" . \n";
   cout<<"The element which occur minimum time is "<<minKey<<" with frequency "<<minOccur<<" . \n";
}

int main(){
   int arr[]={10,5,10,15,10,5};
   int n=sizeof(arr)/sizeof(arr[0]);
    
   // int max=max_element(mpp);
   // cout<<max;
   countFrequency(arr,n);
   cout<<"\n";
   Frequency(arr,n);

    return 0;
}