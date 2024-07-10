# include<bits\stdc++.h>
using namespace std;
// Here we will learn important algorithm

bool comp(pair<int,int> p1, pair<int,int> p2){
    if(p1.second<p2.second) return true;
    else if(p1.second>p2.second) return false;
    else if(p1.second==p2.second){
        if(p1.first>p2.first) return true;
        else if(p1.first<p2.first) return false;
    }
    
}

void explainExtra(){
    int a[]={1,5,3,2};
    int n=4;
    sort(a,a+n);// a points to the address of 1 and n is size of array a+n points to the address next to 2
                 // similarly like [first,end)
    for(auto it:a){
        cout<<it<<" ";
    }

    // sort(v.begin(),v.end()) with this we can sort any container like vectors and array but not map
     // a[]={2,1,5,7,3,8,10}
    //sort(a+3,a+7) After sorting a[]={2,1,5,3,7,8,10}

    //sort(a,a+n,greater<int>); To sort array in descending order
     cout<<"\n";
    pair<int,int> a1[]={{1,2},{2,1},{4,1}};
    for(auto it:a1){
        cout<<it.first<<","<<it.second<<" ";
    }
    cout<<"\n";  
    // sort above pair according to second element in Ascending if second element is same than sort 
    // it according to first element but is descending
    int n1=3;
    sort(a1,a1+n1,comp);
    for(auto it:a1){
        cout<<it.first<<","<<it.second<<" ";
    }

    int num=7;
    int cnt=__builtin_popcount(num); // it return number of 1 in binary number of num
   
    long long num1=165786578687;
    int cnt1=__builtin_popcountl(num1);

    string s="123";
    sort(s.begin(),s.end());
    do{
        cout<< s <<endl;
    
    }while(next_permutation(s.begin(),s.end())); // it return all the permutation of string

    int maxi= *max_element(a,a+n);
    

}
int main(){

    explainExtra();


    return 0;
}