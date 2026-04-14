/*
QUESTION:
Given a number n, print all its divisors in sorted order.

Example:
Input: n = 36
Output: 1 2 3 4 6 9 12 18 36

-----------------------------------------------------

APPROACH (Optimized - No Sorting):

Step 1: Iterate from i = 1 to sqrt(n)
--------------------------------------
- If i divides n → i is a divisor
- Print i immediately (these are smaller divisors)

- Store (n / i) in a separate vector (these are larger divisors)

--------------------------------------

Step 2: Avoid duplicates
--------------------------------------
- If i == n/i (perfect square case)
  → Do not store again

--------------------------------------

Step 3: Print larger divisors in reverse
--------------------------------------
- The stored larger divisors are in decreasing order
- So print them in reverse to maintain sorted order

-----------------------------------------------------

WHY THIS IS OPTIMAL:
--------------------------------------
- No sorting required
- Only half divisors are stored
- Output is naturally sorted

-----------------------------------------------------

TIME COMPLEXITY:
O(√n)

→ Only one loop till sqrt(n)
→ No sorting overhead

-----------------------------------------------------

SPACE COMPLEXITY:
O(√n)

→ Stores only larger divisors (at most √n elements)

-----------------------------------------------------
*/

void print_divisors(int n) {
    vector<int> large;

    // Step 1: Find and print smaller divisors
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            cout << i << " ";

            // Store larger divisor
            if(i != n / i)
                large.push_back(n / i);
        }
    }

    // Step 3: Print larger divisors in reverse
    for(int i = large.size() - 1; i >= 0; i--){
        cout << large[i] << " ";
    }
}