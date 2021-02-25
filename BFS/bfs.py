from collections import defaultdict

class Graph:

    def __init__(self):
        
        self.graph = defaultdict(list)
        self.numNodes = None
        self.numEdges = None

    def buildGraph(self):
        
        self.numNodes = int(input("Number of nodes: "))
        self.numEdges = int(input("Number of edges: "))
        
        for i in range(0, self.numEdges):
            u, v = [int(x) for x in input("Enter two value: ").split()]

            # undirected Graph
            self.graph[u].append(v)
            self.graph[v].append(u)
        
    def bfs(self, source):
       
        # Marked all unvisited
        visited = [False] * (self.numNodes + 1)
        # print(max(self.graph))
        distances = [None] * (self.numNodes + 1)
        
        # initialize Queue
        queue = []
        queue.append(source)

        # marked source visited
        visited[source] = True
        distances[source] = 0


        while queue:

            u = queue.pop(0)
            print(u, end = " ")

            for v in self.graph[u]:
                if visited[v] == False:
                    queue.append(v)
                    visited[v] = True
                    distances[v] = distances[u] + 1
        
        print("\nSource to destinations distance.\n")
        for i in range(1, self.numNodes + 1):
            print("{} -----> {} = {}".format(source, i, distances[i]))


# Driver Code

g = Graph()
g.buildGraph()
source = int(input("Source: "))
print("Breath First Traversal (starting from {})".format(source))
g.bfs(source)
