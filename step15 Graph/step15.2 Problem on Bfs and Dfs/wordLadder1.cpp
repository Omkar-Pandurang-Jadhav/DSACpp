#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    // Time Complexity: O(N * wordSize * 26)
    // Space Complexity: O(N)
    
    // Convert wordList into an unordered_set for quick lookup
    unordered_set<string> st(wordList.begin(), wordList.end());
    
    // Queue for BFS, storing the current word and its transformation step count
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    st.erase(beginWord); // Remove the starting word if present
    
    while (!q.empty()) {
        string word = q.front().first;
        int step = q.front().second;
        q.pop();
        
        // If we reach the endWord, return the transformation steps
        if (word == endWord) return step;
        
        // Try changing each character in the word to every letter from 'a' to 'z'
        for (int i = 0; i < word.size(); i++) {
            char temp = word[i]; // Store the original character
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                
                // If the modified word exists in the set, push it to the queue
                if (st.find(word) != st.end()) {
                    st.erase(word); // Remove from the set to avoid revisiting
                    q.push({word, step + 1});
                }
            }
            word[i] = temp; // Restore the original character
        }
    }
    
    return 0; // No transformation sequence found
}

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    
    int result = ladderLength(beginWord, endWord, wordList);
    cout << "Shortest transformation sequence length: " << result << endl;
    
    return 0;
}
