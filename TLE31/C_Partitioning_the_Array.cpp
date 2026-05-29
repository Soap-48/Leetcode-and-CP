#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const int MOD = 1000000007;
using namespace std;

int check(vi &a,int i,int &n){
    if(i==n)    return 1;
    int val=0;
    for(int j=i;j<n;j+=1)
        val=gcd(val,abs(a[j]-a[j-i]));
    if(val>=2||val==0)  return 1;
    else   return 0;
}

void solve(){
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    ll ans=0;
    for(int i=1;i*i<=n;i+=1){
        if(n%i==0){
            ans+=check(a,i,n);
            if(i*i!=n) ans+=check(a,n/i,n);
        }
    }
    cout<<ans<<"\n";
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