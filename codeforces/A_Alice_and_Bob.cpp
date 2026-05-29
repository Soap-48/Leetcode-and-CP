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
    int n,a;
    cin>>n>>a;
    int l=0,r=0,k;
    for(int i=0;i<n;i+=1){
        cin>>k;
        if(k<a) l+=1;
        else if(k>a)    r+=1;
    }
    if(l>r) cout<<a-1;
    else if(l<=r)    cout<<a+1;
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