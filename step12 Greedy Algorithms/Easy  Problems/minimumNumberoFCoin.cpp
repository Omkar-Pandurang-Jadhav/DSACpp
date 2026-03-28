#include <bits/stdc++.h>
using namespace std;

int minimumNumberOfCoins(vector<int> coin, int val)
{
    // Time complexity at worst case is O(val) ans sc is O(1) 
    // This is only possible for if last two coins sum is less then the third one
    int n = coin.size();
    int cnt=0;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        while (val >= coin[i])
        {
            val -= coin[i];
            cnt++;
            ans.push_back(coin[i]);
        }
    }

    cout << "The minimum number of coins is " << ans.size() << endl;
    cout << "The coins are " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout<<"\n";
    return cnt;
}
int main()
{
    cout << "Enter the size of an  coin array : ";
    int n;
    cin >> n;
    vector<int> coin(n);
    cout << "Enter the element for an coin array : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
    cout << "Enter the value : ";
    int val;
    cin >> val;
    int cnt = minimumNumberOfCoins(coin, val);
    cout << "The minimum number of coins are : " << cnt;
    return 0;
}