# include<bits/stdc++.h>
using namespace std;

// This program is about the matrix is given of size n*m containing only zeros and one 
// so when we find zero at position say (i,j) then we have to replace all element in row i and
// column j with zero

void markRow(vector<vector<int>> &mat,int i,int column){
    for(int j=0;j<column;j++){
        if(mat[i][j]!=0){
        mat[i][j]=-1;
        }
    }
}
void markColumn(vector<vector<int>> &mat,int j,int row){
    for(int i=0;i<row;i++){
       if(mat[i][j]!=0){
        mat[i][j]=-1;
       }
    }
}
void printMatrix(vector<vector<int>> mat,int row,int column){
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void setMatrixToZero(vector<vector<int>> &mat,int row,int column){
    // Time complexity is (m*n)*(m+n)+(m*n) 
    
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
          if(mat[i][j]==0){
            markRow(mat,i,column);
            markColumn(mat,j,row);
          }
        }
    }
    for(int i=0;i<row;i++){
      for(int j=0;j<column;j++){
        if(mat[i][j]==-1){
            mat[i][j]=0;
        }
      }
    }
    printMatrix(mat,row,column);
}

// Better solution 
void setMatrixToZerodup1(vector<vector<int>> &mat,int row,int column){
    // Time complexity is O(m*n)+O(m*n)
    // Space complexity is O(m)+O(n)
    vector<int> rows(row,0);                       
    vector<int> col(column,0);    
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(mat[i][j]==0){
                rows[i]=1;
                col[j]=1;
            }
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(rows[i]==1 || col[j]==1){
                mat[i][j]=0;
            }
        }
    }
    printMatrix(mat,row,column);
}

// Optimal solution 
void setMatrixToZerodup2(vector<vector<int>> &mat,int row,int column){
  //  vector<int> rows(row,0);  -> mat[..][0]                     
  //  vector<int> col(column,0);  -> mat[0][..]

  // Time complexity is O(2*m*n) and space complexity is O(1)
    int col0=1;
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(mat[i][j]==0){
                // marking row[i]
                mat[i][0]=0;
                // marking col[j]
                if(j!=0){
                    mat[0][j]=0;
                }
                else {
                    col0=0;
                }
            }     
        }
    }
    for(int i=1;i<row;i++){
        for(int j=1;j<column;j++){
            if(mat[i][j]!=0){
              if(mat[0][j]==0 || mat[i][0]==0){    
                mat[i][j]=0;  
              }
            }
        }
    }
    if(mat[0][0]==0){
        for(int j=0;j<column;j++){
            mat[0][j]=0;
        }
    }
    if(col0==0){
        for(int i=0;i<row;i++){
            mat[i][0]=0;
        }
    }
    printMatrix(mat,row,column);
}
int main(){
    int row,column;
    cout<<"Enter the value for number of rows and columns : ";
    cin>>row>>column;
    cout<<"Enter the element for matrix of size "<<row<<" x "<<column<<" : \n";
    vector<vector<int>> mat(row,vector<int>(column));
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cin>>mat[i][j];
        }
    }
    cout<<"The modified matrix is : \n";
    // setMatrixToZero(mat,row,column);
    // setMatrixToZerodup1(mat,row,column);
    setMatrixToZerodup2(mat,row,column);
   
    return 0;           
}