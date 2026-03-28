/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take.
 To take course 1 you should have finished course 0. 
 So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should 
have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]
 */
#include <bits/stdc++.h>
using namespace std;

/*
    Intuition:
    - This algorithm finds a valid order to complete all courses given prerequisites.
    - We model courses as a **directed graph**, where an edge A → B means A must be taken before B.
    - We use **Kahn's Algorithm (Topological Sorting using BFS)** to get a valid order.
    - If no valid topological order exists (cycle detected), we return an empty list.
*/

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    int v = numCourses;
    int n = prerequisites.size();
    vector<vector<int>> adj(v);
    
    // Construct adjacency list
    for (int i = 0; i < n; i++) {
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    
    queue<int> q;
    vector<int> indegree(v, 0);
    
    // Compute in-degree of all nodes
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            indegree[adj[i][j]]++;
        }
    }
    
    // Push nodes with in-degree 0 into the queue
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0) q.push(i);
    }
    
    if (q.empty()) return {}; // If no node has in-degree 0, cycle exists
    
    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        
        for (int i = 0; i < adj[node].size(); i++) {
            indegree[adj[node][i]]--;
            if (indegree[adj[node][i]] == 0) q.push(adj[node][i]);
        }
    }
    
    if (topo.size() == v) return topo; // Valid order found
    return {}; // No valid order exists due to cycle
}

int main() {
    int numCourses, numPrerequisites;
    cout << "Enter number of courses: ";
    cin >> numCourses;
    cout << "Enter number of prerequisite pairs: ";
    cin >> numPrerequisites;
    
    vector<vector<int>> prerequisites(numPrerequisites, vector<int>(2));
    cout << "Enter prerequisite pairs (course, prerequisite):\n";
    for (int i = 0; i < numPrerequisites; i++) {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }
    
    vector<int> order = findOrder(numCourses, prerequisites);
    if (order.empty()) {
        cout << "No valid course order exists. Cycle detected.\n";
    } else {
        cout << "Valid course order: ";
        for (int course : order) {
            cout << course << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
    Time Complexity: O(V + E)
    - Each node is visited once -> O(V)
    - Each edge is processed once -> O(E)
    - Overall: O(V + E)

    Space Complexity: O(V + E)
    - Adjacency list stores E edges -> O(E)
    - In-degree array stores V nodes -> O(V)
    - Queue stores V nodes in worst case -> O(V)
    - Overall: O(V + E)
*/
