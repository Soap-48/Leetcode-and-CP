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
    vi a(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    if(n>=m)    {cout<<"YES\n";return;}
    else{
        vector<vi> pos(2,vi(m,0));
        pos[0][0]=1;
        int in=1;
        for(int i=0;i<n;i+=1){
            in=1-in;
            for(int j=0;j<m;j+=1){
                pos[1-in][j]|=pos[in][j];
                if(pos[in][j]==1){
                    int k=((j+a[i])%m);
                  //  cerr<<i<<'|'<<j<<"|"<<k<<"\n";
                    if(k==0){
                        cout<<"YES\n";
                        return;
                    }
                    pos[1-in][k]=1;
                }
            }
        }
    }
    cout<<"NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}