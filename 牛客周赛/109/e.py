import sys
from collections import defaultdict


n = int(input())
st = set(tuple(map(int, input().split())) for _ in range(n))

mpx = defaultdict(int)
mpy = defaultdict(int)

sub = 0
ans = 0
for x, y in st:
    if (x,y + 1) in st:
        mpy[y] += 1

    if (x + 1,y) in st:
        mpx[x] += 1


    if (x + 1, y) in st and (x, y + 1) in st and (x + 1, y + 1) in st:
        sub += 1

for key,val in mpx.items():
    ans = ans + val * (val - 1) // 2


for key,val in mpy.items():
    ans = ans + val * (val - 1) // 2

ans -= sub
print(ans)

    