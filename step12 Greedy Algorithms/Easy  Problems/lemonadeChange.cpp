# include<bits/stdc++.h>
using namespace std;

// At a lemonade stand, each lemonade costs $5. Customers are 
//standing in a queue to buy from you and order one at a time 
//(in the order specified by bills). Each customer will only buy one lemonade and
// pay with either a $5, $10, or $20 bill. You must provide the correct change
// to each customer so that the net transaction is that the customer pays $5.

// Note that you do not have any change in hand at first.

// Given an integer array bills where bills[i] is the bill the ith customer pays,
// return true if you can provide every customer with the correct change, or false otherwise.

 

// Example 1:

// Input: bills = [5,5,5,10,20]
// Output: true
// Explanation: 
// From the first 3 customers, we collect three $5 bills in order.
// From the fourth customer, we collect a $10 bill and give back a $5.
// From the fifth customer, we give a $10 bill and a $5 bill.
// Since all customers got correct change, we output true.
// Example 2:

// Input: bills = [5,5,10,10,20]
// Output: false
// Explanation: 
// From the first two customers in order, we collect two $5 bills.
// For the next two customers in order, we collect a $10 bill and give back a $5 bill.
// For the last customer, we can not give the change of $15 back because we only have two $10 bills.
// Since not every customer received the correct change, the answer is false.
 

// Constraints:

// 1 <= bills.length <= 105
// bills[i] is either 5, 10, or 20.


bool lemonadeChange(vector<int>& bills){
    // Time complexity is O(n)
    int p=0,q=0,r=0;
    int n=bills.size();
    for(int i=0;i<n;i++){
        if(bills[i]==5) p++;
        else if(bills[i]==10){
            q++;
            p--;
        }
        else if(bills[i]==20){
            r++;
            if(q>0){
                q--;
                p--;
            }
            else {
                p=p-3;
            }
        }

        if(p<0 || q<0 || r<0){
            return false;
        }
    }

    return true;
}
int main(){
    cout<<"Enter the size of an bill array : ";
    int n;
    cin>>n;
    vector<int> bills(n);
    cout<<"Enter the element for an bill array it should be 5,10 or 20 : \n";
    for(int i=0;i<n;i++){
      cin>>bills[i];
    }
    bool ans=lemonadeChange(bills);
    cout<<"The customer with correct change is : "<<ans;

    return 0;
}