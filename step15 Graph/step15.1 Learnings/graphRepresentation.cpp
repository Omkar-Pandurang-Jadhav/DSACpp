# include<bits/stdc++.h>
using namespace std;

void graphCreation(vector<vector<int>> &a,int v1,int v2){
    // If graph is weighted graph so insted of i store its weight
    a[v1][v2]=1;
    a[v2][v1]=1;
}
int main(){
    int n,m;
    cout<<"Enter the number of vertext and number of edges : ";
    cin>>n>>m;
    cout<<"Enter the edges between node : \n";
    // 1 based graph
    vector<vector<int>> a(n+1,vector<int>(n+1,0));

    // For weighted graph make array of vector<pair<int,int>> where first will store neighbour and then second
    // wiil store weight
    vector<int> adjList[n+1];
    // for undirected graph
    for(int i=0;i<m;i++){
        cout<<"Enter the edge : "<<i<<" \n";
        int v1,v2;
        cin>>v1>>v2;
        graphCreation(a,v1,v2);
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }
    // Space complexity is O(N^2)
    cout<<"Graph representation in matrix form : \n";
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"\n";
    // Space Complexity is O(2*E)
    cout<<"Graph representation in adjecency List form : \n";
    for(int i=0;i<n+1;i++){
        cout<<i;
        for(int j=0;j<adjList[i].size();j++){
            cout<<"->"<<adjList[i][j];
        }
        cout<<"\n";
    }
    return 0;
}