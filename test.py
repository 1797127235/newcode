class Solution:
    def minOperations(self, nums: List[int]) -> int:
        ans = 0
        top = -1
        for x in nums:
            while top >= 0 and x < nums[top]:
                top -= 1
                ans += 1
            
            if top < 0 or x != nums[top]:
                top += 1
                nums[top] = x
        
        return ans + top + (nums[0] > 0)
    