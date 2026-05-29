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
    ll a,b,c;
    cin>>a>>b>>c;
    if(a+1!=c){
        cout<<"-1\n";
    }
    else{
        ll child=1,h=-1;
        while(a||b||c){
            h+=1;
            ll nxt=0;
            if(a){
                ll k=min(a,child);
                a-=k;child-=k;nxt+=2*k;
            }
            if(child&&b){
                ll k=min(child,b);
                b-=k;child-=k;nxt+=k;
            }
            if(child&&c){
                ll k=min(child,c);
                c-=k;child-=k;
            }
            child=nxt;
        }
        cout<<h;nl;
    }
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