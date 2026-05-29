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
    int n,a,b;
    cin>>n>>a;
    if(a==0||a==n){
        int j=a/n;
        for(int i=0;i<n;i+=1)   cout<<j;
        nl;return;
    }
    b=n-a;
    a-=1;b-=1;
    cout<<1;
    for(int i=0;i<b;i+=1)   cout<<0;
    for(int i=0;i<a;i+=1)   cout<<1;
    cout<<0;
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