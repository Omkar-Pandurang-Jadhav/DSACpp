# include<bits/stdc++.h>
using namespace std;
// Function sare set of code which performs something for you
// Functions are used to modularise code
// Functions are used to increase readability
// Functions are used to use same code multiple times
// void -> Which does not return anything
// return ->
// parameterised
// non parameterised

void printName(string name){
    cout<<name<<"\n";
}

int sum(int a,int b){
    return a+b;
}
// Pass by value copy is send
void dosomething(int a){
    cout<<a<<"\n";
    a=a+5;
    cout<<a<<"\n";
    a=a+5;
    cout<<a<<"\n";
    a=a+5;
    cout<<a<<"\n";
    a=a+5;
}
void dosomething1(int &a){
    cout<<a<<"\n";
    a=a+5;
    cout<<a<<"\n";
    a=a+5;
    cout<<a<<"\n";
    a=a+5;
    cout<<a<<"\n";
   // a=a+5;
}
// Pass by reference
void dosomething3(int arr[],int n){
   arr[0]+=100;
   cout<<"VAlue of arr[0] inside function is :"<<arr[0]<<"\n";
}
int main(){
 
    /*
    string name;
    getline(cin,name);
    printName(name);
    */

    // Take two number and prints its sum
    /*
    int a,b;
    cin >> a >> b;
    cout<<"The sum of two number is : "<<sum(a,b)<<"\n";
    int minimum=min(a,b);
    cout<<minimum;
    */

   // Pass by value
   /*
   int a=5;
   dosomething(a);
   cout<<a;
   */

  // pass by reference
  /*
  int a=5;
   dosomething1(a);
   cout<<a;
   */
  int n=5;
  int arr[n];
  for (int i=0;i<n;i++){
    cin>>arr[i];
  }
 
  for (int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<"\n";
  dosomething3(arr,n);
  cout<<"VAlue of arr[0] inside main is :"<<arr[0] ;
    return 0;
}