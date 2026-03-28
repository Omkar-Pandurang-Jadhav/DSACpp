#include <bits/stdc++.h>
using namespace std;

// Example Question
// arr1={1,3,5,7} arr2={0,2,6,8,9}
// final ans
// arr1={0,1,2,3} arr2={5,6,7,8,9 }


void printArray(vector<int> arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void swapIfGreater(vector<int> &arr1,vector<int> &arr2,int i,int j){
    if(arr1[i]>arr2[j]){
        swap(arr1[i],arr2[j]);
    }
}


// Brute Force
void merge(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    // Time complexity is O(m+n)+O(m+n)
    // Space complexity is O(m+n)
    vector<int> arr3;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] > arr2[j])
        {
            arr3.push_back(arr2[j]);
            j++;
        }
        else
        {
            arr3.push_back(arr1[i]);
            i++;
        }
    }
    while (i < n)
    {
        arr3.push_back(arr1[i]);
        i++;
    }
    while (j < m)
    {
        arr3.push_back(arr2[j]);
        j++;
    }
    for (int i = 0; i < n + m; i++)
    {
        if (i >= 0 && i < n)
        {
            arr1[i] = arr3[i];
        }
        else
        {
            arr2[i - n] = arr3[i];
        }
    }
    
}

// 1st Optimal solution Without using extra space
void mergeOptimal1(vector<int> &arr1,vector<int> &arr2,int n,int m){
    // Time comlexity is O(min(n,m))+O(nLog(n))+O(mlog(m))
    // space compexity is O(1)

    int i=n-1;
    int j=0;
    while(i>=0 && j<m){
        if(arr1[i]>arr2[j]){
            int temp=arr1[i];
            arr1[i]=arr2[j];
            arr2[j]=temp;
            i--;
            j++;
        }
        else{
            break;
        }
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
}

// 2nd Optimal solution Know as gap method
void mergeOptimal2(vector<int> &arr1,vector<int> &arr2,int n,int m){
    // Time complexity is O(Log2(m+n))*O(m+n)
    int len=m+n;
    int gap=(len/2)+(len%2);
    
    while(gap>0){
        int left=0;
        int right=left+gap;

        while(right<len){
            // arr1 and arr2
            if(left<n && right>=n){
                swapIfGreater(arr1,arr2,left,right-n);
            }
            // arr2 and arr2
            else if(left>=n){
                swapIfGreater(arr2,arr2,left-n,right-n);
            }
            // arr1 and arr1
            else {
                swapIfGreater(arr1,arr1,left,right);
            }
            left++;
            right++;
        }
        if(gap==1) break;
        gap=(gap/2)+(gap%2);
    }
}
int main()
{
    cout << "Enter the size of an array1 and array2: ";
    int n,m;
    cin >> n>>m;
    vector<int> arr1(n);
    vector<int> arr2(m);
    cout << "Enter the element for an array1 : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    cout << "Enter the element for an array2 : \n";
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

   // merge(arr1,arr2,n,m);
   // mergeOptimal1(arr1,arr2,n,m);
    mergeOptimal2(arr1,arr2,n,m);
    cout<<"The array 1 is : \n";
    printArray(arr1,n);
    cout<<"\n";
    cout<<"The array 2 is : \n";
    printArray(arr2,m);
    return 0;
}