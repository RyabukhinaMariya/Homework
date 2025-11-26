class Graph():
    def __init__(self, graph):
        if graph: 
            self.graph = graph
        else: 
            self.graph = []

    def dfs(self, start_node=0, visited=None, inter_arr=None):
        if visited is None:
            visited = [0] * len(self.graph)
        if inter_arr is None:
            inter_arr = []
    
        visited[start_node] = 1
        inter_arr.append(start_node)
    
        for neighbor in range(len(self.graph)):
            if self.graph[start_node][neighbor] == 1 and not visited[neighbor]:
                self.dfs(neighbor, visited, inter_arr)
    
        return inter_arr
    
    def __iter__(self):
        return iter(self.dfs(0))
 
    pass
