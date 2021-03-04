/*



*/

#include <bits/stdc++.h>
using namespace std;

#define SZ 100
#define UNVISITED 0
vector <int> graph[SZ];
typedef vector <int> vi;
vi dfs_nums, parent, dfs_low;
int dfsNumberCounter;
bool articulation_vertex[SZ];
int dfs_root, rootChildren;

void articulationPointAndBridge(int u){
	dfs_nums[u] = dfs_low[u] = ++dfsNumberCounter;
	for(int j = 0; j < graph[u].size(); j++){
		int v = graph[u][j];
		if(dfs_nums[v] == UNVISITED){
			parent[v] = u;
			if(u == dfs_root) rootChildren++;
			articulationPointAndBridge(v);
			if(dfs_low[v] >= dfs_nums[u]){
				articulation_vertex[u] = true;
				printf("Check %d %d\n", u, v);
			}
			if(dfs_low[v] > dfs_nums[u]){
				printf("Edge (%d, %d) is a bridge\n", u, v);
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}else if(v != parent[u]){
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
	}
}

int main(){

	int V, E;
	cin >> V >> E;
	for(int i = 1; i <= E; i++){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfsNumberCounter = 0;
	dfs_nums.assign(V, UNVISITED);
	dfs_low.assign(V, 0);
	parent.assign(V, -1);
	memset(articulation_vertex, false, sizeof(articulation_vertex));
	puts("Bridges: ");

	for(int i = 1; i <= V; i++){
		if(dfs_nums[i] == UNVISITED){
			dfs_root = i;
			rootChildren = 0;
			articulationPointAndBridge(i);
			articulation_vertex[dfs_root] = (rootChildren > 1);
		}
	}
	puts("Articulation points:");
	for(int i = 1; i <= V; i++){
		if(articulation_vertex[i]){
			printf(" Vertex %d\n", i);
		}
	}

	return 0;
}
