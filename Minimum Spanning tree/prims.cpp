#include <bits/stdc++.h>
using namespace std;

#define SZ 15
typedef pair<int, int> ii;
typedef vector<int> vi;
vector<ii> graph[SZ];
bool visited[SZ];
priority_queue<ii> pq;

void process(int u){
    visited[u] = true;
    for(int i = 0; i < graph[u].size(); i++){
        ii v = graph[u][i];
        if(!visited[v.first]){
            pq.push(ii(-v.second, -v.first));
        }
    }
}

int main(){

    int numNodes, numEdges;
    cout << "Enter number of nodes and edges: ";
    cin >> numNodes >> numEdges;

    int u, v, w;
    for(int i = 1; i <= numEdges; i++){
        cin >> u >> v >> w;
        graph[u].push_back(ii(v, w));
    }

    memset(visited, false, sizeof(visited));
    process(1);
    int mst_cost = 0;

    while(!pq.empty()){
        ii frnt = pq.top();
        pq.pop();
        v = -frnt.second;
        w = -frnt.first;

        if(!visited[v]){
            mst_cost += w;
            process(v);
        }
    }

    printf("Mst cost = %d (Prim's)\n", mst_cost);

    return 0;
}