t=int(input())
while t>0:
    t-=1
    n=int(input())
    a=list(map(int,input().split()))
    a1,a2,n1,n2=a[0],-1,0,-1
    for k in a:
        if k==a1:
            n1+=1
        else:
            if n2==-1:
                a2=k
                n2=1
            elif k==a2:
                n2+=1
            else:
                print("NO")
                break
    else:
        if n2==-1:
            print("YES")
        else:
            if n%2==0 and n1==n2:
                print("YES")
            elif n%2==1 and abs(n1-n2)==1:
                print("YES")
            else:
                print("NO")