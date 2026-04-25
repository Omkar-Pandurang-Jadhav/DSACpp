/* 
Code
Testcase
Testcase
Test Result
1358. Number of Substrings Containing All Three Characters
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these 
characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1*/

/*
============================================================
NUMBER OF SUBSTRINGS CONTAINING ALL THREE CHARACTERS (a,b,c)
3 APPROACHES
============================================================

PROBLEM:
Count substrings that contain at least one 'a', 'b', and 'c'.

============================================================


------------------------------------------------------------
1️⃣ BRUTE FORCE
------------------------------------------------------------

APPROACH:
- Fix starting index i
- Expand j
- Track presence of a, b, c using booleans
- If all three found → increment count

------------------------------------------------------------

TIME COMPLEXITY:
O(n^2)

→ Outer loop: n
→ Inner loop: up to n

------------------------------------------------------------

SPACE COMPLEXITY:
O(1)

------------------------------------------------------------
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt=0;
        
        for(int i=0;i<s.size();i++){
            bool p=false;
            bool q=false;
            bool r=false;
            for(int j=i;j<s.size();j++){
                if(s[j]=='a') p=true;
                if(s[j]=='b') q=true;
                if(s[j]=='c') r=true;
                if(p && q && r) cnt++;
            }
        }
        return cnt;
    }
};



/*
------------------------------------------------------------
2️⃣ BRUTE FORCE OPTIMIZED
------------------------------------------------------------

APPROACH:
- Same as above
- Once valid substring found at j:
    → all substrings till end are valid
    → add (n - j) and break

------------------------------------------------------------

TIME COMPLEXITY:
O(n^2)

(best case faster due to early break)

------------------------------------------------------------

SPACE COMPLEXITY:
O(1)

------------------------------------------------------------
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt=0;
        
        for(int i=0;i<s.size();i++){
            bool p=false;
            bool q=false;
            bool r=false;
            for(int j=i;j<s.size();j++){
                if(s[j]=='a') p=true;
                if(s[j]=='b') q=true;
                if(s[j]=='c') r=true;
                if(p && q && r){
                    cnt+=s.size()-j;
                    break;
                }
            }
        }
        return cnt;
    }
};



/*
------------------------------------------------------------
3️⃣ OPTIMAL (LAST OCCURRENCE METHOD ⭐)
------------------------------------------------------------

APPROACH:
- Track last seen index of 'a', 'b', 'c'
- At each index r:
    → find minimum of last indices
    → all substrings ending at r and starting before that min are valid
    → add (min_index + 1)

------------------------------------------------------------

TIME COMPLEXITY:
O(n)

→ single pass

------------------------------------------------------------

SPACE COMPLEXITY:
O(3) ≈ O(1)

------------------------------------------------------------
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt=0;
        vector<int> hash(3,-1);
        int r=0;
        while(r<s.size()){
            hash[s[r]-'a']=r;
            int mini=*min_element(hash.begin(),hash.end());
            if(mini!=-1){
                cnt+=1+mini;
            }
            r+=1;
        }
        return cnt;
    }
};



/*
============================================================
DRY RUN (APPROACH 3)
STRING: "bbacba"
============================================================

Initial:
hash = [-1, -1, -1]   // [a, b, c]
cnt = 0

------------------------------------------------------------
r = 0 → 'b'
hash = [-1, 0, -1]
mini = -1 → skip

cnt = 0

------------------------------------------------------------
r = 1 → 'b'
hash = [-1, 1, -1]
mini = -1 → skip

cnt = 0

------------------------------------------------------------
r = 2 → 'a'
hash = [2, 1, -1]
mini = -1 → skip

cnt = 0

------------------------------------------------------------
r = 3 → 'c'
hash = [2, 1, 3]

mini = min(2,1,3) = 1

cnt += 1 + 1 = 2

Valid substrings ending at r=3:
"bac", "bbac"

------------------------------------------------------------
r = 4 → 'b'
hash = [2, 4, 3]

mini = min(2,4,3) = 2

cnt += 1 + 2 = 3

Valid substrings:
"acb", "bacb", "bbacb"

cnt = 5

------------------------------------------------------------
r = 5 → 'a'
hash = [5, 4, 3]

mini = min(5,4,3) = 3

cnt += 1 + 3 = 4

Valid substrings:
"cba", "acba", "bacba", "bbacba"

cnt = 9

------------------------------------------------------------
FINAL ANSWER = 9
============================================================
*/