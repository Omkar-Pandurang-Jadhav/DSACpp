/*
Problem statement
There are ‘n’ fruit trees that are planted along a road. The trees are numbered from 0 to n-1. The type of fruit each tree bears is represented by an integer from 1 to 'n'.



A Ninja is walking along that road. He has two baskets and wants to put the maximum number of fruits in them. The restriction is that each basket can have only one type of fruit.



Ninja can start with any tree and end at any tree, but once he has started, he cannot skip a tree i.e if he picks fruit from the tree ‘i’, then he has to pick fruit from tree ‘i+1’ before going to the tree ‘i+2’. He will pick one fruit from each tree until he cannot, i.e, he will stop when he has to pick a fruit of the third type because only two different fruits can fill both baskets.



You are given an array ‘arr’. The ‘i’th integer in this array represents the type of fruit tree ‘i’ bears. Return the maximum number of fruits Ninja can put in both baskets after satisfying all the conditions.



For Example:
 'arr' = [1, 2, 3]

 Here, we have three different types of fruits. We can pick [1, 2] or [2, 3]. We can pick a maximum of two fruits.

Hence, we return 2.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
4
1 1 2 3
Sample Output 1:
3 
Explanation of Sample Input 1:
There are four trees and the type of fruits in them are 1, 1, 2, 3 respectively.

One way is that Ninja can start picking fruits from tree 0. He picks one 
fruit from tree 0 and put it in the first basket, then he picks one fruit 
from tree 1 and put it in the first basket, then he picks one fruit from tree 
2 and put it in the second basket, he cannot pick fruit from tree 3 because the 
first basket has the fruit of type 1 and second has the fruit of type 2 and type of 
fruit in tree-3 is 3. 

Thus he has to stop there. The number of fruits he picks in this way is 3. We can 
show that this is the maximum possible number of fruits ninjas can pick.
Sample Input 2:
4
1 2 3 4
Sample Output 2:
2
Explanation of Sample Input 2:
There are four trees, and each of them has different types of fruit. No matter 
from which tree Ninja starts picking fruits he can only collect 2 fruits.
Constraints:
1 <= n <= 10^4
1 <= arr[I] <= n
Where ‘n’ represents the number of trees.


Time limit: 1 sec*/


/*
============================================================
FRUIT INTO BASKETS (4 APPROACHES)
============================================================

PROBLEM:
Find the length of the longest subarray containing at most 2 distinct elements.

============================================================


------------------------------------------------------------
1 BRUTE FORCE (Set + Nested Loops)
------------------------------------------------------------

APPROACH:
- Fix starting index i
- Extend subarray using j
- Use set to track distinct fruits
- If size ≤ 2 → update maxlen
- Else break

------------------------------------------------------------

TIME COMPLEXITY:
O(n^2 * log2)

→ Outer loop: n
→ Inner loop: up to n
→ Each insertion in set: O(log2) ≈ constant

------------------------------------------------------------

SPACE COMPLEXITY:
O(2)

→ At most 2 elements in set

------------------------------------------------------------
*/

int findMaxFruits(vector<int> &arr, int n) {
    if(arr.size()==0 || arr.size()==1) return arr.size();
    int maxlen=0;

    for(int i=0;i<arr.size();i++){
        set<int> st;
        for(int j=i;j<arr.size();j++){
            st.insert(arr[j]);
            if(st.size()<=2){
                maxlen=max(maxlen,j-i+1);
            }
            else break;
        }
    }
    return maxlen;
}





/*
------------------------------------------------------------
2 SLIDING WINDOW (CORRECT - STRICT WHILE)
------------------------------------------------------------

APPROACH:
- Expand window using r
- Count frequencies using map
- If distinct > 2:
    → shrink using while until valid

------------------------------------------------------------

TIME COMPLEXITY:
O(n * log2)

→ r moves n times
→ l moves at most n times
→ map operations: log2 ≈ constant

Total ≈ O(2n * log2)

------------------------------------------------------------

SPACE COMPLEXITY:
O(3) ≈ O(1)

→ At most 3 keys in map temporarily

------------------------------------------------------------
*/

int findMaxFruits(vector<int> &arr, int n) {
    if(arr.size()==0 || arr.size()==1) return arr.size();

    int maxlen=0;
    int r=0, l=0;
    map<int,int> mpp;

    while(r<arr.size()){

        mpp[arr[r]]++;

        while(mpp.size()>2){
            mpp[arr[l]]--;
            if(mpp[arr[l]]==0) mpp.erase(arr[l]);
            l++;
        }

        maxlen=max(maxlen,r-l+1);

        r++;
    }

    return maxlen;
}



/*
------------------------------------------------------------
3 SLIDING WINDOW (RELAXED IF VERSION)
------------------------------------------------------------

APPROACH:
- Expand window using r
- Shrink only once using IF (not while)
- Window may be temporarily invalid

------------------------------------------------------------

TIME COMPLEXITY:
O(n * log2)

→ r moves n times
→ l moves at most n times
→ map operations log2 ≈ constant

Total ≈ O(2n * log2)

------------------------------------------------------------

SPACE COMPLEXITY:
O(3) ≈ O(1)

------------------------------------------------------------

NOTE:
- Works for this problem
- Not general sliding window pattern

------------------------------------------------------------
*/

int findMaxFruits(vector<int> &arr, int n) {
    if(arr.size()==0 || arr.size()==1) return arr.size();

    int maxlen=0;
    int r=0, l=0;
    map<int,int> mpp;

    while(r<arr.size()){

        mpp[arr[r]]++;

        if(mpp.size()>2){
            mpp[arr[l]]--;
            if(mpp[arr[l]]==0) mpp.erase(arr[l]);
            l++;
        }

        if(mpp.size()<=2)
            maxlen=max(maxlen,r-l+1);

        r++;
    }

    return maxlen;
}



/*
============================================================
FINAL COMPARISON
============================================================

| Approach | Time Complexity        | Space |
|----------|----------------------|-------|
| Brute    | O(n^2 * log2) ❌     | O(1)  |
| Strict SW| O(2n * log2) ⭐      | O(1)  |
| Relaxed SW| O(2n * log2) ⭐     | O(1)  |

============================================================
*/