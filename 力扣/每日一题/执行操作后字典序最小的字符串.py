#bfs 裴蜀定理

class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        q = deque([s])

        visited = {s}
        ans = s

        while q:
            cur_s = q.popleft()

            if cur_s < ans:
                ans = cur_s
            
            s_list = list(cur_s)

            for i in range(1,len(s_list),2):
                new_digit = (int(s_list[i]) + a) % 10
                s_list[i] = str(new_digit)

            
            added_s = ''.join(s_list)

            if added_s not in visited:
                visited.add(added_s)
                q.append(added_s)

            
            rotated_s = cur_s[-b:] + cur_s[:-b]

            if rotated_s not in visited:
                visited.add(rotated_s)
                q.append(rotated_s)
            
        
        return ans

    

'''
裴蜀定理：
对于任意整数 a 和 b，它们的线性组合 ax + by 可以表示为 d 的倍数，其中 d 是 a 和 b 的最大公约数。
换句话说，存在整数 x 和 y 使得 ax + by = d。
'''
# 枚举可能成为最小下标的轮转位置

class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        s = list(map(int, s))
        n = len(s)
        step = gcd(b, n) # 可以轮转到最左边的一定是step的倍数
        g = gcd(a, 10)
        ans = [inf]
        def modify(start: int) -> None:
            ch = t[start]  # 最靠前的数字，越小越好
            # ch 可以变成的最小值为 ch%g
            # 例如 ch=5，g=2，那么 ch+2+2+2（模 10）后变成 1，不可能变得更小
            # 从 ch 到 ch%g，需要增加 inc（循环中会 %10 保证结果在 [0,9] 中）
            inc = ch % g - ch
            if inc:  # 优化：inc 为 0 时，t[j] 不变，无需执行 for 循环
                for j in range(start, n, 2):
                    t[j] = (t[j] + inc) % 10
        for i in range(0, n, step):      
            t = s[i:] + s[:i]  # 轮转
            modify(1)  # 累加操作（所有奇数下标）
            if step % 2:  # 能对偶数下标执行累加操作
                modify(0)  # 累加操作（所有偶数下标）
            ans = min(ans, t)
        return ''.join(map(str, ans))


