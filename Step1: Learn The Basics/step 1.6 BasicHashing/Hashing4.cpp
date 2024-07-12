# include<bits\stdc++.h>
using namespace std;

// We cannot store 10^ 8 ,9 or 10 in array so to solve this STL comes in to solve this.Map is used
// map<int,int> -> map<key,value> key is number and value is frequency
//consider example {1,2,3,1,3,2,12} if we find frequency using Hash array it would ended up making array of size 13
//  to make till index 12 but in Map it takes less memory because it just store the element as key;
int main(){
    // in storing and fetching of map it takes time complexity log(n) in all cases
    // when we use the unordered map it gives same output but the order of keys is not sorted it is in unsorted 
    // manner
    int n;
    cout<<"Enter the size of an array - ";                      
    cin>>n;
    int arr[n];
    
    cout<<"Enter the element of an array - \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // Pre compute
    // In map any data stucture can be a key like pair<int,int> ,string ,double ,long 
    // But in unordered map key are only limited to long,double int and not data structure
    // If its string we can declare map<char,int> where char is key and int is value or frequency of character 
    // appear in string.
    //map<int,int> mpp;
    // Average and best  time complexity of unordered map is constant O(1) but in worst case it Takes linear time
    // which is O(N) for storing and fetching where N is number of element in the map.
    // Worst case in unordered map happens due to internal collision
    // 
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        //O(N) for worst case unordered map and O(1) for best and average case of unordered map
        // and O(log(N)) for simple map
        mpp[arr[i]]++;
    }
    cout<<"\n";
    // Iterate in the map
    for(auto it : mpp){
      cout<< it.first<<"->"<<it.second<<" ";
    }
    cout<<"\n";
    int q;
    cout<<"Enter the number of queries u want frequency of - ";
    cin>>q;
    while(q--){
        int number;
        cout<<"Enter the number you want frequency of : ";
        cin>>number;
        // fetch
        cout<<mpp[number]<<"\n";
    }

    return 0;
}
/*
 Hasing using Division Method
{2,16,23,28,139}
 In normal Hasharray method one can make an array of size 140 to reach till 139 and store the 0 and increment it
 But the condition we have to use the array of size only 10
 Then division method comes in we divide each element by 10 and based on there remainder we store it
 from above example rem 139 is 9 so we store it at index 9 similarly 16 at 6,23 art 3 and 2 at 2
   0 1 2  3 4 5  6 7 8  9
  [ , ,2,23, , ,16, , ,139 ]
 Now consider a new example {2,18,16,25,23,28,38,48,28,98}
 here remainder with index 8 is repeated in this case we do chaning of element with same remainder to the index of 
 remainder
index   keys
   0
   1   
   2    2
   3    23
   4
   5    25
   6    16
   7
   8    18->28->28->38->48->98  here chaining is done in sorted way
   9

   By this chaining we can save lot of time we can access element quickly and element with same rem is all save 
   at same Hash memory

   Now consider new example 
   {8,18,28,38, ,    ,, 1008}
   Remainder of all element is same so all element endup chaining at same Hash Memory
   index  keys
   0
   1
   2
   3
   4
   5
   6
   7
   8      8->18->18->28->38     ->1008
   9
   The above condition is called collision condion where all element is store at same memory location
   and this condition is the worst case scenario when time complexity can be linear in unordered_map with O(N)
   this is a very rare case.
*/