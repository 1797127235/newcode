from collections import defaultdict
from typing import List

class Solution:
    def countCoveredBuildings(self, n: int, buildings: List[List[int]]) -> int:
        ans = 0
        #预处理每行最大最小 每列最大最小
        row_min = defaultdict(lambda: int(1e9)) 
        row_max = defaultdict(lambda: -1)
        col_min = defaultdict(lambda: int(1e9))
        col_max = defaultdict(lambda: -1)

        for x,y in buildings:
            row_min[x] = min(row_min[x], y)
            row_max[x] = max(row_max[x], y)
            col_min[y] = min(col_min[y], x)
            col_max[y] = max(col_max[y], x)

        for x,y in buildings:
            if row_min[x] < y < row_max[x] and col_min[y] < x < col_max[y]:
                ans += 1

        return ans