class Frozen_matrix:
    def __init__ (self, arr):
        if not arr or not all(len(row) == len(arr[0]) for row in arr):
            raise ValueError
        self.rows = len(arr)
        self.cols = len(arr[0])
        self.arr = tuple(tuple(float(elem) for elem in row) for row in arr)

        self._hash = None
        
    def __summarize__(self, other: 'Frozen_matrix') -> 'Frozen_matrix':
        if self.rows != other.rows or self.cols != other.cols:
            raise ValueError
        
        result = [[self.arr[i][j] + other.arr[i][j] for j in range(self.cols)] for i in range(self.rows)]
        return Frozen_matrix(result)
    
    def __mult_to_el__(self, el) -> 'Frozen_matrix':
        result = [[self.arr[i][j] * el for j in range(self.cols)] for i in range(self.rows)]
        return Frozen_matrix(result)
    
    def __mult_Frozen_matrix__(self, other: 'Frozen_matrix') -> 'Frozen_matrix':
        if self.cols != other.rows:
                raise ValueError
        result = [[0] * other.cols for m in range(self.rows)]
        for i in range(self.rows):
            for j in range(other.cols):
                for k in range(self.cols):
                    result[i][j] += self.arr[i][k] * other.arr[k][j]
        return Frozen_matrix(result)
    
    def determinant(self) -> float:
        if self.rows != self.cols:
            raise ValueError
        
        result = self.arr
        
        return self._determinant_recursive(result)

    def _determinant_recursive(self, result) -> float:
        n = len(result)
        
        if n == 1:
            return result[0][0]
        if n == 2:
            return result[0][0] * result[1][1] - result[0][1] * result[1][0]
        
        det = 0
        for col in range(n):
            m = [[result[i][j] for j in range(n) if j != col] for i in range(1, n)]
            det = det + ((-1) ** col) * result[0][col] * self._determinant_recursive(m)
        
        return det
    
    def __iter__(self):
        for row in self.arr:
            for el in row:
                yield el
    
    def __hash__(self) -> int:
        if self._hash is None:
            data_str = str(self._data)
            self._hash = hash(data_str)
        return self._hash



