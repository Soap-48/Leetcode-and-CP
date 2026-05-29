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
    int n,m;
    cin>>n>>m;
    vi a(m);
    for(int i=0;i<m;i+=1)
        cin>>a[i];
    sort(all(a),[](int x,int y){
        if((x/100)>(y/100))
            return true;
        else
            return false;
        }
        );
    vector<pair<int,int>> ans(n);
    int i=0,j=m-1;
    int it=0;
    while(it<n){
        ans[it]={a[i],a[j]};
        if(it+1<n) ans[it+1]={a[j],a[i]};
        i+=1;j-=1;
        it+=2;
    }
    for(int i=0;i<n;i+=1){
        for(int j=0;j<3;j+=1)
            cout<<ans[i].first<<' '<<ans[i].second<<' ';
        nl;
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