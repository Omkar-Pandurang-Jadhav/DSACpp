#include <bits/stdc++.h>
using namespace std;

/*
Given two arrays, val[] and wt[], representing the values and weights of items,
and an integer capacity representing the maximum weight a knapsack can hold,
determine the maximum total value that can be achieved by putting items in the knapsack.
You are allowed to break items into fractions if necessary.
Return the maximum value as a double, rounded to 6 decimal places.

Examples :

Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
Output: 240.000000
Explanation: Take the item with value 60 and weight 10, value 100 and weight 20 and
split the third item with value 120 and weight 30, to fit it into weight 20. so it becomes
(120/30)*20=80, so the total value becomes 60+100+80.0=240.0 Thus, total maximum value of
item we can have is 240.00 from the given capacity of sack.
Input: val[] = [60, 100], wt[] = [10, 20], capacity = 50
Output: 160.000000
Explanation: Take both the items completely, without breaking. Total maximum value
of item we can have is 160.00 from the given capacity of sack.
Input: val[] = [10, 20, 30], wt[] = [5, 10, 15], capacity = 100
Output: 60.000000
Explanation: In this case, the knapsack capacity exceeds the combined weight of all items (5 + 10 + 15 = 30).
Therefore, we can take all items completely, yielding a total maximum value of 10 + 20 + 30 = 60.000000.
Constraints:
1 <= val.size=wt.size <= 105
1 <= capacity <= 109
1 <= val[i], wt[i] <= 104

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// class implemented

struct Item
{
    int val;
    int wt;
};

// Function to get the maximum total value in the knapsack.
bool static comp(Item a, Item b)
{
    double r1 = (double)a.val / (double)a.wt;
    double r2 = (double)b.val / (double)b.wt;

    return r1 >= r2;
}
double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
{
    // Your code here

    int n = val.size();
    vector<Item> arr(n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = {val[i], wt[i]};
    }

    sort(arr.begin(), arr.end(), comp);
    double totalval = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].wt <= capacity)
        {
            totalval = totalval + arr[i].val;
            capacity = capacity - arr[i].wt;
        }
        else
        {
            totalval += (double)((double)arr[i].val / (double)arr[i].wt) * capacity;
            break;
        }
    }
    return totalval;
}

int main()
{
    cout<<"Enter the size of an value and weight array : ";
    int n;
    cin>>n;
    vector<int> value(n);
    vector<int> weight(n);
    cout<<"Enter the element for an value with weight array : \n";
    for(int i=0;i<n;i++){
      cin>>value[i];
      cin>>weight[i];
    }
    cout<<"Enter the maximum capacity of knapsack : ";
    int capacity;
    cin>>capacity;
    double ans=fractionalKnapsack(value,weight,capacity);
    cout<<"The maximum value with fraction knapsack is : "<<ans;
    return 0;
}