#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const int MOD = 1000000007;
const int inf=1e9+1;
using namespace std;

void solve(){
    ll n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    vector<int> d(n,inf);
    for(int i=0;i<n;i+=1){
        int j=upper_bound(all(d),a[i])-d.begin();
      //  cerr<<i<<" : "<<j<<endl;
        if(j<n){
            if(j==0||(a[i]>d[j-1]))
                d[j]=a[i];
        }
    }
    for(int i=n-1;i>=0;i-=1)
        if(d[i]!=inf){
            cout<<i+1;
            return;
        }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}