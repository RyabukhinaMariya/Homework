def solve_n_queens(n):

    def is_safe(board, row, col):

        for previos_col in range(col):
            previos_row = board[previos_col]

            if previos_row == row:
                return False

            if abs(previos_row - row) == abs(previos_col - col):
                return False

        return True

    def set_quin(col, current_board, solutions):

        if col == n:
            solutions.append(current_board)
            return

        for row in range(n):
            if is_safe(current_board, row, col):
                current_board.append(row)

                set_quin(col + 1, current_board, solutions)

                current_board.pop()

    solutions = []
    set_quin(0, [], solutions)
    return solutions

N = int(input())
print(len(solve_n_queens(N)))


