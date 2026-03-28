# include<bits/stdc++.h>
using namespace std;

// This program is about to print matrix in spiral form the size can mxn

// There is only one solution and that is the optimal solution 
vector<int> printInSpiralForm(vector<vector<int>> & mat){
    // Time complexity is O(m*n) and space complexity is O(m*n)
    int m=mat.size();
    int n=mat[0].size();
    int right=n-1,left=0;
    int top=0,bottom=m-1;
    vector<int> ans;
    while(left<=right && top<=bottom){
    //left to right
    for(int i=left;i<=right;i++){
        ans.push_back(mat[top][i]);
    }
    top++;
    // Top to bottom
    for(int i=top;i<=bottom;i++){
        ans.push_back(mat[i][right]);
    }
    right--;
    // right to left
    if(top<=bottom){
    for(int i=right;i>=left;i--){
        ans.push_back(mat[bottom][i]);
    }
    }
    bottom--;
    // bottom to top
    if(left<=right){
    for(int i=bottom;i>=top;i--){
        ans.push_back(mat[i][left]);
    }
    }
    left++;
    }

    return ans;
}
int main(){
    int m,n;
    cout<<"Enter the number of rows and columns : ";
    cin>>m>>n;
    cout<<"Enter the element for an matrix : \n";
    vector<vector<int>> mat(n,vector<int>(m));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    vector<int> ans=printInSpiralForm(mat);
    cout<<"The matrix in spiral form is : \n";
    for(int i=0;i<m*n;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}