#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Given an n x n binary matrix grid, return the length of the shortest clear
 path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e.,
 (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e.,
 they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.*/
// Function to find shortest path in binary matrix
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=1;
        pq.push({1,{0,0}});
        int drow[]={0,-1,-1,-1,0,1,1,1};
        int dcol[]={-1,-1,0,1,1,1,0,-1};
        while(!pq.empty()){
            int distance=pq.top().first;
            int cx=pq.top().second.first;
            int cy=pq.top().second.second;

            pq.pop();

            for(int i=0;i<8;i++){
                int x=cx+drow[i];
                int y=cy+dcol[i];

                if(x>=0 && x<=n-1 && y>=0 && y<=n-1 && grid[x][y]==0){
                      if(distance+1<dist[x][y]){
                        dist[x][y]=distance+1;
                        pq.push({dist[x][y],{x,y}});
                      }
                }
            }
        }
        if(dist[n-1][n-1]==INT_MAX) return -1;
        return dist[n-1][n-1];
    }
};
/*
    Time Complexity (TC): O(n^2)
    Space Complexity (SC): O(n^2)
    where n = number of rows/columns in the grid
*/

