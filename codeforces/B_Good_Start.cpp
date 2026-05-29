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
    int w,h,x,y;
    cin>>w>>h>>x>>y;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int val=max(a,c)-min(a,c)-x;
    if(val<x){
        cout<<"No\n";
        return;
    }
    val=max(b,d)-min(b,d)-y;
    if(val<y){
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
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