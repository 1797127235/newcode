from typing import List
class Solution:
    def maxPoints(self, technique1: List[int], technique2: List[int], k: int) -> int:
        n = len(technique1)

        #差排序
        diff = [(technique1[i] - technique2[i], technique1[i], technique2[i]) for i in range(n)]

        diff.sort(reverse=True)

        ans = 0
        for i in range(k):
            ans += diff[i][1]

        
        for i in range(k, n):
            ans += max(diff[i][1], diff[i][2])

        return ans