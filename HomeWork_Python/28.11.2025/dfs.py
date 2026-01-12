class Graph():
    def __init__(self, graph):
        if isinstance(graph, list) and all(isinstance(graph[i][j], int) for i in range(len(graph)) for j in range(len(graph[0]))): 
            self.graph = graph
        else: 
            raise ValueError('invalid garph')
        
        self.build_adj_list()
        
    def build_adj_list(self):
        self.adj_list = [[] for _ in range(len(self.graph))]
        for i in range(len(self.graph)):
            for j in range(len(self.graph[i])):
                if self.graph[i][j] == 1:
                    self.adj_list[i].append(j)
        return self.adj_list

    def dfs(self, start_node=0, visited=None):
        if visited is None:
            visited = set()
        
        res = []
        stack = [start_node]
        
        while stack:
            vertex = stack.pop()
            if vertex not in visited:
                visited.add(vertex)
                res.append(vertex)
                for neighbor in reversed(self.adj_list[vertex]):
                    if neighbor not in visited:
                        stack.append(neighbor)
        
        return res
    
    def dfs_all(self):
        visited = set()
        res = []
    
        for vertex in range(len(self)):
            if vertex not in visited:
                res.extend(self.dfs(vertex, visited))
    
        return res
    
    def __iter__(self):
        return iter(range(len(self)))
    
    def __len__(self):
        return len(self.graph)
    
    def __getitem__(self, vertex):
        return self.adj_list[vertex]
    
    def vertices(self):
         return range(len(self.adj_list))
    
    def __repr__(self):
        return f"graph with {len(self)} vertices"

    pass
