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
    
    def bicoloring(self, source):
        
        # color = 0(white)
        # color = 1(red)
        # color = 2 (blue)

        color = [0] * (self.numNodes + 1)
        queue = []
        color[source] = 1
        queue.append(source)
        

        while queue:

            u = queue.pop(0)

            #traverse the graph
            for v in self.graph[u]:

                if color[v] == 0:
                    if color[u] == 1:
                        color[v] = 2
                    else:
                        color[v] = 1
                    
                    queue.append(v)
                
                if color[v] == color[u]:
                    return False
        
        return True

# driver code
g = Graph()
g.buildGraph()
source = int(input("Source: "))

if g.bicoloring(source):
    print("Yes, graph is bicolorable.")
else:
    print("No, graph is not bicolorable.")
