class Matrix:
    def __init__ (self, arr):
        if not arr or not all(len(row) == len(arr[0]) for row in arr):
            raise ValueError
        self.rows = len(arr)
        self.cols = len(arr[0])
        self.arr = [[float(elem) for elem in row] for row in arr]
        
    def __summarize__(self, other: 'Matrix') -> 'Matrix':
        if self.rows != other.rows or self.cols != other.cols:
            raise ValueError
        
        result = [[self.arr[i][j] + other.arr[i][j] for j in range(self.cols)] for i in range(self.rows)]
        return Matrix(result)
    
    def __mult_to_el__(self, el) -> 'Matrix':
        result = [[self.arr[i][j] * el for j in range(self.cols)] for i in range(self.rows)]
        return Matrix(result)
    
    def __mult_matrix__(self, other: 'Matrix') -> 'Matrix':
        if self.cols != other.rows:
                raise ValueError
        result = [[0] * other.cols for m in range(self.rows)]
        for i in range(self.rows):
            for j in range(other.cols):
                for k in range(self.cols):
                    result[i][j] += self.arr[i][k] * other.arr[k][j]
        return Matrix(result)
    
    def determinant(self) -> float:
        if self.rows != self.cols:
            raise ValueError
        
        return self._determinant_recursive(self.arr)

    def _determinant_recursive(self, matrix) -> float:
        n = len(matrix)
        
        if n == 1:
            return matrix[0][0]
        if n == 2:
            return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]
        
        det = 0
        for col in range(n):
            m = [[matrix[i][j] for j in range(n) if j != col] for i in range(1, n)]
            det = det + ((-1) ** col) * matrix[0][col] * self._determinant_recursive(m)
        
        return det
    
    def __iter__(self):
        for row in self.arr:
            for el in row:
                yield el
    


