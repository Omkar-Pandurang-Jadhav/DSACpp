/*

Given a list of accounts where each element accounts[i] is a list of strings, where the first
 element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there 
is some common email to both accounts. Note that even if two accounts have the same name, they may belong 
\to different people as people could have the same name. A person can have any number of accounts initially,
 but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is 
the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

 

Example 1:

Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.

Example 2:  
*/

// Problem: Merge accounts based on common emails using Disjoint Set Union (DSU)
// Approach: 
// 1️⃣ Each email belongs to an account index. 
// 2️⃣ If an email is already mapped to an account, union the current account with the earlier one.
// 3️⃣ After processing all emails, merge emails belonging to the same parent account.
// 4️⃣ Finally, sort the emails and prepend the account name.
// 5️⃣ Return the list of merged accounts.

class Solution {
public:

// Disjoint Set Union (DSU) arrays for parent tracking and rank optimization
vector<int> parent;
vector<int> treerank;

// Function to initialize DSU for 'n' accounts
void DisjointSet(int n) {
    treerank.resize(n + 1, 0);      // Initialize rank array
    parent.resize(n + 1);           // Initialize parent array
    for (int i = 0; i <= n; i++) {
        parent[i] = i;              // Each account is initially its own parent
    }
}

// Function to find ultimate parent with path compression
int findUPar(int x){
    if(x == parent[x]) return x;
    return parent[x] = findUPar(parent[x]);
}

// Function to merge two sets by rank
void unionByRank(int x, int y){
    int px = findUPar(x); // Parent of x
    int py = findUPar(y); // Parent of y

    if(px == py) return; // If already in same set, do nothing

    // Merge smaller rank tree under larger rank tree
    if(treerank[px] > treerank[py]){
        parent[py] = px;
    }
    else if(treerank[px] < treerank[py]){
        parent[px] = py;
    }
    else{
        parent[py] = px;
        treerank[px]++;
    }
}

// Main function to merge accounts by common emails
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();  // Number of accounts

    DisjointSet(n);  // Initialize DSU

    // Map to track each email and the corresponding account index it belongs to
    unordered_map<string, int> mpp;

    // Process each account and its emails
    for(int i = 0; i < n; i++){
        for(int j = 1; j < accounts[i].size(); j++){
            string email = accounts[i][j];

            // If email seen first time, map it to this account
            if(mpp.find(email) == mpp.end()){
                mpp[email] = i;
            }
            else {
                // If email already mapped, union this account with the previous account
                unionByRank(mpp[email], i);
            }
        }
    }

    // Array to collect emails for each parent account after unions
    vector<string> mergedMail[n];
    for(auto it : mpp){
        string email = it.first;
        int accountIdx = it.second;

        // Find parent of this email's account index
        mergedMail[findUPar(accountIdx)].push_back(email);
    }

    vector<vector<string>> ans;  // Final merged account list

    // Now prepare final merged accounts
    for(int i = 0; i < n; i++){
        if(mergedMail[i].size() == 0) continue;  // If no emails, skip

        vector<string> temp;

        // First, add account name (from original accounts)
        temp.push_back(accounts[i][0]);

        // Sort the emails lexicographically
        sort(mergedMail[i].begin(), mergedMail[i].end());

        // Add all emails to this account's list
        for(auto it : mergedMail[i]){
            temp.push_back(it);
        }

        // Add this merged account to final answer
        ans.push_back(temp);
    }

    return ans;  // Return merged account list
}
};
