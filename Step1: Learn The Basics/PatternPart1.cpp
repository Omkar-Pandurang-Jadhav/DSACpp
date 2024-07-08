# include<iostream>
using namespace std;

void pattern1(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           cout<<"* ";
        }
        cout<<"\n";
    }
}
void pattern2(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
           cout<<"* ";
        }
        cout<<"\n";
    }
}
void pattern3(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
           cout<<j<<" ";
        }
        cout<<"\n";
    }
}
void pattern4(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}
void pattern5(int n){
    /*
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<"\n";
    }
    */
   // Or
   for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cout<<"* ";
        }
        cout<<"\n";
    }
}
void pattern6(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}
void pattern7(int n){
   
    for(int i=1;i<=n;i++){
        for(int sp=1;sp<=n-i;sp++){
            cout<<" ";
        }
        for(int j=1;j<=2*i-1;j++){
            cout<<"*";
        }
        for(int sp=n-i;sp>=1;sp--){
            cout<<" ";
        }
        cout<<"\n";
    }
   
}
void pattern8(int n){
    for(int i=1;i<=n;i++){
        for(int sp=1;sp<=i-1;sp++){
            cout<<" ";
        }
        for(int j=1;j<=2*n+1-2*i;j++){
            cout<<"*";
        }
        for(int sp=1;sp<=i-1;sp++){
            cout<<" ";
        }
        cout<<"\n";
    }
}
void pattern9(int n){
    for(int i=1;i<=2*n;i++){
        int start1,start2;
        if(i>=1 && i<=n){
            start1=n-i;
            start2=2*i-1;
        }
        else if(i>=n+1 && i<=2*n){
            start1=i-n-1;
            start2=4*n+1-2*i;
        }
        for(int sp=1;sp<=start1;sp++){
                cout<<" ";
            }
        for(int j=1;j<=start2;j++){
                cout<<"*";
            }
        cout<<"\n";
    }
}
void pattern10(int n){
    for(int i=1;i<=2*n-1;i++){
        int start;
        if(i>=1 && i<=n){
           start=i;
        }
        else if(i>=n+1 && i<=2*n-1){
            start=2*n-i;
        }
         for(int j=1;j<=start;j++){
                cout<<"*";
            }
        cout<<"\n";
    }
}
int main(){
    int n;
    cout<<"Enter the Number :"<<"\n";
    cin>>n;
    cout<<"Pattern1 \n";
    pattern1(n);
     cout<<"\n";
     cout<<"Pattern2 \n";
    pattern2(n);
     cout<<"\n";
     cout<<"Pattern3 \n";
    pattern3(n);
     cout<<"\n";
     cout<<"Pattern4 \n";
    pattern4(n);
     cout<<"\n";
     cout<<"Pattern5 \n";
    pattern5(n);
     cout<<"\n";
     cout<<"Pattern6 \n";
    pattern6(n);
     cout<<"\n";
     cout<<"Pattern7 \n";
    pattern7(n);
    cout<<"\n";
    cout<<"Pattern8 \n";
    pattern8(n);
     cout<<"\n";
     cout<<"Pattern9 \n";
    pattern9(n);
    cout<<"\n";
    cout<<"Pattern10 \n";
    pattern10(n);

    return 0;
}
