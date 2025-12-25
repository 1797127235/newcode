
res = []

def main():
    r = [int(x) for x in input().split()]
    p = [int(x) for x in input().split()]

    t = 0

    for x,y in zip(r,p):
        cnt = x + y
        if cnt == 4: continue
        if cnt > 4 : t = t + cnt -4

    res.append(t)


if __name__ == "__main__":
    main()
    for r in res:
        print(r,sep=' ')