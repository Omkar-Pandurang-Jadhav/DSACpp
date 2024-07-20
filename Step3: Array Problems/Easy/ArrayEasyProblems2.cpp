# include<bits/stdc++.h>
using namespace std;


void inputArray(vector<int> &arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
// Left Rotate the array by one place
vector<int> leftRotateArrayByOnePlace(vector<int> &arr,int n){
    // Time Complexity is O(N) and Space Complexity is O(1)
    // Space use in Algorithm is O(N) and Extra space is O(1)
    int firstElement=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=firstElement;
    return arr;
}
void printArray(vector<int> arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

// Left Rotate an array by D places
vector<int> leftRotateArrayByDPlace(vector<int> &arr,int n){
    int d;
    cout<<"Enter the number you want to rotate to left : ";
    cin>>d;
    d=d%n;
    vector<int> v(n-d);
    for(int i=0;i<n-d;i++){
        v[i]=arr[i];
    }
    for(int i=n-1;i>=0;i--){
        int temp=i-d;
        if(i>=0 && i<n-d){
            if(temp<0){
                arr[temp+n]=v[i];
            }
            else{
                arr[temp]=v[i];
            }
        }
        else if(i<n && i>=n-d){
            if(temp<0){
                arr[temp+n]=arr[i];
            }
            else{
                arr[temp]=arr[i];
            }
        }
        else {
            arr[temp]=arr[i];
        }
    }

    return arr;
}
//Another brute force Approach for Left Rotate an array by D places
vector<int> leftRotateArrayByDPlacedup1(vector<int> &arr,int n){
    // Time complexity is O(d)+O(n-d)+O(d)=O(n+d)
    // Space complexity is O(d)
    int d;
    cout<<"Enter the number you want to rotate to left : ";
    cin>>d;
    d=d%n;
    vector<int> temp(d);
    for(int i=0;i<d;i++){
       temp[i]=arr[i];
    }
    for(int i=d;i<n;i++){
        arr[i-d]=arr[i];
    }
    for(int i=n-d;i<n;i++){
        arr[i]=temp[i-(n-d)];
    }
    return arr;
}
void reverseArray(vector<int> &arr,int start,int end){
      
      if(start<end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        reverseArray(arr,start+1,end-1);
      }

}
// Another Optimal solution for Left Rotate an array by D places
vector<int> leftRotateArrayByDPlacedup2(vector<int> &arr,int n){
    // Timecomplexity is O(2*n) and space complexity is O(1)         
   int d;
    cout<<"Enter the number you want to rotate to left : ";
    cin>>d;
    d=d%n;
    reverseArray(arr,0,d-1);
    reverseArray(arr,d,n-1);
    reverseArray(arr,0,n-1);
}

// Move all zeros to the end of the Array
// Brute force solution
vector<int> moveZeroToEnd(vector<int> &arr,int n){
    // Time complexity is O(2*N)
    // Space Complexity is O(N) whenn in worst case  where there is no zero in array or O(x) where is x
    // is number of non zero element
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }
    }
    for(int i=0;i<n;i++){
         if(i>=0 && i<temp.size()){
            arr[i]=temp[i];
         }
         else{
            arr[i]=0;
         }
    }
      return arr;
}

// Another Optimal Solution to Move all zeros to the end of the Array
vector<int> moveZeroToEnddup(vector<int> &arr,int n){
    // This solution send zero to end while iterating by using two pointer 
    int j=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    if(j==-1) return arr;

    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
     return arr;
}

// Linear Search 
// In this array of number is given and separate number is given we to check that separate number is 
// present in array of not (first occurenc) so we have to return index at which it first time occur else return -1
int linearSearch(vector<int> arr,int n,int num){
    for(int i=0;i<n;i++){
        if(arr[i]==num){
            return i;
        }
    }
    return -1;
}

// Union of two sorted array without duplicate
// arr1[]={1,1,2,3,4,5}  arr2[]={2,3,4,4,5,6}
// Union[]={1,2,3,4,5,6}

