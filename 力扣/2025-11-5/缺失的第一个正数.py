'''
    原地置换法
'''
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)

        i = 0
        while i < n:
            x = nums[i]
            if x <=0 or x > n or x == i + 1 or nums[x - 1] == x:
                i += 1
            else:
                nums[i],nums[x - 1] = nums[x - 1],nums[i]

        for i in range(n):
            if nums[i] != i + 1:
                return i + 1

        return n + 1