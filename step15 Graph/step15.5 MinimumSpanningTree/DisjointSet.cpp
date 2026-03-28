# include<bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<int> treerank;
vector<int> size;
void  DisjointSet(int n) {
        treerank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n+1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i]=1;
        }
    }

int findUPar(int x){
    if(x==parent[x]) return x;
    return parent[x]=findUPar(parent[x]);
}

void unionByRank(int x,int y){
    int px=findUPar(x);
    int py=findUPar(y);

    if(px==py) return ;
    if(treerank[px]>treerank[py]){
        parent[py]=px;
    }
    else if(treerank[px]<treerank[py]){
        parent[px]=py;
    }
    else{
        parent[py]=px;
        treerank[px]++;
    }
}
void unionBySize(int x, int y) {
        int px = findUPar(x);
        int py = findUPar(y);

        if (px == py) return; // Already in same set

        // Attach smaller component under larger component
        if (size[px] > size[py]) {
            parent[py] = px;
            size[px] += size[py];
        }
        else {
            parent[px] = py;
            size[py] += size[px];
        }
    }

int main() {
    DisjointSet(7);
    unionByRank(1, 2);
    unionByRank(2, 3);
    unionByRank(4, 5);
    unionByRank(6, 7);
    unionByRank(5, 6);
    // if 3 and 7 same or not
    if (findUPar(3) == findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    unionByRank(3, 7);

    if (findUPar(3) == findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}