vector<int> Union(vector<int> arr1,vector<int> arr2,int n1,int n2){
    // Time complexity is O(n1logn+n2logn)+O(n1+n2)
    //SC O(n1+n2)
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    set<int> st;
     
     for(int i=0;i<n1;i++){
        st.insert(arr1[i]);
     }
     for(int i=0;i<n2;i++){
        st.insert(arr2[i]);
     }

     vector<int> Union;
     for(auto it : st){
        Union.push_back(it);
     }
     return Union;
}

vector<int> Uniondup(vector<int> arr1,vector<int> arr2){
    // Time complexity is O(n1+n2)
    // Space complexity isn O(n1+n2) for returning the answer and not for algorithm
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    int n1=arr1.size();
    int n2=arr2.size();

    int i=0;
    int j=0;
     vector<int> unionArr;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            if(unionArr.size()==0 || unionArr.back()!=arr1[i]){
                unionArr.push_back(arr1[i]);
                i++;
            }
        }
        else {
            if(unionArr.size()==0 || unionArr.back()!=arr2[j]){
                unionArr.push_back(arr2[j]);
                j++;
            }
        }
    }
     while(j<n2){
        if(unionArr.size()==0 || unionArr.back()!=arr2[j]){
                unionArr.push_back(arr2[j]);
                j++;
            }
    }
    while(i<n1){
         if(unionArr.size()==0 || unionArr.back()!=arr1[i]){
                unionArr.push_back(arr1[i]);
                i++;
            }
    }    
    return unionArr;
}
// Intersection of two sorted arrays Intersection means Element present in both array repetition is allowed

vector<int> intersectionOf2Arrays(vector<int> arr1,vector<int> arr2,int n1,int n2){
    // Time complexity is O(n1*n2) and Space Complexity is O(n2)
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
     vector<int> intersection;
     vector<int> visited(n2);

     for(int i=0;i<n1;i++){
        for(int j=0;i<n2;j++){
           if(arr1[i]==arr2[j] && visited[j]==0){
            intersection.push_back(arr2[j]);
            visited[j]=1;
            break;
           }
           if(arr1[i]<arr2[j]) break;
        }
     }

     return intersection;
}
// Another optimal solution for intersection
vector<int> intersectionOf2Arraysdup(vector<int> arr1,vector<int> arr2,int n1,int n2){
    // Time complexity is O(n1+n2) and space complexity is O(1)
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    vector<int> intersection;
    int i=0;int j=0;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
        i++;
        }
        else if(arr2[j]<arr1[i]){
            j++;
        }
        else{
            intersection.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return intersection;
}
int main(){
    int n;
    cout<<"Enter the size of an array : ";
    cin>>n;
    //int arr[n];
    vector<int> arr(n);
    cout<<"Enter the element of an array : \n";
    inputArray(arr,n);

   // leftRotateArrayByOnePlace(arr,n);
   // leftRotateArrayByDPlace(arr,n);
   // leftRotateArrayByDPlacedup1(arr,n);
    leftRotateArrayByDPlacedup2(arr,n);
    printArray(arr,n);
  //  moveZeroToEnd(arr,n);
    moveZeroToEnddup(arr,n);
    cout<<"\n";
    printArray(arr,n);
    cout<<"\n";
    int index=linearSearch(arr,n,3);
    cout<<index<<"\n";
    int n1,n2;
    cout<<"Enter the size of array 1 : \n";
    cin>>n1;
    cout<<"Enter the size of array 2 : \n";
    cin>>n2;
    vector<int> arr1(n1),arr2(n2);
    cout<<"Enter the element for array 1 : \n";
    inputArray(arr1,n1);
    cout<<"Enter the element for array 2 : \n";
    inputArray(arr2,n2);
    vector<int> U=Union(arr1,arr2,n1,n2);
    // vector<int> U=Uniondup(arr1,arr2);
    printArray(U,U.size());
    cout<<"\n";
   // vector<int> i=intersectionOf2Arrays(arr1,arr2,n1,n2);
   vector<int> i=intersectionOf2Arraysdup(arr1,arr2,n1,n2);
    printArray(i,i.size());
   
   return 0;
}