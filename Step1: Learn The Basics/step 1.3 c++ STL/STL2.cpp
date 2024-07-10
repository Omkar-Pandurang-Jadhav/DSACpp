# include<bits\stdc++.h>
using namespace std;

void explainList(){
    // it is mostly similar to vecto buthe only thing is its gives you front operation as well
    list<int> ls;
    ls.push_back(2); //{2}
    ls.emplace_back(4);//{2,4}

    ls.push_front(5);//{5,2,4}
    ls.emplace_front();//{2,4}

    // rest functions same as vector
    // begin,end,rbegin,rend,clear,insert,size,swap
}
void explainDeque(){  
   deque<int> dq;
   dq.push_back(1);//{1}
   dq.emplace_back(2); // {1,2}
   dq.push_front(4); //{4,1,2}
   dq.emplace_front(3); //{3,4,1,2}

   dq.pop_back();//{3,4,1}
   dq.pop_front(); // {4,1}

   dq.back();
   dq.front();
   //rest functions are same as vector
   // begin,end,rbegin,rend,clear,insert,size,swap
}
void explainStack(){
    // in stack index element is not allowed
    // Majorly there are three functions only like push,pop,top
    // All operation are happening in constant time in O(1)
    stack<int> st; // LIFO Last in first out
    st.push(1);//{1}
    st.push(2);//{2,1}
    st.push(3);//{3,2,1}
    st.push(4);//{3,3,2,1}
    st.emplace(5);//{5,3,3,2,1} // similar to push

     cout<<st.top(); // prints 5 "** st[2] is invalid **"

     st.pop();// st looks like {3,3,2,1}

     cout<< st.top(); // Prints 3
     cout<<st.size();// 4

     cout<<st.empty();

     stack<int> st1,st2;
     st1.swap(st2);


}
void explainQueue(){
    // it is simply first in first out FIFO
    // All operation are happening in constant time in O(1)
    queue<int> q;
     q.push(1);//{1}
     q.push(2);//{1,2}
     q.emplace(4);//{1,2,4}
     q.back()+=5;

     cout<<q.back(); // Prints 9

     //q is {1,2,9}
     cout<<q.front();  // Prints 1
     q.pop(); // {2,9}

     cout<<q.front(); // Print 2

     //size swap empty same as swap

}
void explainPQ(){
    
    priority_queue<int> pq; // known as max heap
    // Int with largest value stays at the top
    pq.push(5); //{5}
    pq.push(2); //{5,2}
    pq.push(8); //{8,5,2}
    pq.emplace(10); //{10,8,5,2}

    cout<<pq.top(); // prints 10
    pq.pop(); // {8,5,2}
    
    // size swap empty function same as others
    
    // Minimum Heap
    priority_queue<int,vector<int>,greater<int>> pq; // known as min heap// Keep minimum element at top
    pq.push(2);//{2}
    pq.push(5);//{2,5}
    pq.push(8); //{2,5,8}
    pq.emplace(10); //{2,5,8,10}

    cout<<pq.top(); // prints 2 

    // Time complexcity of push and pop is logn and that of top is O(1)

}
void explainSet(){ 
    // set-> sorted ands unique
    // In set everythings happen in logarithamic time complexity Log(n)
    set<int>st;
    st.insert(1); // {1}
    st.emplace(2); // {1,2}
    st.insert(2); // {1,2} // It cannot store same element twice
    st.insert(4); //{1,2,4}
    st.insert(3); // {1,2,3,4}
    // Functionality of insert can be use in vector also that only increases efficiency

    // begin(),end(),rbegin(),rend();size();
    // empty() and swap() are same as those above

    //{1,2,3,4,5}
    auto it =st.find(3); // returns an iterator which points to the 3
    
    // {1,2,3,4,5}
    auto it =st.find(6); // returns an iterator which points to the st.end() points after 5

    //{1,4,5}
    st.erase(5); // erases 5 // take logarithimic time

    int cnt=st.count(1);

    auto it=st.find(3);
    st.erase(it); // It will take constant time

    //{1,2,3,4,5}
    auto it1=st.find(2);
    auto it2=st.find(4);
    st.erase(it1,it2); //after erase {1,4,5} [first,last)

    // lower_bound() and upper_bound() work in the same way as it does in the vector

    // This is the systax
    auto it=st.lower_bound(2);
    auto it=st.upper_bound(3);
}
void explainMultiSet(){
    // Everything is same as set only obeys sorted
    // only stores duplicate element also

    multiset<int> ms;
    ms.insert(1); //{1}
    ms.insert(1); //{1,1}
    ms.insert(1); //{1,1,1}

    ms.erase(1);// all 1's are erased

    int cnt = ms.count(1);

    //only one 1 is erased
    ms.erase(ms.find(1));

   // ms.erase(ms.find(1),ms.find(1)+1);               

    // rest all functions are same

}
void explainUnorderedSet(){
    unordered_set<int> us; // it stores unique 
    // in most of the cases time complexity in constant O(1)
    //lower_bound() and upper_bound() function does not work ,rest all functions are same as above,
    // it does not stores in any particular order it has better complexity than set in most of the cases,
    // except some when collision happens.
}
int main(){


    return 0;
}
