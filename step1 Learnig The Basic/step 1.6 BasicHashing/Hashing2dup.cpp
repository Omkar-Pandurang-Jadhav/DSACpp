# include<bits\stdc++.h>
using namespace std;

// Hashing for string
int main(){
    string s;
    cout<<"Enter the string - ";
    cin>>s;
    
    // consider only lower case character ASCII of a is 97 and z is 122
    // Precompute
    // So we consider a=0,b=1 and so on a so when char  comes in string we have we have to subtract value 97 by it
    // because 97 is ASCII value of a
    int Hash[26]={0};// a=0 z=25
    for(int i=0;i<s.length();i++){
        Hash[s[i]-'a']+=1;
    }
    int q;
    cout<<"Enter the number of queries - ";
    cin>>q;
    while(q--){
        char c;
        cout<<"Enter the charachter u want frequency of - ";
        cin>>c;
    cout<<Hash[c-'a']<<"\n";
}
    return 0;
}