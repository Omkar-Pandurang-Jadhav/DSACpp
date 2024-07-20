# include<bits/stdc++.h>
using namespace std;

//If we declare array inside int main then array store garbage value
//But the array is declared befor int main then the array stores the value 0.
// Maximum size length is of array inside main is 10^6 and globally is 10^7.
int largestElementInArray(vector<int> &arr,int n){
    // Time complexity is O(N).  
    int largest=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    return largest;
}
// Second Largest Element in an array without Sorting
int secondLargestElementInArray(vector<int> &arr,int n){
    // Time Complexity is O(2*N)
    int largest=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    
    int secondLargest=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>secondLargest && arr[i]!=largest){
         //  if(arr[i]==largest) continue;
           secondLargest=arr[i];
        }
    }
    return secondLargest;
}
// Another better way to find second largest asumming there is no -ve number in an array
int secondLargestElementInArraydup(vector<int> &arr,int n){
    int largest =arr[0];
    int secondLargest=-1;
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            secondLargest=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest && arr[i]>secondLargest){
            secondLargest=arr[i];
        }
    }
    return secondLargest;
}
int secondSmallestElementInArray(vector<int> & arr,int n){
    int smallest =arr[0];
    int secondSmallest=INT_MAX;
    for(int i=1;i<n;i++){
        if(arr[i]<smallest){
            secondSmallest=smallest;
            smallest=arr[i];
        }
        else if(arr[i]>smallest && arr[i]<secondSmallest){
            secondSmallest=arr[i];
        }
    }
    return secondSmallest;
}
vector<int> secondLargestAndSmallest(vector<int> arr,int n){
       int slargest=secondLargestElementInArraydup(arr,n);
       int ssmallest=secondSmallestElementInArray(arr,n);

       return {slargest,ssmallest};
}
bool isSorted(vector<int> &arr,int n){
    // Time complexity is O(N)
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]){
            return true;
        }
        else {
            return false;
        }
    }
}
// Remove duplicate from sorted arrays and return number of unique element
// Brute force approch

int numberOfUniqueElement(vector<int> &arr,int n){
    sort(arr.begin(),arr.end());
    set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    int index=0;
    for(auto it:st){
        arr[index]=it;
        index++;
    }
    return index;
}

// Optimal approch
int numberOfUniqueElementdup(vector<int> &arr,int n){
    sort(arr.begin(),arr.end());
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[i]!=arr[j]){
            arr[i+1]=arr[j];
            i++;
        }
    }
    return i+1;
}

int main(){
    int n;
    cout<<"Enter the size of an array : ";
    cin>>n;
    //int arr[n];
    vector<int> arr(n);
    cout<<"Enter the element of an array : \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int largest=largestElementInArray(arr,n);
    cout<<"The largest element of an array is : "<<largest<<". \n";
    int secondLargest=secondLargestElementInArraydup(arr,n);
    cout<<"The second largest element of an array is : "<<secondLargest<<". \n";

    vector<int> arr2=secondLargestAndSmallest(arr,n);
    cout<<"The second largest and smallest element is : \n";
    for(int i=0;i<arr2.size();i++){
        cout<<arr2[i]<<" ";
    }
    cout<<"\n";
    cout<<"Is array is sorted : "<<isSorted(arr,n)<<"\n";

    cout<<"The number of unique Element in sorted Array is : \n";
    cout<<numberOfUniqueElement(arr,n);
    cout<<" "<<numberOfUniqueElementdup(arr,n);



    return 0;
}
