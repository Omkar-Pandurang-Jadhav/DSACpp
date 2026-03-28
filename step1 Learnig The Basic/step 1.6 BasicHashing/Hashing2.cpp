# include<bits\stdc++.h>
using namespace std;

// character Hashing
int frquency(char c,string s,int n){
     int cnt=0;
     for(int i=0;i<n;i++){
        if(s[i]==c) cnt++;
     }
     return cnt;
}
int main(){
    // Time complexity is O(n2*n1)
    cout<<"Enter the string - ";
    string s;
    cin>>s;
    int n1;
    cout<<"Enter the size of queries - ";
    cin>>n1;
    char c1[n1];
    for(int i=0;i<n1;i++){
        cin>> c1[i];
    }
    int n2=sizeof(s)/sizeof(s[0]);
    int arr[n1];
     for(int i=0;i<n1;i++){
        arr[i]=frquency(c1[i],s,n2);
     }
     cout<<"Character-Repetition \n";
     for(int i=0;i<n1;i++){
        cout<<c1[i]<<"-"<<arr[i];
        cout<<"\n";
     }

    return 0;
}