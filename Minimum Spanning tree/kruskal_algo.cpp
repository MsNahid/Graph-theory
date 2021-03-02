#include <bits/stdc++.h>
using namespace std;

#define SZ 15
int parent[SZ];

void make_set(int u){
    parent[u] = u;
}

void init_disjoint_set(int nodesNum){
    for(int i = 1; i <= nodesNum; i++){
        make_set(i);
    }
}

int findRepresentative(int r){

    if(parent[r] == r) return r;
    parent[r] = findRepresentative(parent[r]);
    return parent[r];
}

bool setUnion(int a, int b){

    int u = findRepresentative(a);
    int v = findRepresentative(b);

    if(u != v){
        parent[u] = v;
        return true;
    }

    return false;
}

struct edges{

    int u, v, w;
    edges(int _u, int _v, int _w){
        u = _u;
        v = _v;
        w = _w;
    }
};

bool comp(edges a, edges b){
    return a.w < b.w;
}

int main(){

    int numNodes, numEdges;
    cout << "Enter the number of nodes and edges: ";
    cin >> numNodes >> numEdges;

    init_disjoint_set(numNodes);
    vector<edges> graph;

    for (size_t i = 1; i <= numEdges; i++){

        int u, v, w;
        cin >> u >> v >> w;
        graph.push_back(edges(u, v, w));
    }

    sort(graph.begin(), graph.end(), comp);
    int cost = 0;
    for(int i = 0; i < graph.size(); i++){
        edges currentEdge = graph[i];
        bool ok = setUnion(currentEdge.u, currentEdge.v);
        if(ok){
            cost += currentEdge.w;
        }
    }

    cout << "MST(Kurskal algorithm): " << cost << endl;
    return 0;
}