class queens:
    def __init__(self, n):
        self.n = n
        self.count = 0
        self.all_ones = (1 << n) - 1
    
    def solve(self):
        self.backtrack(0, 0, 0, 0)
        return self.count
    
    def backtrack(self, row, columns, diag1, diag2):
        if row == self.n:
            self.count += 1
            return
        
    
        available_positions = self.all_ones &~ (columns | diag1 | diag2)
        
        while available_positions:
            position = available_positions &- available_positions
            
            available_positions -= position
            
            self.backtrack(
                row + 1,
                columns | position,
                (diag1 | position) << 1,
                (diag2 | position) >> 1
            )


def count_n_queens_fast(n):
    if n <= 0:
        return 0
    if n == 1:
        return 1
    
    solver = queens(n)
    return solver.solve()
