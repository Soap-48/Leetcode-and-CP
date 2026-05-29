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
    if(k==(n*n-1)){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for(int i=1;i<n;i+=1){
        for(int i=1;i<=n;i+=1){
            if(k){
                cout<<'U';
                k-=1;
            }
            else{
                cout<<'D';
            }
        }
        cout<<'\n';
    }
    for(int i=1;i<n;i+=1){
        if(k){
            cout<<'L';
            k-=1;
        }
        else{
            cout<<'R';
        }
    }
    cout<<'L';
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