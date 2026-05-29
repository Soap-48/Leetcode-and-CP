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
    int n,q;
    cin>>n>>q;
    vector<ll> a(n+1),c(n+1,`);
    a[0]=0;
    for(int i=1;i<=n;i+=1)
        cin>>a[i];
    int l,r;
    for(int i=0;i<q;i+=1){
        cin>>l>>r;
        c[l]+=1;
        if(r<n) c[r+1]-=1;
    }
    for(int i=1;i<=n;i+=1)
        c[i]+=c[i-1];
    sort(rall(a));sort(rall(c));
    ll ans=0;
    for(int i=0;i<n&&c[i]>0;i+=1)
        ans+=(a[i]*c[i]);
    cout<<ans<<"\n";
    return 0;
}