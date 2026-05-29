#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const int MOD = 1000000007;
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vi a(n);map<int,int> f;
    for(int i=0;i<n ;i+=1){
        cin>>a[i];
        f[a[i]]+=1;
    }
    if(n%k!=0)  {
        cout<<"0\n";return;
    }
    map<int,int> g;
    for(auto &[i,j]:f){
        if(j%k!=0)  {
            cout<<"0\n";return;
        }
        g[i]=j/k;
    }
    int i=0,j=0;ll ans=0;
    while(j<n){
        g[a[j]]-=1;
        if(g[a[j]]<0){
            while(i<=j&&g[a[j]]<0){
                g[a[i]]+=1;
                i+=1;
            }
        }
        ans+=(j-i+1);
        j+=1;
    }
    cout<<ans;nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}