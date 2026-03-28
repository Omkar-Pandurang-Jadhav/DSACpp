#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adjList[],int v,int startingPoint,vector<int> &traversal,vector<int> &visited){
    // Space complexity is O(N)+O(N)+O(N)
    // Time complexity is O(N)+O(2E)
    visited[startingPoint]=1;
    traversal.push_back(startingPoint);
    for(int i=0;i<adjList[startingPoint].size();i++){
        if(!visited[adjList[startingPoint][i]]){
            dfs(adjList,v,adjList[startingPoint][i],traversal,visited);
        }
    }
}
int main(){
    int n,m;
    cout<<"Enter the number of vertex and edges : \n";
    cin>>n>>m;
    vector<int> adjList[n+1];
    cout<<"Enter the edges between the vertex : \n";
    for(int i=0;i<m;i++){
        cout<<"Edge "<<(i+1)<<" : ";
        int v1,v2;
        cin>>v1>>v2;
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }

    cout<<"The graph is : \n";
    for(int i=1;i<n+1;i++){
        cout<<i;
        for(int j=0;j<adjList[i].size();j++){
            cout<<"->"<<adjList[i][j];
        }
        cout<<"\n";
    }
    cout<<"Enter the starting point : ";
    int start;
    cin>>start;
    vector<int> visited(n+1,0);
    vector<int> traversal;
    dfs(adjList,n,start,traversal,visited);
    cout<<"DFS traversal is : \n";
    for(int i=0;i<traversal.size();i++){
        cout<<traversal[i]<<" ";
    }
    
    return 0;
}