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
    ll n,x;
    cin>>n>>x;
    if(x==0){
        if(n&1){
            if(n==1)    cout<<"-1";
            else    cout<<5+n-2;
        }
        else cout<<n;
        nl;return;
    }
    if(x==1){
        if(n&1){
            cout<<n;nl;
        }
        else{
            cout<<5+n-2;nl;
        }
        return;
    }
    if(n<=__builtin_popcount(x)){
        cout<<x;
    }
    else{
        ll left=n-__builtin_popcount(x);
        if(left%2==0){
           cout<<x+(left);
        }
        else{
                    cout<<x+left+1;
        }
    }
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