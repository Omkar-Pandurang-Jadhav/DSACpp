/*
Question:
You are given an array of non-negative integers nums and an integer k.

In one operation, you may choose any element of nums and increment it by 1.

Return the maximum possible product of all elements after performing
at most k operations.

Since the answer can be very large, return it modulo 10^9 + 7.

Note:
The product should be maximized first, and only then should the modulo
operation be applied.

Example 1:
Input: nums = [0,4], k = 5
Output: 20

Example 2:
Input: nums = [6,3,3,2], k = 2
Output: 216

Approach:
1. To maximize the final product, always increment the smallest
   element in the array.
2. Store all elements in a min heap so that the minimum element
   can be accessed efficiently.
3. Repeat the following process exactly k times:
   - Remove the smallest element.
   - Increment it by 1.
   - Insert it back into the min heap.
4. After all operations are completed, multiply every element of
   the heap.
5. Take modulo (10^9 + 7) while multiplying to avoid overflow.
6. Return the final product.

Mathematical Proof:
Assume there are two numbers x and y such that

x > y

Suppose only one increment operation is available.

Case 1:
Increment the larger element x.

Product obtained:

(x + 1) × y
= xy + y

Case 2:
Increment the smaller element y.

Product obtained:

x × (y + 1)
= xy + x

Now compare both products.

x(y + 1) - (x + 1)y
= xy + x - xy - y
= x - y

Since

x > y

we have

x - y > 0

Therefore,

x(y + 1) > (x + 1)y

Hence, incrementing the smaller element always produces a larger
product than incrementing the larger element.

Since this argument holds for every operation independently,
repeating this greedy choice (always incrementing the current
smallest element) guarantees the maximum possible product.

Time Complexity:
O((N + K) log N)

where,
N = size of nums

Building the heap takes O(N), and each of the K increment operations
takes O(log N).

Space Complexity:
O(N)

for storing the min heap.
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {

        // Min heap storing all elements
        priority_queue<int, vector<int>, greater<int>> pq;

        // Insert every element into the min heap
        for (auto it : nums) {
            pq.push(it);
        }

        // Perform exactly k increment operations
        for (int i = 0; i < k; i++) {

            // Remove the smallest element
            long long temp = pq.top();
            pq.pop();

            // Increment it by one
            temp += 1;

            // Insert the updated value back into the heap
            pq.push(temp);
        }

        // Modulo value
        long long mod = 1e9 + 7;

        // Stores the final product
        long long ans = 1;

        // Compute the product of all elements
        while (!pq.empty()) {

            ans = ((ans % mod) * (pq.top() % mod)) % mod;

            pq.pop();
        }

        return ans;
    }
};