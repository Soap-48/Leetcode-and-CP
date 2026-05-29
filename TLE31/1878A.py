t=int(input())
while t>0:
    t-=1
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    if k in a:
        print("YES")
    else:
        print("NO")