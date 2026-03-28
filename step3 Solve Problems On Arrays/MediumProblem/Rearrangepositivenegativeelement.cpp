# include<bits/stdc++.h>
using namespace std;

// This program is about rearranging positive and negative element in an array where no of positive and
// negative element are equals

// Brute force solution
vector<int> positiveNegativeElement(vector<int> a,int n){

   // Time complexity is O(N)+O(N/2) and space complexity is O(N)
   vector<int> positive;
   vector<int> negative;

   for(int i=0;i<n;i++){
    if(a[i]<0){
       negative.push_back(a[i]);
    }
    else{
        positive.push_back(a[i]);
    }
   }
   for(int i=0;i<n/2;i++){
    a[2*i]=positive[i];
    a[2*i+1]=negative[i];
   }

   return a;
}

// Another optimal solution can be
vector<int> positiveNegativeElementdup1(vector<int> arr,int n){
    // Time complexity is O(N) and space complexity is O(N)
    int positive=0;
    int negative=1;
    vector<int> temp(n);

    for(int i=0;i<n;i++){
        if(arr[i]>0){
            temp[positive]=arr[i];
            positive=positive+2;
        }
        else{
            temp[negative]=arr[i];
            negative=negative+2;
        }
    }

    return temp;
}

// Another method if number of positive and negative are not same

vector<int> positiveNegativeElementdup2(vector<int> a,int n){
   vector<int> positive;
   vector<int> negative;

   // Time complexity is O(N)+O(min(positive,negative))+O(leftover) an
   // if all +ve or -ve than worst time coplexity is O(2*N) and for best case equal -ve and +ve than TC is O(N+N/2)
   for(int i=0;i<n;i++){
    if(a[i]<0){
       negative.push_back(a[i]);
    }
    else{
        positive.push_back(a[i]);
    }
   }
   if(positive.size()>negative.size()){
       for(int i=0;i<negative.size();i++){
        a[2*i]=positive[i];
        a[2*i+1]=negative[i];
       }
       int index=2*negative.size();
       for(int i=negative.size();i<positive.size();i++){
        a[index]=positive[i];
        index++;
       }
   }
   else{
    for(int i=0;i<positive.size();i++){
        a[2*i]=positive[i];
        a[2*i+1]=negative[i];
       }
       int index=2*positive.size();
       for(int i=positive.size();i<negative.size();i++){
        a[index]=negative[i];
        index++;
       }
   }

   return a;
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

    // vector<int> arr2=positiveNegativeElement(arr,n);
    // vector<int> arr2=positiveNegativeElementdup1(arr,n);
    vector<int> arr2=positiveNegativeElementdup2(arr,n);
    
    cout<<"The alternate array is : \n";
    for(int i=0;i<n;i++){
        cout<<arr2[i]<<" ";
    }

}