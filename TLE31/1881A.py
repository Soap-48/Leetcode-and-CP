t=int(input())
while t>0:
    t-=1
    n,m=(input().split())
    a=input()
    b=input()
    for i in range(0,6):
        if b in a:
            print(i)
            break
        else:
            a=a+a
    else:
        print("-1")