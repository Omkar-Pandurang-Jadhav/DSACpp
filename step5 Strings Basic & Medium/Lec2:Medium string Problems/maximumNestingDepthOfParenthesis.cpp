class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;  // Stores the maximum depth of parentheses found so far
        int cnt = 0;   // Keeps track of current depth while scanning

        // Traverse the string character by character
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') 
                cnt++;  // Opening bracket → increase current depth
            else if (s[i] == ')') 
                cnt--;  // Closing bracket → decrease current depth

            // Update maximum depth whenever we reach a deeper level
            maxi = max(maxi, cnt);
        }

        return maxi;  // Return the maximum depth encountered
    }
};
