# include<bits/stdc++.h>
using namespace std;

// This program contains three problem 
// 1st problem is index will be given on the given index we have to find 
// element at that index
// 2nd is we have to print the nth row of pascals triangle
// 3rd we have to print pascal triangle

int fact(int n,int r){
    // Time complexity is is O(r) or O(c-1) and space complexity is O(1)
   int res=1;
   for(int i=0;i<r;i++){
    res=res*(n-i);
    res=res/(i+1);
   }
   return res;
}

// Brute Force Solution
void printRowOfPascalTriangle(int n){
    // Time complexity is O(n*r) or O(n2*r) and space complexity is O(1)
    for(int i=0;i<n;i++){
        cout<<fact(n-1,i)<<" ";
    }
}

// Better solution for above problem
void printRowOfPascalTriangledup(int n){
    // Time complexity is O(N) and space complexity is O(1)
    int ans=1;
    cout<<ans<<" ";
    for(int i=1;i<n;i++){
       ans=ans*(n-i);
       ans=ans/i;
       cout<<ans<<" "; 
    }
}

// brute force solution by using fact function
void printPascalTriangle(int n){
    // Time complexity is O(n*n*r) which is nearly equal to O(n*n*n)
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<fact(i-1,j-1)<<" ";
        }
        cout<<"\n";
    }
}

// Optimal soultion
void printPascalTriangledup(int n){
    // Here time complexity is nearly equal to O(n*n)
    for(int i=1;i<=n;i++){
        printRowOfPascalTriangledup(i);
        cout<<"\n";
    }
}
int main(){
    int n,c;
    cout<<"Enter the nth row and cth column : ";
    cin>>n>>c;
    int element=fact(n-1,c-1);
    cout<<"The element at index "<<n<<","<<c<<" is : "<<element<<"\n";

    cout<<"Enter the row no you want to print : ";
    int n2;
    cin>>n2;
    cout<<"The "<<n2<<"th row of pascal triangle is : \n";
    // printRowOfPascalTriangle(n2);
    printRowOfPascalTriangledup(n2);
     cout<<"\n";
    cout<<"Engter the number n for pascal triangle : \n";
    int n3;
    cin>>n3;
    cout<<"The pascal triangle is : \n";
    // printPascalTriangle(n3);
    printPascalTriangledup(n3);

    return 0;
}   