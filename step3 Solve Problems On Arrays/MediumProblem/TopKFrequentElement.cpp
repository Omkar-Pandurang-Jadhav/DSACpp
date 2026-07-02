/*
Question:
Given an integer array nums and an integer k, return the k most frequent
elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Example 3:
Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
Output: [1,2]

Approach:
1. Traverse the array and count the frequency of each element using a map.
2. Store each element along with its frequency in a max heap
   (priority queue), where the frequency is kept as the first value.
3. Since the priority queue always keeps the highest frequency element
   at the top, repeatedly remove the top element k times.
4. Store the corresponding numbers in the answer vector.
5. Return the final answer.

Time Complexity:
O(N log M)

where,
N = size of the input array
M = number of unique elements

Space Complexity:
O(M)
for storing the frequency map and priority queue.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Stores the frequency of each number
        map<int, int> mpp;

        int n = nums.size();

        // Count the frequency of every element
        for (int i = 0; i < n; i++) {
            mpp[nums[i]] += 1;
        }

        // Max heap storing {frequency, number}
        priority_queue<pair<int, int>> pq;

        // Insert every unique number along with its frequency
        for (auto it : mpp) {
            pq.push({it.second, it.first});
        }

        // Stores the final top k frequent elements
        vector<int> ans;

        // Extract the top k elements from the heap
        while (k != 0) {

            // Element with the highest frequency
            pair<int, int> element = pq.top();
            pq.pop();

            // Store only the number
            ans.push_back(element.second);

            k -= 1;
        }

        return ans;
    }
};