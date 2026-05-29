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
    vll a(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    ll gc=0;
    for(int i=1;i<n;i+=1)
        gc=gcd(gc,a[i]-a[0]);
    ll po=0;
    while(gc>0&&gc%2==0){
        po+=1;
        gc/=2;
    }
    cout<<(1ll<<(po+1));
    nl;
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