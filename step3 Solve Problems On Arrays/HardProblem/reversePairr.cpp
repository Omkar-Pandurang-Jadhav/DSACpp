#include <bits/stdc++.h>
using namespace std;

//  Return the count of pair where i<j and a[i]>2*arr[j]
//  Example :-
//  arr[]={40,25,19,12,9,6,2}
//  ans=(40,19) (40,12) (40,9) (40,6) (40,2) (25,12) (25,9) (25,6) (25,2)
//   (19,9) (19,2) (19,6) (12,2) (9,2) (6,2)
//   final ans is 14

// Brute Force
int reversePairCount(vector<int> arr, int n)
{
    // Time complexity is O(N*N) and space complexity is O(1)
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > 2 * arr[j])
            {
                cnt++;
            }
        }
    }
    return cnt;
}
void merge(vector<int> &arr,int low,int mid,int high){
    int left=low;
    int right=mid+1;
    vector<int> temp;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
int countPairs(vector<int> arr,int low,int mid,int high){
    int right=mid+1;
    int cnt=0;
    for(int i=low;i<=mid;i++){
        while(right<=high && arr[i]>2*arr[right]) right++;
        cnt=cnt+right-(mid+1);
    }
    return cnt;
}
int mergeSort(vector<int> &arr,int low,int high){
    int cnt=0;
    if(low>=high) return cnt;
    int mid=(low+high)/2;
    cnt=cnt+mergeSort(arr,low,mid);
    cnt=cnt+mergeSort(arr,mid+1,high);
    cnt=cnt+countPairs(arr,low,mid,high);
    merge(arr,low,mid,high);

    return cnt;
}
// Optimal solution using merge sort
int reversePairCountdup1(vector<int> arr, int n)
{  
    // Time complexity is O(NlogN)+O(NlogN)
    // Space complexity is O(N)
    int ans = mergeSort(arr, 0, n - 1);

    return ans;
}
int main()
{
    int n;
    cout << "Enter the size of an array : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the element for an array : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // int ans=reversePairCount(arr,n);
    int ans = reversePairCountdup1(arr, n);
    cout << "The count of reverse pair is : " << ans << " .";

    return 0;
}