# include<bits/stdc++.h>
using namespace std;

// This program is about to rotate an nxn matrix by 90 degree

// Brute force approach
vector<vector<int>> rotateMatrix(vector<vector<int>> &mat,int n){

    // Here we can observe in matrix every element mat[i][j] is placed at ans[j][n-1-i] matrix
    // Time complexity is O(N*N) and Space complexity is O(N*N)
    vector<vector<int>> ans(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[j][n-1-i]=mat[i][j];
        }
    }
    return ans;
}

// Optimal solution
void rotateMatrixdup1(vector<vector<int>> &mat,int n){

    // First make transpose of an matrix
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
               int temp=mat[i][j];
               mat[i][j]=mat[j][i];
               mat[j][i]=temp;
        }
    }
    for(int i=0;i<n;i++){
        int start=0;
        int end=n-1;
        while(start<end){
            int temp=mat[i][start];
            mat[i][start]=mat[i][end];
            mat[i][end]=temp;
            start++;
            end--;
        }
    }

}

int main(){
  int n;
  cout<<"Enter the no of rows and column for nxn matrix : ";
  cin>>n;
  vector<vector<int>> mat(n,vector<int>(n));
  cout<<"Enter the element for matrix : \n";
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>mat[i][j];
    }
  }
  // vector<vector<int>> ans=rotateMatrix(mat,n);
  // cout<<"The rotated matrix is : \n";
  // for(int i=0;i<n;i++){
  //  for(int j=0;j<n;j++){
  //      cout<<ans[i][j]<<" ";
  //  }
  //  cout<<"\n";
  // }
   rotateMatrixdup1(mat,n);
  cout<<"The rotated matrix is : \n";
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<mat[i][j]<<" ";
    }
    cout<<"\n";
  }
  
  return 0;
}