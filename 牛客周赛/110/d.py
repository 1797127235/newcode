import sys
input = sys.stdin.readline

res=[]
def main():
    n = int(input())
    a = [0]+list(map(int, input().split()))
    if n == 2:
        res.append(0)
        return
    a.sort()
    s = [0] * (n + 1)
    ans = 10**18
    pos = (n + 1) //2
    for i in range(1, n + 1):
        s[i] = s[i - 1] + a[i]

    for i in range(1,n + 1):
        p = pos
        if n % 2:
            if i >= pos: p-=1
        else:
            if i <=pos: p+=1

        now = 0

        if i <=p:
            now += (p - 1) * a[p] - (s[p] - a[i])
            now += (s[n] - s[p]) - (n - p) * a[p]
        else:
            now += p * a[p] - s[p]
            now += (s[n] - s[p] - a[i]) - (n - p - 1) * a[p]
        ans = min(ans, now)

    res.append(ans)

    
    

if __name__ == '__main__':
    T = 1
    T=int(input())  # 如果有多组数据，取消注释此行
    for _ in range(T):
        main()
    print(*res, sep='\n')