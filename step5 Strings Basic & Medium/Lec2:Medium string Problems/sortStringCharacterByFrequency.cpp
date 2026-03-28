
/*
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the
 number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/


// Brute Force
class Solution {
public:
    int freqq(string s, char ch) {
        // Helper function to count frequency of a given character `ch` in string `s`
        int cnt = 0;
        for(int i=0; i<s.size(); i++){
            if(ch == s[i]) cnt++;
        }
        return cnt;
    }

    string frequencySort(string s) {
        /*
        Problem:
        --------
        Given a string `s`, sort it in decreasing order based on the frequency 
        of characters.

        Approach:
        ---------
        1. For each character in `s`, compute its frequency using `freqq()` helper.
        2. Store pairs {frequency, character} in a vector.
        3. Sort the vector by frequency (default ascending).
        4. Traverse vector from end → beginning to build result string 
           (characters with highest frequency first).
        5. Append only one instance of each character (⚠️ bug in this code: 
           it appends characters only once, not multiple times as required).

        Example:
        --------
        s = "tree"
        Frequencies: t→1, r→1, e→2
        Sorted by freq: {1,t}, {1,r}, {2,e}
        Result = "ert" (but should be "eetr" → so current code is incorrect)

        Time Complexity: O(n^2 log n)
            - freqq(s,s[i]) is O(n) for each character → O(n^2).
            - Sorting vector of size n → O(n log n).
            - Overall: O(n^2 + n log n) ≈ O(n^2).
        Space Complexity: O(n)
            - Vector of size n to store frequency-character pairs.

        ⚠️ Note: This code is not optimal and also incorrect for problems 
        like LeetCode 451 (where we must repeat characters by frequency). 
        Optimal solution uses a hash map + priority queue or bucket sort.
        */

        int n = s.size();
        vector<pair<int,char>> freq;

        // Build frequency vector for each character
        for(int i=0; i<n; i++){
            freq.push_back(make_pair(freqq(s, s[i]), s[i]));
        }

        // Sort by frequency
        sort(freq.begin(), freq.end());

        string ans = "";

        // Traverse in reverse to get descending frequency
        for(int i=n-1; i>=0; i--){
            ans += freq[i].second;  // ⚠️ only appends once, should append freq[i].first times
        }

        return ans;
    }
};




// better 

class Solution {
public:


    string frequencySort(string s) {   
        /*

        Approach:
        ---------
        1. Use a map<char,int> to count frequency of each character in `s`.
        2. Push all {frequency, character} pairs into a max-heap 
           (priority_queue in C++).
        3. Extract elements from the heap one by one:
            - For each pair {freq, char}, append `char` to the result string
              exactly `freq` times.
        4. Return the result string.

        Example:
        --------
        s = "tree"
        Step 1: Frequencies → {t:1, r:1, e:2}
        Step 2: Push into max-heap → [(2,e), (1,t), (1,r)]
        Step 3: Pop from heap:
                - e (2 times) → "ee"
                - t (1 time) → "eet"
                - r (1 time) → "eetr"
        Result = "eetr"

        Time Complexity: O(n log k)
            - Counting frequencies: O(n)
            - Building max-heap of size k (unique characters): O(k log k)
            - Extracting all characters: O(n log k) in total
            - Overall: O(n log k), where k ≤ 26 for lowercase or ≤ 256 for ASCII.
        Space Complexity: O(k)
            - Map and priority queue store at most k entries.

        This is efficient and passes all standard test cases.
        */

        int n = s.size();
        map<char,int> mpp;

        // Step 1: Count frequency of each character
        for(int i=0; i<n; i++){
            mpp[s[i]]++;
        }

        // Step 2: Push {frequency, character} into max-heap
        priority_queue<pair<int,char>> pq;
        for(auto it : mpp){
            pq.push({it.second, it.first});
        }

        // Step 3: Build the result string
        string ans = "";
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int cnt = it.first;
            char ch = it.second;

            // Append character `cnt` times
            for(int i=1; i<=cnt; i++){
                ans += ch;
            }
        }

        return ans;
    }
};


// Optimal Approach

class Solution {
public:
    string frequencySort(string s) {
        /*
        Problem:
        --------
        Given a string `s`, sort it in decreasing order of frequency.

        Approach (Bucket Sort):
        -----------------------
        1. Count frequency of each character using an unordered_map.
        2. Create a "bucket" array of size n+1, where bucket[i] stores all
           characters that appear exactly `i` times.
           - Max frequency of any character ≤ n.
        3. Traverse buckets from high to low frequency:
           - For each character in bucket[f], append it `f` times to the result.
        4. Return the result string.

        Example:
        --------
        s = "tree"
        Step 1: freq = {t:1, r:1, e:2}
        Step 2: bucket[1] = [t, r], bucket[2] = [e]
        Step 3: traverse buckets:
                freq=2 → "ee"
                freq=1 → "eert" (or "eetr")
        Result = "eert" or "eetr"

        Time Complexity: O(n)
            - Count frequencies: O(n)
            - Place characters into buckets: O(n)
            - Traverse buckets: O(n)
        Space Complexity: O(n)
            - Bucket array size is n+1
            - Hash map for frequencies
        */

        int n = s.size();

        // Step 1: Count frequencies
        unordered_map<char,int> freq;
        for(char c : s) {
            freq[c]++;
        }

        // Step 2: Create buckets
        vector<vector<char>> bucket(n+1);
        for(auto it : freq) {
            bucket[it.second].push_back(it.first);
        }

        // Step 3: Build result from buckets
        string ans = "";
        for(int f = n; f >= 1; f--) {
            for(char c : bucket[f]) {
                ans.append(f, c);  // append `c` f times
            }
        }

        return ans;
    }
};
