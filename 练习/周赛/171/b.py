import bisect
from typing import List
class Solution:
    def check(self,s:str) ->bool:
        n = len(s)
        i,j = 0,n-1
        while i < j:
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1
        return True

    def minOperations(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0] * n
        #预处理回文
        p = []

        mx = (1 << (max(nums).bit_length() + 1)) - 1

        for i in range(mx + 1):
            if self.check(bin(i)[2:]):
                p.append(i)

        for i,x in enumerate(nums):
            pos = bisect.bisect_left(p,x)
            res[i] = min(abs(x - p[pos]), abs(x - p[pos-1])) if pos > 0 else abs(x - p[pos])

        return res