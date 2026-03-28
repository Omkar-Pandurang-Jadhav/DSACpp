class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || i==m-1  || j==0 || j==n-1) && grid[i][j]==1){
                    q.push({i,j});
                    visited[i][j]=1;
                }

                if(grid[i][j]==1) cnt++;
            }
        }

        int count=0;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            count++;

            int drow[]={0,-1,0,1};
            int dcol[]={-1,0,1,0};

            for(int i=0;i<4;i++){
                int r=row+drow[i];
                int c=col+dcol[i];

                if(r>=0 && r<=m-1 && c>=0 && c<=n-1 && visited[r][c]==0 && grid[r][c]==1){
                    q.push({r,c});
                    visited[r][c]=1;
                }
            }
        }
        int ans=cnt-count;
        return ans;
    }
};