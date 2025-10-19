class Solution:
    def maxDistinctElements(self, nums: List[int], k: int) -> int:
        pre = -10**18
        nums.sort()
        ans = 0
        for x in nums:
            x = min(max(x - k,pre + 1),x + k)
            if x > pre:
                ans += 1
                pre = x
        return ans