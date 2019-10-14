class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        
        h = []
        ans = grid[0][0]
        r,c = len(grid),len(grid[0])
        heapq.heappush(h,[grid[0][0],0,0])
        visited = set()
        # visited.add((0,0))
        while h:
            value,curx,cury = heapq.heappop(h)
            if (curx,cury) in visited:
                continue
            visited.add((curx,cury))
            ans = max(ans,value)
            if curx==r-1 and cury==c-1:
                return ans
            for i,j in [[curx+1,cury],[curx-1,cury],[curx,cury+1],[curx,cury-1]]:
                if -1<i<r and -1<j<c:
                    heapq.heappush(h,[grid[i][j],i,j])