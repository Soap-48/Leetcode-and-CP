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
    int n,q;
    cin>>n>>q;
    vector<vector<int>> sp(30,vector<int>(n+1,-1));
    for(int i=1;i<=n;i+=1)
        cin>>sp[0][i];
    for(int i=1;i<=29;i+=1)
        for(int j=1;j<=n;j+=1)
            sp[i][j]=sp[i-1][sp[i-1][j]];
    int x,k;
    for(int i=0;i<q;i+=1){
        cin>>x>>k;
        int ans=x;
        int p=0;
        while(k>0){
            if(k&1)
                ans=sp[p][ans];
            k=k>>1;
            p+=1;
        }
        cout<<ans;
        nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}