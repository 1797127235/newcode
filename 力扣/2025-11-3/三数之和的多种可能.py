
from typing import List

class Solution:
    def threeSumMulti(self, arr: List[int], target: int) -> int:
        n = len(arr)
        ans = 0
        mod = 1000000007
        arr.sort()
        for i in range(n):
            l,r=i + 1,n - 1
            while l < r:
                total = arr[i] + arr[l] + arr[r]
                if total == target:
                    if arr[l] == arr[r]:
                        cnt = r - l + 1
                        ans = (ans + cnt * (cnt - 1) // 2 ) % mod
                        break
                    else:
                        lcnt,rcnt =1,1
                        while l + 1 < r and arr[l] == arr[l + 1]:
                            lcnt += 1
                            l += 1
                        while l + 1 < r and arr[r] == arr[r - 1]:
                            rcnt += 1
                            r -= 1
                        ans = (ans + lcnt * rcnt) % mod
                        l += 1
                        r -= 1
                elif total < target:
                    l += 1
                else:
                    r -= 1
        return ans % mod