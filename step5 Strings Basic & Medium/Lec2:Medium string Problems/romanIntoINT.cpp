class Solution {
public:
    int romanToInt(string s) {
        /*
        Problem:
        --------
        Convert a Roman numeral string `s` into an integer.

        Rules:
        - Roman numerals are usually written largest to smallest from left to right.
        - However, if a smaller value comes before a larger one, it is subtracted.
          Example: IV = 4, IX = 9, XL = 40, etc.

        Approach:
        ---------
        1. Create a mapping of Roman symbols → integer values.
           I=1, V=5, X=10, L=50, C=100, D=500, M=1000
        2. Traverse the string from left to right:
           - If current symbol < next symbol → subtract (next - current) and skip the next one.
           - Else, just add the current symbol value.
        3. At the end, add the last symbol if not already processed.
        4. Return the total.

        Example:
        --------
        s = "MCMIV"
        M=1000
        C < M → 900
        I < V → 4
        Total = 1000 + 900 + 4 = 1904

        Time Complexity: O(n)
            - We scan the string once.
        Space Complexity: O(1)
            - Map stores fixed 7 entries, constant space.
        */

        map<char,int> mpp;
        int n = s.size();

        // Step 1: Roman numeral mapping
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;

        if(n == 1) return mpp[s[0]];  // single character case

        int ans = 0;

        // Step 2: Traverse the string
        for(int i=0; i<s.size()-1; i++){
            if(mpp[s[i]] < mpp[s[i+1]]) {
                // Case: subtractive notation (like IV, IX, XL, etc.)
                ans += mpp[s[i+1]] - mpp[s[i]];
                i++; // skip next character as it's already processed
            }
            else {
                ans += mpp[s[i]];
            }

            // Step 3: Add last character if at second last index
            if(i == n-2) ans += mpp[s[n-1]];
        }

        return ans;
    }
};
