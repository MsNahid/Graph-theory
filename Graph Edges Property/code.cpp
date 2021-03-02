#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define UNVISITED -1
#define EXPLORED 1
#define VISITED 2

vector <vii> AdjList;
vi dfs_num;
vi parent;
int numCC;

void graphCheck(int u){
	dfs_num[u] = EXPLORED;

	for(int i = 0; i < AdjList[u].size(); i++){
		ii v = AdjList[u][i];
		if(dfs_num[v.first] == UNVISITED){
			parent[v.first] = u;
			graphCheck(v.first);

		}else if(dfs_num[v.first] == EXPLORED){
			if(v.first == parent[u]){
				printf("Two ways(%d, %d) - (%d, %d)\n", u, v.first, v.first, u);
			}else{
				printf("Back Edge(%d, %d) (Cycle)\n", u, v.first);
			}
		}else if(dfs_num[v.first] == VISITED){
			printf("Cross edge(%d, %d)\n", u, v.first);
		}
	}
	dfs_num[u] = VISITED;
}


int main(){

	int V, total_neighbors, id, weight;
	scanf("%d", &V);
	AdjList.assign(V, vii());
	for(int i = 0; i < V; i++){
		scanf("%d", &total_neighbors);
		for(int j = 0; j < total_neighbors; j++){
			scanf("%d %d", &id, &weight);
	        AdjList[i].push_back(ii(id, weight));
		}
	}
	puts("Graph edge property check");
	numCC = 0;
	dfs_num.assign(V, UNVISITED);
	parent.assign(V, -1);
	for(int i = 0; i < V; i++){
		if(dfs_num[i] == UNVISITED){
			printf("Component: %d\n", ++numCC);
		    graphCheck(i);
		}
	}
	return 0;
}
