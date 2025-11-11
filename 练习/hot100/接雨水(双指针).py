from ast import List


class Solution:
    def trap(self, height: List[int]) -> int:
        ans = pre_max = suf_max = 0
        left, right = 0, len(height) - 1
        while left < right:
            pre_max = max(pre_max, height[left])
            suf_max = max(suf_max, height[right])
            if pre_max < suf_max:
                ans += pre_max - height[left]
                left += 1
            else:
                ans += suf_max - height[right]
                right -= 1
        return ans

'''
每次移动左右中较小的一边，
因为这一边的最高柱子已经确定会成为瓶颈，从而能直接决定该侧的接水量。
'''