t=int(input())
while t>0:
    t-=1
    n=int(input())
    ans=sum(list(map(int,input().split())))
    if ans%2==0:
        print("YES")
    else:
        print("NO")