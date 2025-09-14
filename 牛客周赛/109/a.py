import sys
input = sys.stdin.readline

def main():
    x1,y1,x2,y2 = map(int, input().split())
    if x1 == 0 and x2 !=0 or x2 ==0 and x1 !=0:
        print("Yes")
    else:
        print("No")

if __name__ == '__main__':
    T = 1
    #T=int(input())  # 如果有多组数据，取消注释此行
    for _ in range(T):
        main()