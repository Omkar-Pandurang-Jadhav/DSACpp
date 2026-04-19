# include<bits/stdc++.h>
using namespace std;


void BFS(vector<int> adjList[],int v,int startingPoint){
    // Time complexity is O(N)+O(2E)
    // Space complexity si O(3N)
    vector<int> visited(v+1,0);
    queue<int> q;
    vector<int> traversal;
    q.push(startingPoint);
    visited[startingPoint]=1;
    while(!q.empty()){
        int p=q.front();
        q.pop();
        traversal.push_back(p);
        int i=0;
        while(i<adjList[p].size()){
            if(!visited[adjList[p][i]]){
                q.push(adjList[p][i]);
                visited[adjList[p][i]]=1;
            }
            i++;
        }
    }
    cout<<"The BFS Traversal is : \n";
    for(int i=0;i<traversal.size();i++){
        cout<<traversal[i]<<" ";
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
    BFS(adjList,n,start);
    return 0;
}

//. timePAsssss