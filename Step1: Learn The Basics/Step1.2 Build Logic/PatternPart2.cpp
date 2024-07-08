# include<iostream>
using namespace std;

void pattern11(int n){
    for(int i=1;i<=n;i++){
        int start=i;
        for(int j=1;j<=i;j++){
            if(start%2==0){
                if(j%2==1){
                    cout<<"0 ";
                }
                else{
                    cout<<"1 ";
                }
            }
            else{
                if(j%2==0){
                    cout<<"0 ";
                }
                else{
                    cout<<"1 ";
                }
            }
        }
        cout<<"\n";
    }

    // Or
    /*
    int start;
    for(int i=1;i<=n;i++){
        if(i%2==1) start=1;
        else start=0;
        for(int j=1;j<=i;j++){
            cout<<start<<" ";
            start=1-start;
        }
        cout<<"\n";
    }
    */
}
void pattern12(int n){
    for(int i=1;i<=n;i++){
        // numbers
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        // space
        for(int sp=1;sp<=2*n-2*i;sp++){
            cout<<" ";
        }
        // numbers
        for(int j=i;j>=1;j--){
            cout<<j;
        }
        cout<<"\n";
    }
}
void pattern13(int n){
    int num=1;
    for(int i=1;i<=n;i++){
         for(int j=1;j<=i;j++){
           cout<<num<<" ";
           num++;
       }
       cout<<"\n";
    }
}
void pattern14(int n){
    
    for(int i=1;i<=n;i++){
        for(char ch='A';ch<='A'+i-1;ch++){
            cout<<ch<<" ";
        }
        cout<<"\n";
    }
}
void pattern15(int n){
    
    for(int i=1;i<=n;i++){
        for(char ch='A';ch<='A'+n-i;ch++){
            cout<<ch<<" ";
        }
        cout<<"\n";
    }
}
void pattern16(int n){
    char ch='A';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<ch<<" ";
        }
        ch++;
        cout<<"\n";
    }
}
void pattern17(int n){
    /*
    for(int i=1;i<=n;i++){
        for(int sp=1;sp<=n-i;sp++){
            cout<<" ";
        }
        for(char ch='A';ch<='A'+i-1;ch++){
            cout<<ch;
        }
        for(char ch='A'+i-2;ch>='A';ch--){
            cout<<ch;
        }
        for(int sp=1;sp<=n-i;sp++){
            cout<<" ";
        }
        cout<<"\n";
    }
    */
   // OR
   
   for(int i=1;i<=n;i++){
        for(int sp=1;sp<=n-i;sp++){
            cout<<" ";
        }
     char ch='A';
     int breakpoint=(2*i-1)/2;
       for(int j=1;j<=2*i-1;j++){
        cout<<ch;
        if(j<=breakpoint)ch++;
        else ch--;
       }
       cout<<"\n"; 
    }
}
void pattern18(int n){
    for(int i=1;i<=n;i++){ 
        for(char ch='A'+n-i;ch<='A'+n-1;ch++){
            cout<<ch<<" ";
        }
        cout<<"\n";
    }
    // or
    /*
    for(int i=1;i<=n;i++){ 
        for(char ch='E'-i+1;ch<='E';ch++){
            cout<<ch<<" ";
        }
        cout<<"\n";
    }
    */
}
void pattern19(int n){
    for(int i=1;i<=2*n;i++){
        int start1,start2;
       if(i>=1 && i<=n){
          start1=n-i+1;
          start2=2*i-2;
       }
       else if(i>=n+1 && i<=2*n){
        start1=i-n;
        start2=4*n-2*i;
       }
       for(int j=1;j<=start1;j++){
        cout<<"*";
       }
       for(int sp=1;sp<=start2;sp++){
        cout<<" ";
       }
       for(int j=1;j<=start1;j++){
        cout<<"*";
       }
       cout<<"\n";
    }
}
void pattern20(int n){
    for(int i=1;i<=2*n-1;i++){
        int start1,start2;
        if(i>=1 && i<=n){
            start1=i;
            start2=2*n-2*i;
        }
        else if(i>=n+1 && i<=2*n-1){
            start1=2*n-i;
            start2=2*i-2*n;
        }
        for(int j=1;j<=start1;j++){
            cout<<"*";
        }
        for(int sp=1;sp<=start2;sp++){
            cout<<" ";
        }
        for(int j=1;j<=start1;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
}
void pattern21(int n){
    /*
    for(int i=1;i<=n;i++){
        if(i==1 || i==n){
            for(int j=1;j<=n;j++){
                cout<<"*";
            }
            cout<<"\n";
        }
        else{
            for(int sp=1;sp<=n;sp++){
                if(sp==1 || sp==n) cout<<"*";
                else cout<<" ";
            }
             cout<<"\n";
        }
    }
    */
    // OR 
    for(int i=1;i<=n;i++){
        // condition i=1,j=1,i=n,j=n;
        for(int j=1;j<=n;j++){
            if(i==1 || i==n || j==1 || j==n) cout<<"*";
            else cout<<" ";
        }
        cout<<"\n";
    }
}
void pattern22(int n){
    for(int i=1;i<=2*n-1;i++){
        for(int j=1;j<=2*n-1;j++){
            int top=i-1,down=2*n-2-top,left=j-1,right=2*n-2-left;
            cout<< (n-min(min(top,down),min(left,right)));
        }
        cout<<"\n";
    }
}
int main(){

    int n;
    cout<<"Enter the Number :"<<"\n";
    cin>>n;
    cout<<"\n";
    cout<<"Pattern11 \n";
    pattern11(n);
    cout<<"\n";
    cout<<"Pattern12 \n";
    pattern12(n);
    cout<<"\n";
    cout<<"Pattern13 \n";
    pattern13(n);
    cout<<"\n";
    cout<<"Pattern14 \n";
    pattern14(n);
    cout<<"\n";
    cout<<"Pattern15 \n";
    pattern15(n);
    cout<<"\n";
    cout<<"Pattern16 \n";
    pattern16(n);
    cout<<"\n";
    cout<<"Pattern17 \n";
    pattern17(n);
    cout<<"\n";
    cout<<"Pattern18 \n";
    pattern18(n);
    cout<<"\n";
    cout<<"Pattern19 \n";
    pattern19(n);
    cout<<"\n";
    cout<<"Pattern20 \n";
    pattern20(n);
    cout<<"\n";
    cout<<"Pattern21 \n";
    pattern21(n);
    cout<<"\n";
    cout<<"Pattern22 \n";
    pattern22(n);


    return 0;
}