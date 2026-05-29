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
    vi a(n),b(n);
    for(int i=0;i<n;i+=1)
    cin>>a[i];
    for(int i=0;i<n;i+=1)
    cin>>b[i];
    if(n-k+1<=k){
        map<int,int> m;
        for(int i=n-k;i<k;i+=1){
            m[a[i]]+=1;
            if(b[i]!=-1)    m[b[i]]-=1;
        }
        for(auto &[i,j]:m){
            if(j<0){
                cout<<"NO\n";
                return;
            }
        }
        for(int i=0;i<n-k;i+=1)
            if(a[i]!=b[i]&&b[i]!=-1){
                cout<<"NO\n";
                return;
            }
        for(int i=k;i<n;i+=1)
            if(a[i]!=b[i]&&b[i]!=-1){
                cout<<"NO\n";
                return;
            }
        cout<<"YES\n";
        return;
    }
    else{
        for(int i=0;i<n;i+=1)
            if(a[i]!=b[i]&&b[i]!=-1){
                cout<<"NO\n";
                return;
            }
        cout<<"YES\n";
        return;
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