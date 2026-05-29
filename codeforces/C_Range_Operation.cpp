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
    vi a(n),b(n);ll val=0;
    for(int i=0;i<n;i+=1){
        cin>>a[i];
        b[i]=(2*(i+1))-a[i];
    }
    ll ans=0,sum=0;
    for(int i=0;i<n;i+=1){
        sum+=b[i];
        if(sum<0){
            sum=0;
        }
        val+=a[i];
        ans=max(ans,sum);
    }
    cout<<val+ans;nl;
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