/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be
 separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two 
words. The returned string should only have a single space separating the words. 
Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.*/

/*
============================================================
REVERSE WORDS IN A STRING
============================================================

PROBLEM:
- Given a string s
- Reverse the order of words
- Remove extra spaces

============================================================


------------------------------------------------------------
1️⃣ YOUR APPROACH (VECTOR + REVERSE)
------------------------------------------------------------

APPROACH:
- Traverse string and extract words into vector
- Ignore multiple spaces
- Reverse the vector
- Join words with single space

------------------------------------------------------------

TIME COMPLEXITY:
O(n)

→ Traverse string once → O(n)
→ Reverse vector → O(n)
→ Build result → O(n)

Total ≈ O(3n) ≈ O(n)

------------------------------------------------------------

SPACE COMPLEXITY:
O(n)

→ Vector stores words
→ Output string also O(n)

------------------------------------------------------------
*/

class Solution {
public:
    string reverseWords(string s) {
        vector<string> a;
        string temp="";

        for(int i=0;i<s.size();i++){
            if(s[i]==' ') {
                if(temp!="") a.push_back(temp);
                temp="";
                continue;
            }
            else temp+=s[i];
        }

        if(temp!="") a.push_back(temp);

        reverse(a.begin(),a.end());

        string ans="";
        for(int i=0;i<a.size();i++){
            ans+=a[i];
            if(i!=a.size()-1) ans+=" ";
        }

        return ans;
    }
};



/*
============================================================
REVERSE WORDS IN A STRING (SCAN FROM BACK)
============================================================

PROBLEM:
- Reverse the order of words in a string
- Remove extra spaces (leading, trailing, multiple)

============================================================


------------------------------------------------------------
1️⃣ YOUR APPROACH (RIGHT → LEFT SCAN)
------------------------------------------------------------

APPROACH:
- Traverse string from end
- Build current word in `temp`
- When space encountered:
    → append word to result (if non-empty)
- Append last word
- Trim trailing space at the end

------------------------------------------------------------

TIME COMPLEXITY:
O(n)

→ Single pass from right to left → O(n)
→ Building strings (amortized) → O(n)

Total ≈ O(n)

------------------------------------------------------------

SPACE COMPLEXITY:
O(n)

→ `result` stores final string
→ `temp` stores current word (≤ word length)

------------------------------------------------------------

NOTE:
- Avoids extra vector
- Handles multiple spaces correctly
- Still uses extra string → not in-place

------------------------------------------------------------
*/

class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string result="";
        string temp="";

        for(int i=n-1;i>=0;i--){
            if(s[i]==' '){
                if(temp!=""){
                    result+=temp;
                    result+=" ";
                }
                temp="";
                continue;
            }
            else temp=s[i]+temp;
        }

        if(temp!=""){
            result+=temp;
        }

        int i=result.size()-1;
        while(i>=0 && result[i]==' ') i-=1;

        return result.substr(0,i+1);
    }
};



/*
============================================================
IS THIS BETTER THAN VECTOR APPROACH?
============================================================

✔ Time: SAME → O(n)
✔ Space: SAME → O(n)

------------------------------------------------------------

Comparison:

| Approach          | Time | Space | Note |
|------------------|------|-------|------|
| Vector           | O(n) | O(n)  | stores all words |
| Your approach    | O(n) | O(n)  | avoids vector but still uses string |

👉 No asymptotic improvement in space

------------------------------------------------------------

⚠️ Hidden inefficiency:

This line:
    temp = s[i] + temp;

👉 causes:
    O(k) shift each time (string prepend)

Worst case:
    O(n²) behavior (many characters)

------------------------------------------------------------

So practically:
👉 This can be slower than vector approach

------------------------------------------------------------

============================================================
2️⃣ BEST SPACE OPTIMIZATION (IN-PLACE)
============================================================

IDEA:
- Remove extra spaces
- Reverse entire string
- Reverse each word

TIME:
O(n)

SPACE:
O(1) ⭐

------------------------------------------------------------
*/

class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0, n = s.size();

        // remove extra spaces
        while(j < n){
            while(j < n && s[j] == ' ') j++;
            while(j < n && s[j] != ' ') s[i++] = s[j++];
            while(j < n && s[j] == ' ') j++;
            if(j < n) s[i++] = ' ';
        }

        s.resize(i);

        // reverse whole string
        reverse(s.begin(), s.end());

        // reverse each word
        int start = 0;
        for(int end = 0; end <= s.size(); end++){
            if(end == s.size() || s[end] == ' '){
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }

        return s;
    }
};



/*
============================================================
FINAL TAKEAWAY
============================================================

👉 Your approach:
- Cleaner than vector
- Same space complexity O(n)
- Slightly worse constant due to string prepend

👉 Best approach:
- In-place reversal → O(1) space

============================================================
*/