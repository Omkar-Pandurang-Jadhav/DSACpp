# include<bits/stdc++.h>
using namespace std;

// This is the program about the best time to buy and sell the stock in order to maximize the profit
// We can do this only once

int BuyAndSell(vector<int> arr,int n){
    int profit=0;
    int mini=arr[0];
    int cost;
    for(int i=1;i<n;i++){
        cost=arr[i]-mini;
        profit=max(profit,cost);
        mini=min(mini,arr[i]);
    }

    return profit;
}
int main(){
    int n;
    cout<<"Enter the number of days within which you will buy and sell stock : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the stock price with respect to days : \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxProfit=BuyAndSell(arr,n);
    cout<<"The maximum profit is "<<maxProfit;

    return 0;
}