t=int(input())
while t>0:
    t-=1
    n=int(input())
    a=list(map(int,input().split()))
    ma=a[0]
    for k in a:
        ma=max(k,ma)
    b=[]
    c=[]
    for k in a:
        if k==ma:
            c.append(k)
        else:
            b.append(k)
    if b==[]:
        print(-1)
    else:
        print(f"{len(b)} {len(c)}")
        for k in b:
            print(k,end=' ')
        print("")
        for k in c:
            print(k,end=' ')
        print()