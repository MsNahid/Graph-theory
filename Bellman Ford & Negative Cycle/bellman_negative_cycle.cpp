#include <bits/stdc++.h>
using namespace std;

#define SZ 20
#define INF 22222222

void bellmanNegativeCycle(vector<int> g[], vector<int> cost[], int numNodes, int source){
    int distance[numNodes + 2];
    for(int i = 1; i <= numNodes; i++) distance[i] = INF;

    distance[source] = 0;
    bool isNegCycle = false;

    for(int k = 1; k <= numNodes; k++){
        bool updated = false;
        for(int u = 1; u <= numNodes; u++){
            for(int i = 0; i < g[u].size(); i++){
                int v = g[u][i];
                if(distance[u] + cost[u][i] < distance[v]){
                    distance[v] = distance[u] + cost[u][i];
                    updated = true;
                }
            }
        }
        if(k == numNodes && updated){
            isNegCycle = true;
        }
    }

    puts("Output: ");
    if(isNegCycle){
        puts("Negative cycle detected");
    }
}

int main(){
    
    vector<int> graph[SZ], cost[SZ];
    int numNodes, numEdges;
    cout << "Enter number of nodes and edges: ";
    cin >> numNodes >> numEdges;

    for(int i = 1; i <= numEdges; i++){
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back(v);
        graph[v].push_back(u);

        cost[u].push_back(w);
        cost[v].push_back(w);
    }

    int source;
    cout << "Enter source: ";
    cin >> source;
    bellmanNegativeCycle(graph, cost, numNodes, source);

    return 0;
}