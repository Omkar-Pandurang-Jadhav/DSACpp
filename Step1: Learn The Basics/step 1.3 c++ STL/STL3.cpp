# include<bits\stdc++.h>
using namespace std;

void explainMap(){
  // Map is a container which stores everything with respect to keys and value
  // in Map everything happens in logarithimic time complexity Log(n)
  //  key   value
  map<int , int> mpp;
 // map<int,pair<int,int>> mpp;
 // map< pair<int,int> ,int>mpp;
  mpp[1]=2; // key is 1 and value is 2
  mpp.emplace(3,1);// key is 3 and value is 1
  mpp.insert({2,4});// key is 2 and value is 4
  // mpp={{1,2},{2,4},{3,1}}
  //mpp[2,3]=10;// key is 2,3 and value is 10
  // Map stores unique keys in sorted order
  /*
  {
     {1,2}
     {2,4}
     {3,1}
   }
   */
  for(auto it : mpp){
    cout<<it.first<<" "<<it.second<<endl;
  }

  cout<<mpp[1];
  cout<<" ";
  cout<<mpp[5]; // prints 0
  cout<<"\n";

   map<int,int>:: iterator it =mpp.find(3);
  cout << mpp[3]<<" "<< it->second; // print 1
   auto it1 =mpp.find(5);// point to mpp.end()
   cout<<"\n";
   cout<< it1->second;
  
  // This is syntax
  auto it=mpp.lower_bound(2);
  auto it =mpp.upper_bound(3);

  // erase,swap,size,empty, are same as above

}
void explainMultiMap(){
  // everything same as map, only it can store multiple keys
  //only map[key] cannot be used here
  // can store duplicate keys
}

void explainUnorderedMap(){
  // take constant time of O(1)
  // same as set and unordered_set difference.
  // unique keys
}

int main(){
   
   explainMap();

    return 0;
}
