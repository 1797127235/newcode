mod = 17
all = 0

for x in range(1,30):
    cnt = 1
    for i in range(1,x + 1):
        cnt = (cnt * i) % mod
    all += cnt
    print(f"{x}! mod {mod} = {cnt}")
print(f"Sum of all factorials mod {mod} = {all % mod}")