class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        g = [[] for _ in range(n)]
        for u,v in edges:
            g[u].append(v)
            g[v].append(u)


        vis = [False] * n
        v,e = 0, 0
        ans = 0
        def dfs(u):
            nonlocal v,e
            vis[u] = True
            v += 1
            e += len(g[u])

            for to in g[u]:
                if not vis[to]:
                    dfs(to)

        for i in range(n):
            if not vis[i]:
                v,e = 0,0
                dfs(i)
                if e == v * (v - 1):
                    ans += 1

        return ans