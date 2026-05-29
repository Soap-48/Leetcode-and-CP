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
    vector<vi> a(n,vi(m));
    int maxi=0;
    for(int i=0;i<n;i+=1)
        for(int j=0;j<m;j+=1){
            cin>>a[i][j];
            maxi=max(maxi,a[i][j]);
        }
    int p=0,q=0,r=-1,s=-1;
    vi x(n,0),y(m,0);
    vector<pair<int,int>> b;
    for(int i=0;i<n;i+=1)
        for(int j=0;j<m;j+=1)
            if(a[i][j]==maxi){
                x[i]+=1;y[j]+=1;
                b.push_back({i,j});
            }   
    for(int i=0;i<n;i+=1)
            if(x[i]>1){
                r=i;break;
            }
    for(int i=0;i<m;i+=1)
            if(y[i]>1){
                s=i;
                break;
            }
    if(r==-1&&s==-1){
        if(b.size()>=3){
            cout<<maxi;
        }
        else
            cout<<maxi-1;
        nl;
        return;
    }
    if(r==-1){
        for(auto &[i,j]:b)
            if(j!=s){
                r=i;
                break;
            }
    }
    if(s==-1){
        for(auto &[i,j]:b)
            if(i!=r){
                s=j;
                break;
            }
    }
    for(auto &[i,j]:b)
            if(i!=r&&j!=s){
                cout<<maxi;nl;return;
            }
    cout<<maxi-1;nl;
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