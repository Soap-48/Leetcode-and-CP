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
    int n,k;
    cin>>n>>k;
    vi a(n+1),f(n+1,1);
    for(int i=1;i<=n;i+=1){
        cin>>a[i];
        f[a[i]]-=1;
    }
    bool flag=true;
    vi unused;
    for(int i=1;i<=n;i+=1)
        if(f[i]<0)  flag=false;
        else if(f[i]==1)    unused.push_back(i);
    if(flag){
        for(int i=1;i<=k;i+=1)
            cout<<a[i]<<' ';
    }
    else{
        if(unused.size()==1){
            for(int i=1;i<=n;i+=1)
                if(i!=unused[0]&&i!=a[n]){
                    unused.push_back(i);
                    break;
                }
        }
        unused.push_back(a[n]);
        for(int i=0;i<k;i+=1)
            cout<<unused[i%3]<<' ';
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