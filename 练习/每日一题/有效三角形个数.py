class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        ans = 0
        for k in range(2,n):
            l,r = 0,k-1
            while l < r:
                if nums[l] + nums[r] > nums[k]:
                    ans += r - l
                    r -= 1
                else:
                    l += 1
        return ans