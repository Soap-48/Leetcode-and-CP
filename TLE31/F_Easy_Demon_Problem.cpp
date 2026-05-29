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
    int n,m,q;
    cin>>n>>m>>q;
    vll a(n),b(m);
    ll sa=0,sb=0;
    for(int i=0;i<n;i+=1){
        cin>>a[i];
        sa+=a[i];
    }
    for(int i=0;i<m;i+=1){
        cin>>b[i];
        sb+=b[i];
    }
    for(int i=0;i<n;i+=1)
        a[i]=sa-a[i];
    for(int i=0;i<m;i+=1)
        b[i]=sb-b[i];
    sort(all(a));sort(all(b));
    ll x;
    for(int i=0;i<q;i+=1){
        cin>>x;
        string s="NO\n";
        ll y=(x>=0?x:-x);
        for(ll j=1;j*j<=y;j+=1){
            if(y%j==0){
                if(x>=0)   { 
                if((binary_search(all(a),j)&&binary_search(all(b),y/j))||(binary_search(all(a),y/j)&&binary_search(all(b),j))||(binary_search(all(a),-j)&&binary_search(all(b),-y/j))||(binary_search(all(a),-y/j)&&binary_search(all(b),-j))){
                    s="YES\n";
                    break;
                }
            }
                else
                    if((binary_search(all(a),-j)&&binary_search(all(b),y/j))||(binary_search(all(a),-y/j)&&binary_search(all(b),j))||(binary_search(all(a),j)&&binary_search(all(b),-y/j))||(binary_search(all(a),y/j)&&binary_search(all(b),-j))){
                    s="YES\n";
                    break;
                }
            }
        }
        cout<<s;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}