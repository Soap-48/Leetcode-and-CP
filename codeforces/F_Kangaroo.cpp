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
    int a,b;
    cin>>a>>b;
    int t=1;
    for(int i=0;i<a;i+=1){
        for(int j=0;j<b;j+=1){
            cout<<i+t*j<<' ';
            t+=1;
        }
    }
    nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}