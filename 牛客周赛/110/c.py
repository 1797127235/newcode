import sys
input = sys.stdin.readline
res=[]
def main():
    #枚举所有长为2的区间
    n = int(input())
    a = list(map(int, input().split()))

    ans = -10**9

    for i in range(n-1):
        l,r = a[i],a[i+1]
        mx = max(l,r)
        mn = min(l,r)
        if mn > 0:
            ans = max(ans, mx)
        else:
            if mx == 1:
                ans = max(ans, -1)
            else:
                ans = max(ans, mx-1)
    
    res.append(ans)



if __name__ == '__main__':
    T = 1
    T=int(input())  # 如果有多组数据，取消注释此行
    for _ in range(T):
        main()
    print(*res, sep='\n')