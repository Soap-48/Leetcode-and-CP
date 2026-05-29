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
    vi a(n+1,0),b(n+1,0);
    vector<pair<int,int>> c(n);
    for(int i=0;i<n;i+=1)
        cin>>c[i].first>>c[i].second;
    for(int i=0;i<n;i+=1){
        if(c[i].first==c[i].second){
            cout<<"NO\n";
            return;
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
        if(a[c[i].first]==0&&a[c[i].second]==0){
            a[c[i].first]=1;
            a[c[i].second]=1;
        }
        else if(b[c[i].first]==0&&b[c[i].second]==0){
            b[c[i].first]=1;
            b[c[i].second]=1;
        }
        else{
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    return;
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