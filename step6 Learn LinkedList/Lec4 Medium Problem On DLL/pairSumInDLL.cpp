/*
Given a sorted doubly linked list of positive distinct elements, the task is to find 
pairs in a doubly-linked list whose sum is equal to given value target.

 

Example 1:

Input:  
1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
target = 7
Output: (1, 6), (2,5)
Explanation: We can see that there are two pairs 
(1, 6) and (2,5) with sum 7.
*/

/*
============================================================
FIND PAIRS WITH GIVEN SUM IN DOUBLY LINKED LIST
============================================================

APPROACH:
- Traverse the DLL from head
- Use a map to store frequency of visited values
- For each node:
    → Compute required value = target - current node data
    → If required value exists in map → add pair
- Insert current value into map
- Sort result at the end

------------------------------------------------------------

TIME COMPLEXITY:
O(n log n)

→ Traversal: O(n)
→ Map operations: O(log n)
→ Sorting result: O(k log k), k = number of pairs

------------------------------------------------------------

SPACE COMPLEXITY:
O(n)

→ Map stores visited elements
→ Result vector stores pairs

============================================================
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        if(head==NULL) return {};

        map<int,int> mpp;
        Node *temp=head;
        vector<pair<int,int>> ans;

        while(temp!=NULL){
            int preSum = target - temp->data;

            if(mpp.find(preSum)!=mpp.end()){
                ans.push_back({preSum,temp->data});
            }

            mpp[temp->data]+=1;
            temp=temp->next;
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};