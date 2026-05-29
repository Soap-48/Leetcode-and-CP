#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
const int MOD = 1000000007;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        ll ans=0;
        cin>>n>>m;
        vector<vll> a(n,vll(m));
        for(int i=0;i<n;i+=1)
            for(int j=0;j<m;j+=1)
                cin>>a[i][j];
        vector<ll> sum(n,0);
        for(int i=0;i<n;i+=1){
            for(int j=0;j<m;j+=1)
                sum[i]+=a[i][j];
        }
        for(int i=0;i<n;i+=1){
            ll val=0;
            for(int j=0;j<m;j+=1)
                val+=(a[i][j]*(m-j));
            ans+=val;
        }
        sort(rall(sum));
        for(int i=0;i<n;i+=1){
            ans+=(sum[i]*(m*n-(i+1)*m));
        }
        cout<<ans<<"\n";
    }
    return 0;
}