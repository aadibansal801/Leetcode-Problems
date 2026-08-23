class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        ans = []
        board = [["."] * n for _ in range(n)]
        def isSafe(col, row):
            for c in range(col):
                if board[row][c] == "Q":
                    return False
            r,c = row-1,col-1
            while r>=0 and c>=0:
                if board[r][c] == "Q":
                    return False
                r-=1
                c-=1
            r,c = row+1,col-1
            while r<n and c>=0:
                if board[r][c] == "Q":
                    return False
                r+=1
                c-=1
            return True
        def solve(col):
            if col == n:
                ans.append(["".join(row) for row in board])
                return
            for row in range(n):
                if isSafe(col, row):
                    board[row][col] = "Q"
                    solve(col+1)
                    board[row][col] = "."
        solve(0)
        return ans