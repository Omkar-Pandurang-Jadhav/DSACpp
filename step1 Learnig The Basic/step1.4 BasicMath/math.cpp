# include<bits\stdc++.h>

using namespace std;

int countDigit(int n){
    // Time complexity is O(log10(n))
    //if number is divided by 2 the time complexity is O(log2(n)) ~
    int num=n;
    int count=0;
    /*
    while(num>0){
        num=num/10;
        count++;
    }
    */
    // or
    count=log10(n)+1;

    return count;
}

int reverseNum(int n){
    int num=n;
    int rev=0;
    while(num>0){
        int rem=num%10;
        rev=rev*10+rem;
        num=num/10;
    }
    return rev;
}
bool palindromeNum(int n){
    int dup=n;
    int num=n;
    int rev=0;
    while(num>0){
        int rem=num%10;
        rev=rev*10+rem;
        num=num/10;
    }
    
    if(dup==rev) {
        return true ;
    }
    else {
         return false;
    }
}
bool ArmstrongNum(int n){
    int num=n;
    int dup=n;
    int count=to_string(num).length();
    int armstrong=0;

    num=n;
    while(num>0){
        int rem;
        rem=num%10;
        armstrong=armstrong+pow(rem,count);
        num=num/10;
    }
    if(dup==armstrong) return true;
    else return false;
}
bool isDivisor(int n,int d){
     if(n%d==0)return true;
     else return false;
}
void DivisibleNum(int n){    
    // Time complexity is O(num) 
    int num=n;
    for(int i=1;i<=num;i++){
        if(isDivisor(num,i)){
            cout<<i<<" ";
        }
    }
}
// Seconf approch for printing divisor
vector<int> findDivisor(int n){
    // Time complexity is O(sqrtN)
    int num=n;
    vector<int> divisor;
    int sqrtN =sqrt(num);
    for(int i=1;i<=sqrtN;i++){
        if(num%i==0){
            divisor.push_back(i);
            if(i!=n/i){
            divisor.push_back(n/i);
         }
        }
         
    }
    // Time complexity is O(No of factor * log(No of factor))
    sort(divisor.begin(),divisor.end());
    // Time complexity is O(No of factor)
    for(auto it : divisor){
        cout<<it<<" ";
     }

     // Total time complexity is  O(sqrtN)+O(No of factor * log(No of factor))+O(No of factor)

    return divisor;
}
bool isPrime(int n){
    bool a=true;
    // Time Complexity is O(sqrt(N))
    if(n!= 2 && n!=1){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i!=0) return a=true;
        else return a=false;
    }
    }
    if(n==1) return a=false;
    if(n==2) return a=true;
    return a;
}

int main(){
    int n1;
    cout<<"Enter the number -"<<"\n";
    cin>>n1;

    int cnt=countDigit(n1);
    cout<<"The number of digit in number "<<n1<<" is "<<cnt<<" . \n";

    int rev=reverseNum(n1);
    cout<<"Reverse of number "<<n1<<" is "<<rev<<" . \n";

    if(palindromeNum(n1)) cout<<"The number "<<n1<<" is a palindrome number. \n";
    else cout<<"The number "<<n1<<" is not a palindrome number. \n";

     int n2;
     cout<<"Enter the number to check whether it is armstrong or not -"<<"\n";
     cin>>n2;

    if(ArmstrongNum(n2)) cout<<"The number "<<n2<<" is a Armstrong number. \n";
    else cout<<"The number "<<n2<<" is not a Armstrong number. \n";
    
    int n3;
     cout<<"Enter the number to check divisors of number -"<<"\n";
     cin>>n3;
     cout<<"The divisors of num "<<n3<<" is - \n";
     DivisibleNum(n3);
     cout<<"\n";

     findDivisor(n3);
     
     
      int n4;
      cout<<"\n";
     cout<<"Enter the number to check whether it is prime or not -"<<"\n";
     cin>>n4;
     if(isPrime(n4)) cout<<n4<<" is a prime number . \n";
     else cout<<n4<<" is not a prime number . \n";
     cout<<"\n";

     
    return 0;
}