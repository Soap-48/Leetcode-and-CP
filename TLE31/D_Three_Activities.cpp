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
    vector<pair<int,int>> a(n),b(n),c(n);
    for(int i=0;i<n;i+=1){
        cin>>a[i].first;
        a[i].second=i;
    }
    for(int i=0;i<n;i+=1){
        cin>>b[i].first;
        b[i].second=i;
    }
    for(int i=0;i<n;i+=1){
        cin>>c[i].first;
        c[i].second=i;
    }
    sort(rall(a));sort(rall(b));sort(rall(c));
    int ans=0;
    for(int i=0;i<3;i+=1){
        for(int j=0;j<3;j+=1){
            for(int k=0;k<3;k+=1){
                if(a[i].second!=b[j].second&&b[j].second!=c[k].second&&a[i].second!=c[k].second)
                    ans=max(ans,a[i].first+b[j].first+c[k].first);
            }
        }
    }
    cout<<ans;
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