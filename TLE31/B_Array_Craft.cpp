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
    int n,x,y;
    cin>>n>>x>>y;
    vi a(n+1,0);
    int last=-1;
    for(int i=y-1;i>0;i-=1){
        a[i]=last;
        last=-last;
    }
    last=-1;
    for(int i=x+1;i<=n;i+=1){
        a[i]=last;
        last=-last;
    }
    a[x]=1;a[y]=1;
    for(int i=1;i<=n;i+=1){
        if(a[i]==0) cout<<"1 ";
        else cout<<a[i]<<' ';
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