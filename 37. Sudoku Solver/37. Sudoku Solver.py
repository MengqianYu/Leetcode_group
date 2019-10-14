class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        row,col = [0 for i in range(9)],[0 for i in range(9)]
        grid = collections.defaultdict(lambda:0)
        wait = []
        for i in range(9):
            for j in range(9):
                if board[i][j] != ".":
                    check = 1<<int(board[i][j])
                    row[i] |= check
                    col[j] |= check
                    grid[(i//3,j//3)] |= check
                else:
                    wait.append([i,j])
        
        def dfs(ct):
            if ct == len(wait):
                return True
            x,y = wait[ct]
            for i in range(1,10):
                check = 1<<i
                if check&row[x] or check&col[y] or check&grid[(x//3,y//3)]:
                    continue
                
                row[x] |= check
                col[y] |= check
                grid[(x//3,y//3)] |= check
                
                if dfs(ct+1):
                    board[x][y] = str(i)
                    return True
                row[x] ^= check
                col[y] ^= check
                grid[(x//3,y//3)] ^= check
            return False
        
        dfs(0)