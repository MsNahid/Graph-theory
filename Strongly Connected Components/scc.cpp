#include <bits/stdc++.h>
using namespace std;

#define SZ 20
bool visited[SZ];
vector<int> adjlist[SZ];
vector<int> transpose[SZ];
stack<int> stck;

void dfs(int u){

    visited[u] = true;
    for(int i = 0; i < adjlist[u].size(); i++){
        int v = adjlist[u][i];
        if(!visited[v]){
            dfs(v);
        }
    }
    stck.push(u);
}

void dfs_transpose(int u){

    printf(" %d", u);
    visited[u] = true;
    for(int i = 0; i < transpose[u].size(); i++){
        int v = transpose[u][i];
        if(!visited[v]){
            dfs_transpose(v);
        }
    }
}

int main(){

    int numNodes, numEdges;
    cout << "Enter number of nodes and edges: ";
    cin >> numNodes >> numEdges;

    for(int i = 0; i < numEdges; i++){
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        transpose[v].push_back(u);
    }

    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= numNodes; i++){
        if(!visited[i]){
            dfs(i);
        }
    }

    memset(visited, false, sizeof(visited));
    puts("Strong connected components.");
    int num = 0;
    while(!stck.empty()){
        int tp = stck.top();
        stck.pop();
        if(!visited[tp]){
            printf("\nSCC %d:", ++num);
            dfs_transpose(tp);
        }
    }

    return 0;
}