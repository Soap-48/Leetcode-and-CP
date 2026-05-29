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
    ll x,y,k;
    cin>>x>>y>>k; 
    if(y==1){
        cout<<"-1";nl;return;
    } 
    if(k<y) {
        cout<<k;nl;return;
    }
    ll pos=k;
    for(int i=0;i<x;i+=1){
        pos+=((pos-1)/(y-1));
        if(pos<y) break;
        //cerr<<i+1<<"|"<<pos<<"\n";
        if(pos>(ll)1e12){
            cout<<"-1\n";
            return;
        }
    }
    if(pos>0){
        cout<<pos;
    }
    else{
        cout<<"-1";
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