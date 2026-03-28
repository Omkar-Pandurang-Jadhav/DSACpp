#include <bits/stdc++.h>
using namespace std;
/*
You are given an image represented by an m x n grid of integers image, 
where image[i][j] represents the pixel value of the image. You are also 
given three integers sr, sc, and color. Your task is to perform a flood
 fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent
 (pixels that share a side with the original pixel, either horizontally or vertically)
  and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated
 pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> copy=image;
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int original=copy[sr][sc];
        copy[sr][sc]=color;
        visited[sr][sc]=1;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;

            q.pop();

            int drow[]={0,-1,0,1};
            int dcol[]={-1,0,1,0};

            for(int i=0;i<4;i++){
                int r=row+drow[i];
                int c=col+dcol[i];

                if(r>=0 && r<=m-1 && c>=0 && c<=n-1 && visited[r][c]==0 && copy[r][c]==original){
                    q.push({r,c});
                    visited[r][c]=1;
                    copy[r][c]=color;
                }
            }
        }
        return copy;
    }
};