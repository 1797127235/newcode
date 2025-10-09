#当发现无路可走时候，造最远的桥

class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        cur_right = 0
        next_right = 0
        for i in range(len(nums) - 1):
            next_right = max(next_right,i + nums[i])
            if i == cur_right:
                cur_right = next_right
                ans +=1

        return ans
