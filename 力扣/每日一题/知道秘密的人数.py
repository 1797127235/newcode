#直接向后推知道的人数
class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        # dp[i] 第i天知道秘密的人
        mod = 10**9+7
        dp = [0] * (n+1)
        dp[1] = 1

        for i in range(1,n+1):
            for j in range(i+delay,i+forget):
                if j<= n:
                    dp[j] += dp[i]  
                    dp[j] %= mod
        
        res = 0
        for i in range(n+1-forget,n+1):
            res+=dp[i]
            res%=mod
        return res
