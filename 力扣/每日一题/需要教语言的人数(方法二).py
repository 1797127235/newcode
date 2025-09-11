from typing import List

class Solution:
    def minimumTeachings(self, n: int, languages: List[List[int]], friendships: List[List[int]]) -> int:
        learned = list(map(set, languages))
        todo = set()

        for u,v in friendships:
            if learned[u-1].isdisjoint(learned[v-1]):
                todo.add(u - 1)
                todo.add(v - 1)
        

        cnt = [0] * (n+1)

        for u in todo:
            for x in languages[u]:
                cnt[x] += 1
        
        return  len(todo) - max(cnt)
        

