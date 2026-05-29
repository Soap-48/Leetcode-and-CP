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
    cout<<2*n-1<<'\n';
    for(int i=1;i<n;i+=1)
        cout<<i<<' '<<1<<' '<<i<<'\n'<<i<<' '<<i+1<<' '<<n<<'\n';
    cout<<n<<' '<<1<<' '<<n<<'\n';
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