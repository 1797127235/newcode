from typing import List

class Solution:

    def countPermutations(self, complexity: List[int]) -> int:
        n = len(complexity)
        if n == 1: return 1
        mod = int(1e9 + 7)
        mn = min(complexity)
        if complexity[0] != mn:
            return 0
        cnt = 0
        for x in complexity:
            if x == mn:
                cnt += 1
            if cnt > 1:
                return 0
        fact = [1] * (n + 1)
        for i in range(2, n + 1):
            fact[i] = fact[i - 1] * i % mod
        
        ans = fact[n - 1]
        return ans


        

        
        
