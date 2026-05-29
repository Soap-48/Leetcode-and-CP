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
    ll q=(a[0]*2-a[1])/(n+1);
    ll p=q+a[1]-a[0];
    if(p<0||q<0){
        cout<<"NO\n";
        return;
    }
    for(int i=1;i<=n;i+=1){
        if(a[i-1]!=(p*i+q*(n-i+1))){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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