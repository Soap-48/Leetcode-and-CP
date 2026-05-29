t=int(input())
while t>0:
    t-=1    
    a,b,c=list(map(int,input().split()))
    if c%2==0:
        a=a+c/2
        b=b+c/2
    else:
        a=a+(c+1)/2
        b=b+(c-1)/2
    if a>b:
        print("First")
    else:
        print("Second")
