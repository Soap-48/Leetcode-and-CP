n=int(input())
a=list(map(int,input().split()))
mi=abs(a[0])
for k in a:
    mi=min(mi,abs(k))
print(mi)