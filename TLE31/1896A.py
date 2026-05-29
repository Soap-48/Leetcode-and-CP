t=int(input())
while t>0:
    t-=1
    n=int(input())
    a=list(map(int,input().split()))
    if a[0]!=1:
        print("NO")
    else:
        print("YES")