from typing import List
import heapq
class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        n = len(events)
        mx = max(e[1] for e in events)
        g = [[] for _ in range(mx + 1)]

        #按开始时间分组
        for e in events:
            g[e[0]].append(e[1])

        ans = 0
        h = []
        for day in range(1,mx + 1):
            while h and h[0] < day:
                heapq.heappop(h)


            for end in g[day]:
                heapq.heappush(h, end)

            if h:
                heapq.heappop(h)
                ans += 1
        return ans