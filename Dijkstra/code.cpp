#include <bits/stdc++.h>
using namespace std;

#define SZ 15
#define INF ((1) << (30))

struct node {
    int u;
    int cost;

    node(int _u, int _cost){
        u = _u;
        cost = _cost;
    }

    bool operator < (const node &p) const{
        return cost > p.cost;
    }
};

void dijkstra(const vector<int> g[], vector<int> c [], const int nodes, int source){

    int distances[nodes + 1];
    for (int i = 1; i <= nodes; i++){
        distances[i] = INF;
    }

    // for(int i = 1; i <= nodes; i++){
    //     cout << distances[i] << endl;
    // }

    priority_queue<node> pq;
    pq.push(node(source, 0));   // 0 so that source can first priority.
    distances[source] = 0;

    while(!pq.empty()){
        node top = pq.top();
        int u = top.u;
        pq.pop();

        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i];

            if(distances[u] + c[u][i] < distances[v]){
                distances[v] = distances[u] + c[u][i];
                pq.push(node(v, distances[v]));
            }
        }
    }
    // printf("check");

    for(int i = 1; i <= nodes; i++){
        cout << "Source " << source << "->" << i << " distance " << distances[i] << endl;
    }
}

int main(){

    int numOfEdges, numOfNodes;
    vector<int> edges[SZ];
    vector<int> cost[SZ];
   
    cout << "Enter number of nodes and edges: ";
    cin >> numOfNodes >> numOfEdges;
    for(int i = 0; i < numOfEdges; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back(v);
        cost[u].push_back(w);
    }

    int source = 1;
    dijkstra(edges, cost, numOfNodes, source);

    return 0;
}