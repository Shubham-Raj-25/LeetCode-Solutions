class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        row = {}
        col = {}

        for i in range(len(grid)):
            count = 0
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    count += 1
            row[i] = count

        for i in range(len(grid[0])):
            count = 0
            for j in range(len(grid)):
                if grid[j][i] == 1:
                    count += 1
            col[i] = count
        
        ans = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1 and (row[i]>1 or col[j]>1):
                    ans += 1
        
        return ans
