class Solution:
    def f(self,x:int) -> bool:
        if x < 2:
            return False
        for i in range(2,int(x**0.5)+1):
            if x % i == 0:
                return False
        return True
    def completePrime(self, num: int) -> bool:
        s = str(num)
        n = len(s)

        for k in range(1,n + 1):
            pre = int(s[:k])
            suf = int(s[-k:])

            if not self.f(pre) or not self.f(suf):
                return False
            
        return True