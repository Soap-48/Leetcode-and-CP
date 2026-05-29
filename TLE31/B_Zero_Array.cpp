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
    ll sum=0;
    ll k;ll mx=0;
    for(int i=0;i<n;i+=1){
        cin>>k;
        sum+=k;
        mx=max(mx,k);
    }
    if(sum&1||(mx)>sum-mx)   cout<<"NO\n";
    else    cout<<"YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}