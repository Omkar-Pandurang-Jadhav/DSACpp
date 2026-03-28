# include<bits\stdc++.h>
using namespace std;

// For C++ STL there are 4 Topics
// 1) Algorithms
//2)Containers
//3)Functions
//4)Iterators

//For understanding Containers we need to learn about Pair
void explainPair(){
    pair<int ,int >p1={1,3};
    cout<<p1.first<<" "<< p1.second<<"\n";
    pair<int,pair<int,int>> p2={1,{3,4}};
    cout<< p2.first<<" "<< p2.second.second<<" "<< p2.second.first<<"\n";
    pair<int ,int > arr[]={{1,2},{2,5},{5,1}};
    cout<<arr[1].second<<"\n";
}
// First Container
void explainVector(){
    // Create an empty container and we can modify the size dynamically where array cannot
   // vector<int> v; // -> {}
     
  //  v.push_back(1); // it add 1 in empty container {}->{1}
    // it add 2 similarly like push_back but it is faster than push_back
  //  v.emplace_back(2);// {1}->{1,2}

 //   vector<pair<int,int>> vec;  
  //  vec.push_back({1,2}); // There is difference between the syntax of push_back and emplace_back 
  //  vec.emplace_back(1,2);   //for storing pair in container
    
 
  //  vector<int> v(5,100); // Create container of size of 5 with 5 instance of 100 containg 100 {100,100,100,100,100}

    
    vector<int> v1(5,20);//{20,20,20,20,20}

    vector<int> v2(v1);  // copying vector v1 into v2 {20,20,20,20,20}

    vector<int> v(5);//Create containerof size of 5 with 5 instances of 0 or any garbage value.
    // we can also increase the size of vector using push_back function adding 1
      // v={20,10,15,6,7};
      cout<<"Enter the element for vector \n";
      for(int i=0;i<v.size();i++){
        cin>>v[i];
      }
    // Accessing an vector one way is iterator and another way is simply v[n] where n is index
    // Iterator
     // iterator basically means points to the memory address of vector container
     // to the next memory
     //so iterator is accessing memory so when we print it it print the memory address so to access the element we
    // write * before it like *(it)
    vector<int>::iterator it = v.begin(); //syntax // it points directly to the memory of 20
   // Example {20,10,15,6,7}
    it++; //  point to the memory of 10
    cout<< *(it)<<" ";// print 10
    it=it+2;// point to the memory of 
    cout<< *(it)<<" ";// print 6
   // vector<int>:: iterator it=v.end(); //end will point to the memory location next to element 7
 //   vector<int>:: iterator it=v.rend();  //rend will point to the memory location before to element 20
 //   vector<int>:: iterator it=v.rbegin(); //rbegin will point to the memory location of element 7 and if
 // we do it++ here than it we will point to 6 basically it works in reverse manner
     
     cout<<v[0]<<" "<<v.at(0)<<" ";
     cout<<v.back()<<" ";

     // Ways to print vector 
     // Easy way
     cout<<"\n";
     for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
     }
     cout<<"\n";
     // Second way using iterator
     for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*(it)<<" ";
     }
      cout<<"\n";
     // Shortcut of second way 
     for(auto it=v.begin();it!=v.end();it++){
        cout<<*(it)<<" ";
     }
      cout<<"\n";
     //for each loop
     for(auto it:v){
        cout<<it<<" ";
     }
      cout<<"\n";

     // consider vector container {10,20,12,23}
     // to remove an element we erase() function
     cout<<"\n";
     vector<int> v3={10,20,12,23};
     //v3.push_back({10,20,12,23});
     for(int i=0;i<v3.size();i++){
        cout<<v3[i]<<" ";
     }
     cout<<"\n";
    v3.erase(v3.begin()+1); // element 20 will be removed {10,12,23}
    for(int i=0;i<v3.size();i++){
        cout<<v3[i]<<" ";
     }
     cout<<"\n";
    v3={10,20,12,23,35};
    for(int i=0;i<v3.size();i++){
        cout<<v3[i]<<" ";
     }
     cout<<"\n";
    v3.erase(v3.begin()+2,v3.begin()+4);//if we have to remove two element so we have to address of first element and 
    // adress of next to second element like end v3.erase(start,end);  {10,20,35}
    for(int i=0;i<v3.size();i++){
        cout<<v3[i]<<" ";
     }
     cout<<"\n";

    // similarly we can use insert function to add
    vector<int>v4(2,100); //{100,100}
    cout<<"\n";
    for(int i=0;i<v4.size();i++){
        cout<<v4[i]<<" ";
     }
     cout<<"\n";
    v4.insert(v4.begin(),300);// {300,100,100}
    for(int i=0;i<v4.size();i++){
        cout<<v4[i]<<" ";
     }
     cout<<"\n";
    v4.insert(v4.begin()+1,3,10);//{300,10,10,10,100,100} // this will insert two 10s at position 1
    for(int i=0;i<v4.size();i++){
        cout<<v4[i]<<" ";
     }
     cout<<"\n";

    vector<int>copy(2,50);//{50,50}
    v4.insert(v4.begin(),copy.begin(),copy.end());//{50,50,300,10,10,100,100}
    for(int i=0;i<v4.size();i++){
        cout<<v4[i]<<" ";
     }
     cout<<"\n";
       
    // v={10,20}  
    // cout<<v.size(); //2

    // v={10,20}
    //v.pop_back(); //{10}

    //v1={10,20} v2={30,40}
    //v1.swap(); //v1->{20,10} v2->{40,30}
    v4.clear(); // erases entire vector
    cout<<v4.empty();


}

int main(){
    cout<<"ExplainPair \n";
    explainPair();
    cout<<"ExplainVecto \n";
    explainVector();

    return 0;
}     