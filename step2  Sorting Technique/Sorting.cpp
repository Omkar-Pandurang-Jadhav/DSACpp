# include<bits/stdc++.h>
using namespace std;

void SelectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int temp;
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void BubbleSort(int arr[],int n){
    int didswap=0;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                didswap=1;
            }
        }
        if(didswap==0)
            break;
    }
    
}
void InsertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
      int  j=i;
      while(j>0 && arr[j-1]>arr[j]){
        int temp=arr[j-1];
        arr[j-1]=arr[j];
        arr[j]=temp;
        j--;
      }
    }
}
void Merge(int arr[],int low,int mid,int high){
    int left=low;
    int right=mid+1;
    vector<int> v;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
         v.push_back(arr[left]);
         left++;
        }
        else {
            v.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        v.push_back(arr[left]);
         left++;
    }
    while(right<=high){
        v.push_back(arr[right]);
        right++;
    }
    
    for(int i=low;i<=high;i++){
         arr[i]=v[i-low];
    }
}

void MergeSort(int arr[],int low,int high){
    if(low>=high) return;
    int mid=(low+high)/2;
    MergeSort(arr,low,mid);
    MergeSort(arr,mid+1,high);
    Merge(arr,low,mid,high);
}
int PartitionSort(int arr[],int low,int high){
       int pivot=arr[low];
       int i=low;
       int j=high;
       while(i<j){
        while(arr[i]<=pivot && i<=high-1){
          i++;
        }    
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
       }
       swap(arr[low],arr[j]);
       return j;
}
void QuickSort(int arr[],int low,int high){
    if(low<high){
        int PE=PartitionSort(arr,low,high);
        QuickSort(arr,low,PE-1);
        QuickSort(arr,PE+1,high);
    }
}  
void RecursionBubbleSort(int arr[],int n){
     if(n==0) return;
     int didswap=0;
    for(int j=0;j<n;j++){
        if(arr[j]>arr[j+1]){
        int temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
        didswap=1;
       }
    }
    if(didswap==0) 
    return;
    RecursionBubbleSort(arr,n-1);
}
void RecursionInsertionSort(int arr[],int i,int n){
    if(i==n) return;
     int j=i;
     while(j>0 && arr[j-1]>arr[j]){
        int temp=arr[j];
        arr[j]=arr[j-1];
        arr[j-1]=temp;
        j--;
     }
     RecursionInsertionSort(arr,i+1,n);

}
int main(){
     int n;
    cout<<"Enter the size of an Array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the element for an Array : \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   // SelectionSort(arr,n);
   // BubbleSort(arr,n);
   // InsertionSort(arr,n);
   // MergeSort(arr,0,n-1);
   // QuickSort(arr,0,n-1);
   // RecursionBubbleSort(arr,n-1);
   RecursionInsertionSort(arr,1,n);
    cout<<"The sorted array by recursive bubblesort is : \n";
    for(int i=0;i<n;i++){
       cout<<arr[i]<<" ";
    }


    return 0;
}