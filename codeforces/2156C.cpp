#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vi a(n);
        vi f(n+1,0),pre(n+1,0);
        for(int i=0;i<n;i+=1){
            cin>>a[i];
            f[a[i]]+=1;
        }
        pre[0]=0;
        for(int i=1;i<=n;i+=1){
            pre[i]=pre[i-1]+f[i];
        }
        int ans=1;
        for(int i=2;i<=n;i+=1){
            int val=n;
            if(4*i<=n) val=(pre[4*i]-f[4*i]);
            if(i<=n)    val-=f[i];
            if(2*i<=n)  val-=f[2*i];
            if(3*i<=n)  val-=f[3*i];
            if(val<=k)  ans=max(ans,i);
        }
        cout<<ans<<"\n";
    }
    return 0;
}