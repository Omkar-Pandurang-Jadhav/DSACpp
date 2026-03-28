/*Given an integer array nums of unique elements, return all possible (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:

Input: nums = [0]
Output: [[],[0]]
*/
/*
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        // Time Complexity: O(n * 2^n)
        // Explanation:
        // For n elements, total subsets = 2^n.
        // For each element, we iterate over all existing subsets.
        // Copying a subset can take up to O(n) time.
        // So total complexity = O(n * 2^n).

        // Space Complexity: O(n * 2^n)
        // We are storing all possible subsets.
        // Total subsets = 2^n and each subset can have at most n elements.

        vector<vector<int>> a;
        
        a.push_back({});  // Start with empty subset
        
        for(int i = 0; i < nums.size(); i++){
            
            int currentSize = a.size();  // Size before adding new subsets
            
            for(int j = 0; j < currentSize; j++){
                
                vector<int> temp = a[j];   // Copy existing subset
                temp.push_back(nums[i]);   // Add current element
                a.push_back(temp);         // Store new subset
            }
        }
        
        return a;
    }
}; */

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        /*
        APPROACH: Bitmasking (Binary Representation Method)

        Idea:
        - For n elements, total subsets = 2^n.
        - Every number from 0 to (2^n - 1) represents one subset.
        - The binary representation of the number decides which elements to include.

        Example: nums = {1,2,3}

        i = 0 (000) → {}
        i = 1 (001) → {1}
        i = 2 (010) → {2}
        i = 3 (011) → {1,2}
        i = 4 (100) → {3}
        i = 5 (101) → {1,3}
        i = 6 (110) → {2,3}
        i = 7 (111) → {1,2,3}

        If j-th bit of i is set → include nums[j].
        */

        vector<vector<int>> ans;
        
        int subset = 1 << nums.size();   // 2^n total subsets
        
        for(int i = 0; i < subset; i++) {
            
            vector<int> list;
            
            for(int j = 0; j < nums.size(); j++) {
                
                // Check if j-th bit is set
                if(i & (1 << j)) {
                    list.push_back(nums[j]);
                }
            }
            
            ans.push_back(list);
        }

        /*
        Time Complexity: O(n * 2^n)
        - Outer loop runs 2^n times.
        - Inner loop runs n times.
        - Total = n * 2^n.

        Space Complexity: O(n * 2^n)
        - We store all subsets.
        - Total subsets = 2^n.
        - Each subset can have at most n elements.
        */
        
        return ans; 
    }
};