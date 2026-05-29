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
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    ll ans=1;
    set<int> e,f;
    f.insert(a[0]);
    for(int i=1;i<n;i+=1){
        e.insert(a[i]);
        auto it=f.find(a[i]);
        if(it!=f.end()) f.erase(it);
        if(f.empty()){
            ans+=1;
            f=e;
            set<int> temp;
            e=temp;
        }
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