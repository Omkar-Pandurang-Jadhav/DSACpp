# include<iostream>
using namespace std;
/*
Take day no and print the correasponding day
for 1 print Monday,
for 2 print Tuesday and so on for 7 print Sunday
*/

int main(){
    int day;
    cout<<"Enter the day no between 1 to 7 : \n";
    cin>> day;

        switch(day){
            case 1:
            cout<<"Monday";
            break;
            case 2:
            cout<<"Tuesday";
            break;
            case 3:
            cout<<"Wednesday";
            break;
            case 4:
            cout<<"Thursday";
            break;
            case 5:
            cout<<"Friday";
            break;
            case 6:
            cout<<"Saturday";
            break;
            case 7:
            cout<<"Sunday";
            break;
            default:
            cout<<"Invalid.";
            break;
        }
   
    
        
    
    return 0;
}