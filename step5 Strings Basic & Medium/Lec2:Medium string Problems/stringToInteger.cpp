/*
mplement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+',
 assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character
 is encountered or the end of the string is reached. If no digits were read, then the
  result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1],
 then round the integer to remain in the range. Specifically, integers less than -231
  should be rounded to -231, and integers greater than 231 - 1 should be rounded 
  to 231 - 1.
Return the integer as the final result.

 

Example 1:

Input: s = "42"

Output: 42

Explanation:

The underlined characters are what is read in and the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
Example 2:

Input: s = " -042"

Output: -42

Explanation:

Step 1: "   -042" (leading whitespace is read and ignored)
            ^
Step 2: "   -042" ('-' is read, so the result should be negative)
             ^
Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
               ^
Example 3:

Input: s = "1337c0d3"

Output: 1337

Explanation:

Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
         ^
Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
             ^
Example 4:

Input: s = "0-1"

Output: 0

Explanation:

Step 1: "0-1" (no characters read because there is no leading whitespace)
         ^
Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "0-1" ("0" is read in; reading stops because the next character is a non-digit)
          ^
Example 5:

Input: s = "words and 987"

Output: 0

Explanation:

Reading stops at the first non-digit character 'w'.

 

Constraints:

0 <= s.length <= 200
s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
 
*/


/*
============================================================
STRING TO INTEGER (ATOI) - YOUR APPROACH
============================================================

APPROACH:
- Traverse the string from left to right
- Skip leading spaces
- Detect sign ('+' or '-')
- Parse digits and build number
- Stop when invalid character appears
- Handle overflow before multiplying
- Apply sign at the end

------------------------------------------------------------

TIME COMPLEXITY:
O(n)

→ Single traversal of string

------------------------------------------------------------

SPACE COMPLEXITY:
O(1)

→ Only constant extra variables used

------------------------------------------------------------

NOTE:
- Uses flag to ensure parsing starts only once
- Stops parsing once invalid sequence appears
- Overflow handled before updating ans

============================================================
*/

long long ans=0;
int sign=1;
int n=s.size();
bool flag=false;
int index=-1;

for(int i=0;i<n;i++){
    if(s[i]=='-') {
        
        if(flag==true) break;
        sign=-1;
        flag=true;
       // break;
    }
    else if(s[i]=='+'){
        if(flag==true) break;
        flag=true;
        continue;
    }
    else if(s[i]-'0' >=0 && s[i]-'0'<=9){
        if(ans>(INT_MAX-s[i]+'0')/10){
            if(sign==1) return INT_MAX;
            if(sign==-1) return INT_MIN;
        }
        ans=ans*10+s[i]-'0';
        flag=true;
    }
    else if(s[i]==' '){
        if(flag==true) break;
        //flag=true;
        continue;
    }
    else break;
}

ans=ans*sign;
return ans;