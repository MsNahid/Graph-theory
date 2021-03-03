#include <bits/stdc++.h>
using namespace std;

#define SZ 20

vector<int> AdjList[SZ];
bool visited[SZ];
stack<int> topsort;

void dfs(int u){

    visited[u] = true;
    for(int i = 0; i < AdjList[u].size(); i++){
        int v = AdjList[u][i];
        if(!visited[v]){
            dfs(v);
        }
    }
    topsort.push(u);
}   

int main(){

    int numNodes, numEdges;
    cout << "Enter number of nodes and edges: ";
    cin >> numNodes >> numEdges;
    int u, v;
 
    for(int i = 1; i <= numEdges; i++){
        cin >> u >> v;
        AdjList[u].push_back(v);
    }
    memset(visited, false, sizeof(visited));

    for(int i = 1; i <= numNodes; i++){
        if(!visited[i]){
            dfs(i);
        }
    }

    printf("Topological Sort: ");
    while(!topsort.empty()){
        int tp = topsort.top();
        topsort.pop();
        printf("%d ", tp);
    }
    putchar('\n');

    return 0;
}