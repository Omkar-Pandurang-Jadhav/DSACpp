# include<bits\stdc++.h>
using namespace std;

// Hashing is something like pre-storing and fetching
void arrayInput(int n,int a[]){
    for(int i=0;i<n;i++){
         cin>>a[i];
    }
}
void numOfTimeElementApperedInArrayPresentInQueries(int n,int q,int a[],int b[]){
    // Here time complexity is O(q*n) q is size of queri array and n is size of normal array
    // If size of array and Q is 10^5 and 10^5 then time complexity will be 10^10 which take 100 sec to run because 
    // 10^8 take 1 sec ,then this code is not usable if it take 100 sec this where Hasing comes in where its a trick to 
    //  to take less time
    int arr2[q];
    int cnt;
    for(int i=0;i<q;i++){
         cnt=0;
         for(int j=0;j<n;j++){
            if(b[i]==a[j]) cnt++;
         }
         arr2[i]=cnt;
    }
    cout<<"Queries"<<"-"<<"Repetition \n";
    for(int i=0;i<q;i++){
        cout<<b[i]<<"-"<<arr2[i];
        cout<<"\n";
    }
}
int main(){
     int n,q;
     cout<<"Enter the size of an array and Queries - ";
     cin>>n>>q;
     int arr[n],Q[q];
     cout<<"Enter array input for array  - \n";
     arrayInput(n,arr);
     cout<<"Enter array input for queries - \n";
     arrayInput(q,Q);
     numOfTimeElementApperedInArrayPresentInQueries(n,q,arr,Q);



    return 0;
}
