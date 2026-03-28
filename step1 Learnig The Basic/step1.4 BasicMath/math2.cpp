# include<bits\stdc++.h>
using namespace std;


int findGreatestCommonFactor(int n1,int n2){
    /*
    Way 1
    // Time complexity is O(min(n1,n2))
    vector<int> v;
    int n=min(n1,n2);
    for(int i=1;i<=n;i++){
        if(n1%i==0 && n2%i==0){
            v.push_back(i);
        }
    }
    return *max_element(v.begin(),v.end());
    */
   // Way 2
   /*
   // Time complexity is O(min(n1,n2))
   int n=min(n1,n2);
   int num;
   for(int i=n;i>=1;i--){
    if(n1%i==0 && n2%i==0){
        num=i;
        break;
    }
   }
   return num;
   */
  // Way 3
  // if(a>b)
  // then gcd(a,b)=gcd(a-b,b)
  // for example gcd(25,20)=gcd(5,20)=gcd(5,15)=gcd(5,10)=gcd(5,5)=gcd(0,5)=5
  // Time complexity is O(N) N= number of steps to become one of the value to become 0
  // As we can see there are so many steps in above process is also we can reduce it by using mod 
  // Euclidean Algorithm by minus
  /*
  int a=n1,b=n2;
  while(a>0 && b>0){
    if(a>=b) a=a-b;
    else if (b>=a) b=b-a;
  }
   if(a==0) return b;
   else if(b==0) return a;
   */

  // Way 4
  // Euclidean Algorithm by modulo
  // if(a>b)
  // gcd(a,b)=gcd(c%b,b)
  // for example gcd(25,20)=gcd(5,20)=gcd(5,0)=5
  // We can see that in modulo we can save many step then in minus

  // Time complexity is log(phi)(min(a,b))  phi is changing everytime
  // whenever we divide any number by phi than time complexity become log(phi)(number)
  int a=n1,b=n2;

  while(a>0 && b>0){
    if(a>=b) a=a%b;
    else if (b>=a) b=b%a;
  }
  if(a==0) return b;
  else if(b==0) return a;
}

int main(){

    int n1,n2;
     cout<<"Enter two number to find greatest common factor - \n";
     cin>>n1>>n2;
     cout<<endl;
     int commonFactor=findGreatestCommonFactor(n1,n2);
     cout<<"The greatest common factor of number "<<n1<<" and "<<n2<<" is "<<commonFactor<<" .\n";


    return 0;
}