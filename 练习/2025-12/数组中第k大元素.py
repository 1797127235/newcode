#https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
#快速选择算法

from random import randint
from typing import List


class Solution:
    def parttion(self,nums,left,right)->int:
        i = randint(left,right)
        pivot = nums[i]

        nums[i],nums[left] = nums[left],nums[i]

        i,j = left + 1,right
        while True:
            while i <= right and nums[i] < pivot:
                i += 1
            while j >= left + 1 and nums[j] > pivot:
                j -= 1
            if i >= j:
                break
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1
        nums[left], nums[j] = nums[j], nums[left]
        return j
        
    def findKthLargest(self, nums: List[int], k: int) -> int:
        n = len(nums)
        target = n - k
        left, right = 0, n - 1
        while True:
            i = self.parttion(nums, left, right)
            if i == target:
                return nums[i]
            elif i < target:
                left = i + 1
            else:
                right = i - 1

