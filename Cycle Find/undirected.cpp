#include <bits/stdc++.h>
using namespace std;

#define SZ 15

#define UNVISITED -1
#define EXPLORED 1

vector<int> graph[SZ];
typedef vector<int> vi;
vi dfs_num, parent;

int cycle_start, cycle_end;
int numC = 0;

bool dfs(int u, int par){
    
    dfs_num[u] = EXPLORED;
    for(int v : graph[u]){
        if(v == par) continue;
        if(dfs_num[v] == EXPLORED){
            cycle_start = v;
            cycle_end = u;
            return true;
        }
        parent[v] = u;
        if(dfs(v, parent[v])){
            return true;
        }

    }
    return false;

}

void find_cycle(int numNodes, int vertex){

    cycle_start = -1;

    for(int u = vertex; u <= numNodes; u++){
        if(dfs_num[u] == UNVISITED && dfs(u, parent[u])){
            break;
        }
    }

    if(cycle_start == -1){
        cout << "Acyclic\n";

    }else{
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for(int v = cycle_end; v != cycle_start; v = parent[v]){
            cycle.push_back(v);
        }
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        printf("Cycle found %d: ", ++numC);
        for(int v : cycle){
            cout << v << " ";
        }
        cout << endl;
    }
}

int main(){

    int numNodes, numEdges;
    cout << "Enter number of nodes and edges: ";
    cin >> numNodes >> numEdges;

    dfs_num.assign(numNodes + 1, UNVISITED);
    parent.assign(numNodes + 1, -1);

    int u, v;
    for(int i = 1; i <= numEdges; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int u = 1; u <= numNodes; u++){
        if(dfs_num[u] == UNVISITED){
            find_cycle(numNodes, u);
        }
    }

    return 0;
}
