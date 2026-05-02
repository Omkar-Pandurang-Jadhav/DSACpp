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



