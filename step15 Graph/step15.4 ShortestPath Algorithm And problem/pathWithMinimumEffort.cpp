/*
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns,
 where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, 
 (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, 
 down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

Example 1:

Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

Example 2:*/


class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        int ans=-1;
        if(n==1 && m==1) return 0;
        if(n==1){
            for(int i=1;i<m;i++){
                ans=max(ans,abs(heights[0][i]-heights[0][i-1]));
            }
            return ans;
        }
        if(m==1){
            for(int i=1;i<n;i++){
                ans=max(ans,abs(heights[i][0]-heights[i-1][0]));
            }
            return ans;
        }
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;

        int drow[]={0,-1,0,1};
        int dcol[]={-1,0,1,0};

        while(!pq.empty()){
            int d=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;

            pq.pop();

            for(int i=0;i<4;i++){
                int r=row+drow[i];
                int c=col+dcol[i];

                if(r>=0 && r<=n-1 && c>=0 && c<=m-1){
                    int effort=max(d,abs(heights[row][col]-heights[r][c]));
                    if(effort<dist[r][c]){
                        dist[r][c]=effort;
                        pq.push({dist[r][c],{r,c}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};


/*

Complexity	Value
Time Complexity	O((n×m)×log⁡(n×m))O((n×m)×log(n×m))
Space Complexity	O(n×m)O(n×m)

*/