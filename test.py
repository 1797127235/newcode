import sys
input = sys.stdin.readline
res= []
def main():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    ans = 2 * sum(a) - a[0] - a[1]
    res.append(ans)

if __name__ == '__main__':
    T = 1
    T=int(input())  # 如果有多组数据，取消注释此行
    for _ in range(T):
        main()
    print(*res, sep='\n') 