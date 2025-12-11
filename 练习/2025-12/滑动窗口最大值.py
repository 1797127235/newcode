from collections import deque
from typing import List

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)

        max_q = deque()
        res = []
        for i,x in enumerate(nums):
            while max_q and nums[max_q[-1]] <= x:
                max_q.pop()
            max_q.append(i)
            if i >= k - 1:
                while max_q[0] <= i - k:
                    max_q.popleft()
                res.append(nums[max_q[0]])

        return res