#include <bits/stdc++.h>
using namespace std;
const int max_n = 10000;
const int LOG = 20;
vector<int> child[max_n];
int parent[max_n][LOG];
int depth[max_n];

void dfs_lca(int src){

    for(auto it:child[src]){
        depth[it] = depth[src] + 1;
        parent[it][0] = src;
        for(int j = 1;j<LOG;j++){
            parent[it][j] = parent[parent[it][j-1]][j-1];
            
        }
        dfs_lca(it);
    }
}
int get_lca1(int a,int b){ //O(n)//
    if(depth[a] < depth[b]){
        swap(a,b);

    }
    while(depth[a] > depth[b]){
        a = parent[a][0];
    } 
    while(a != b){
        a = parent[a][0];
        b = parent[b][0];
    }
    return -1;
}
int main(){
    return 0;
}