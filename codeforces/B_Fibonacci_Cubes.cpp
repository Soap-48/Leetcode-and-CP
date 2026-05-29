#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const int MOD = 1000000007;
using namespace std;

int fib[]={1,2,3,5,8,13,21,34,55,89};

void solve(){
    int n,m;
    cin>>n>>m;
    int a,b,c;
    for(int i=0;i<m;i+=1){
        cin>>a>>b>>c;
        if(max({a,b,c})>=fib[n-1]+fib[n-2]&&min({a,b,c})>=fib[n-1])
            cout<<"1";
        else cout<<0;
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