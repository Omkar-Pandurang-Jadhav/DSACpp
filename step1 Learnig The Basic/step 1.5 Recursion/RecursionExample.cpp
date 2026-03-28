# include<bits\stdc++.h>
using namespace std;

// Recursion is nothing but a function call itself with base condition
// Base condition is the condition when function stops calling itself and return 
//Stack overflow : stack is the place where uncompleted functions are store and overflow happens 
//when there is no base condition
// Recursion tree

// Example 1 
// Print name N times using Recursion
void Recursion1(int n){
    // Time complexity is O(n) since function is called n times and that of cout is O(1)
    // Space complexity O(n)
    if(n==0) return;
    cout<<"Hello ";
    n--;
    Recursion1(n);
}
// Example 2
// Print number from 1 to N using recursion
void Recursion2(int i,int n){
    /*
    if(i>n) return;
    cout<<i<<" ";
    i++;
    Recursion2(i,n);
    */
   // tcout<<"\n";
   // int n1=n-i+1;
    if(i<1) return;  // BackTracking
    Recursion2(i-1,n);
    cout<<i<<" ";
}
// Example 3
// Print N to 1 using recursion
void Recursion3(int n){
    // Using forward Tracking
     if(n==0) return ;
     cout<<n<<" ";
     n--;
     Recursion3(n);
}
// Another method for Example 3
void Recursion3dup(int i,int n){
    // Using Backtracking
     if(i>n) return;
     Recursion3dup(i+1,n);
     cout<<i<<" ";
}
// Example 4
// sum of first N natural number using recursion
void Recursion4(int i,int n,int sum){
    // Time complexity is O(n)
   //int sum;
   if(i<1){
    cout<<"The sum of all natural number till "<<n<<" is "<<sum<<" . \n";
    return;
   }
   Recursion4(i-1,n,sum+i);
}
// Another method for Example 4
int Recursion4dup(int n){
    // Time complexity is O(n)
    if(n==0){
        return 0;
    }
    return n+Recursion4dup(n-1);    
}
//Example 5
// Factorial using recursion
int Recursion5(int n){
    // Time Complexity is O(n)
     if(n==1 || n==0){
        return 1;
     }
     return n*Recursion5(n-1);
}
// Example 6
// Reverse an array using recursion
void Recursion6(int i,int a[],int n){
    // Time complexity is O(n)
    int temp;
    if(i < (n/2)) {
       temp=a[i];
       a[i]=a[n-1-i];
       a[n-1-i]=temp;
    Recursion6(i+1,a,n);
    }
}
// Another method to reverse an array
void Recursion6dup(int a[],int start,int end){
   // Time complexity is O(n)
    if(start<end){
        swap(a[start],a[end]);
        Recursion6dup(a,start+1,end-1);
    }
}
void printarray(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
      
// Example 7
// Check whether string is palindrome or not
bool Recursion7(string s,int i,int n){
    // Time complexity is O(n) basically it is O(n/2)
    string s1=s;
    char temp;
       
    if(i < n/2){
        temp=s[i];
        s[i]=s[n-i-1];
        s[n-i-1]=temp;
        Recursion7(s,i+1,n);
    }
     if(s1==s) return true;
     else return false;
}
// Another way to solve it 
bool Recursion7dup(string& s,int i){
    if(i>=s.length()/2) return true;

    if(s[i]!=s[s.length()-1-i]) return false;
    Recursion7dup(s,i+1);
}
// Example 8
// Fibonacci series
// ex input = 6, output = 0 1 1 2 3 5 8   0 based indexing
void Recursion8(int n,int i){
    int arr[n];
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<n;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    printarray(arr,n);  
}
int Recursion8dup(int n){
    // Time complexity is near about exponential in nature and it is O(2 to the power n)
    if(n==0 || n==1){
        return n;
    }

    return Recursion8dup(n-1)+Recursion8dup(n-2);
}
int main(){
     cout<<"Enter the number- \n";
     int n;
     cin>>n;
     cout<<"\n";
     Recursion1(n);
     cout<<"\n";
   //  Recursion2(1,n); // Forward Recursion
    Recursion2(n,n);  // Backward Recursion
     cout<<"\n";
    Recursion3(n);
     cout<<"\n";
    Recursion3dup(1,n);
     cout<<"\n";  
    Recursion4(n,n,0);
    cout<<"\n"; 
    int sum=Recursion4dup(n);
    cout<<"The sum of all natural number till "<<n<<" is "<<sum<<".";
    cout<<"\n";
    int factorial=Recursion5(n);
    cout<<"Factorial of number "<<n<<" is "<<factorial<<".";
    cout<<"\n";
    int n1;
    cout<<"Enter the size of an array -";
    cin>>n1;
     int arr[n1];
    cout<<"Enter the element of array - \n";
    for(int i=0;i<n1;i++){
        cin>> arr[i];
    }
   Recursion6(0,arr,n1);
   cout<<"\n";
   cout<<"Reverse of an array is - \n";
   printarray(arr,n1);
   cout<<"\n";
   Recursion6dup(arr,0,n1-1);
   printarray(arr,n1);
   string s;
   cout<<"\n";
   cout<<"Enter the String - ";
   cin>>s;
   int n2=s.size()/sizeof(char);
   if(Recursion7(s,0,n2)==true){
   cout<<"The string is a palindrome string \n" ;
   }
   else {
   cout<<"The string is not a palindrome string \n" ;
   }
   if(Recursion7dup(s,0)==true){
   cout<<"The string is a palindrome string \n" ;
   }
   else {
   cout<<"The string is not a palindrome string \n" ;
   }
   cout<<"\n";
   cout<<"Enter the index till you want to print fibonacci series : ";
   int n4;
   cin>>n4;
   Recursion8(n4+1,2);
  int fib = Recursion8dup(n4);
  cout<<"\n"<<fib;

   
    
    return 0;
}