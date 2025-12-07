n, m = map(int, input().split())
a, b = min(n, m), max(n, m)
#看小的

if a == 1:
    print(1)
elif a == 2:
    print((b + 1) // 2)
elif a == 3:
    if b == 3:
        print(8)
    else:
        print(3 * b)
else:
    print(n * m)
