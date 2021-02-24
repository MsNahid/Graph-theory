#include <bits/stdc++.h>
using namespace std;

#define INF 1<<28
#define MX 100

void init(int graph[][MX], int next[][MX], int numNodes){

    for(int i = 1; i <= numNodes; i++){
        for(int j = 1; j <= numNodes; j++){
            if(i != j){
                graph[i][j] = INF;
            }else{
                graph[i][j] = 0;
            }
        }
    }

    for(int i = 1; i <= numNodes; i++){
        for(int j = 1; j <= numNodes; j++){
            next[i][j] = j;
        }
    }
}

void floyd_warshall(int numNodes, int graph[][MX], int next[][MX]){

    for(int k = 1; k <= numNodes; k++){
        for(int i = 1; i <= numNodes; i++){
            for(int j = 1; j <= numNodes; j++){
                if(graph[i][j] > graph[i][k] + graph[k][j]){
                    next[i][j] = next[i][k];
                }
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
               
            }
        }
    }
}


vector<int> findPath(int i, int j, int next[][MX]){
    vector<int> path;
    path.push_back(i);

    while(i != j){
        i = next[i][j];
        path.push_back(i);
    }

    return path;
}

void printAllPairShortestPath(int graph[][MX], int numNodes){
    for(int i = 1; i <= numNodes; i++){
        for(int j = 1; j <= numNodes; j++){
            cout << graph[i][j] << '\t';
        }
        putchar('\n');
    }
    puts("");
}

int main(){
    
    cout << "Hewloo";
    int numNodes, numEdges;
    cout << "Enter number of nodes and edges: ";
    cin >> numNodes >> numEdges;
    int graph[MX][MX];
    int next[MX][MX];

    init(graph, next, numNodes);
    
    for(int i = 1; i <= numNodes; i++){
        for(int j = 1; j <= numNodes; j++){
            cout << next[i][j] << '\t';
        }
        putchar('\n');
    }
    puts("");
    puts("\n\n");

    for(int i = 1; i <= numEdges; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    // printAllPairShortestPath(graph, numNodes);
    floyd_warshall(numNodes, graph, next);
    cout << "After floyd warshall algorithm.\n\n";
    printAllPairShortestPath(graph, numNodes);
    
    // check next[][]
    // puts("\n\n");
    // for(int i = 1; i <= numNodes; i++){
    //     for(int j = 1; j <= numNodes; j++){
    //         cout << next[i][j] << '\t';
    //     }
    //     putchar('\n');
    // }
    // puts("");

    int source, destination;
    cout << "Enter source and destination for path: ";
    cin >> source >> destination;
    vector<int> path = findPath(source, destination, next);

    if(path.size() > 2){
        cout << source << " --------> " << destination;
        for(int i = 0; i < path.size(); i++){
            cout << path[i] << " ";
        }
        puts("");

    }else{
        puts("No path between source and destination.");
    }

    return 0;
}
