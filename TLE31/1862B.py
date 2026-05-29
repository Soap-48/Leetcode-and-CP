t=int(input())
while t>0:
    t-=1
    n=int(input())
    a=list(map(int,input().split()))
    b=[]
    b.append(a[0])
    last=a[0]
    for i in range(1,n):
        b.append(a[i])
        if a[i]<last:
            b.append(a[i])
        last=a[i]
    print(len(b))
    [print(x,end=' ') for x in b]
    print()