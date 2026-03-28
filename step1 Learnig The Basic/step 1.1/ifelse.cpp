#include<iostream>
using namespace std;
/*
 Write a program that takes an input of age
 and prints id you are adult or not.
 >=18 ,yes
 < 18 ,no 
*/
/*
A school has following rules for grading system:
a.Bellow 25 - F
b. 25 to 44 - E
c. 45 to 49 - D
d. 50 to 59 - C
e. 60 to 79 - B
f. 80 to 100 - A
*/

/*
Take theage from the user and then decide accordingly
1.If age<18,
print -> not eligible for job
2. If age>=18,
print -> eligible for job
3.if age>=55and age<=57,
print ->"Eligible for job,but retirement soon."
4.if age> 57,
print ->"Retirement Time"
*/

int main(){
    // Problem 1
    /*
    int age;
    cout<<"Enter the age of your : \n";
    cin>> age;
    if(age>=18){
        cout<<"You are an adult.";
    }
    else if(age<18){
       cout<<"You are not an adult." ;
    }
    */

   // Problem 2
   /*
   int marks;
   cout<<"Enter the marks  of your out of 100 : \n";
   cin>> marks;
   if(marks<=100 && marks>=80){
    cout<<"A Grade.";
   }
   else if(marks<=79 && marks>=60){
    cout<<"B Grade.";      
   }
   else if(marks<=59 && marks>=50){
    cout<<"C Grade.";
   }
   else if(marks<=49 && marks>=45){
    cout<<"D Grade.";
   }
   else if(marks<=44 && marks>=25){
    cout<<"E Grade.";
   }
   else if(marks<25){
    cout<<"F Grade.";
   }
   else{
    cout<<"You have enter wrong number.";
   }
   */

  // Example of nested if
  // Problem 3
  int age;
    cout<<"Enter the age of your : \n";
    cin>> age;
    if(age<18){
        cout<<"Not eligible for job.";
    }
    else if(age>=18){
        if(age<=54){
            cout<<"Eligible for the job.";
        }
        else if(age>=55 && age<=57){
            cout<<"Eligible for the job,but retirement soon.";
        }
        else if (age>57){
            cout<<"Time for retirement.";
        }
    }
   
    return 0;
}