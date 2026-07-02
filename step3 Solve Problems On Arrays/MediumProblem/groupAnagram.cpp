/*
Question:
Given an array of strings `strs`, group all the anagrams together.
You can return the groups in any order.

An anagram is a word or phrase formed by rearranging the letters
of another word using all the original letters exactly once.

Example:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Approach:
1. Traverse each string in the input array.
2. Create a copy of the current string and sort its characters.
3. The sorted string acts as a unique key because all anagrams
   produce the same sorted sequence.
4. Store the original string in a map corresponding to its sorted key.
5. After processing all strings, collect all the grouped values
   from the map into the answer vector.

Time Complexity:
O(N * K log K)
where,
N = number of strings
K = average length of each string

Space Complexity:
O(N * K)
for storing the grouped anagrams.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // Stores sorted string as key and all its anagrams as value
        map<string, vector<string>> groups;

        // Process every string
        for (const string &word : strs) {

            // Create a sorted version of the current string
            string key = word;
            sort(key.begin(), key.end());

            // Insert the original string into its corresponding group
            groups[key].push_back(word);
        }

        // Store final grouped anagrams
        vector<vector<string>> result;

        // Extract all groups from the map
        for (auto &entry : groups) {
            result.push_back(entry.second);
        }

        return result;
    }
};