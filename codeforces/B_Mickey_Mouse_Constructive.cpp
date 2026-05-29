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
    int x,y;
    cin>>x>>y;
    int cnt=0;
    int tot=abs(x-y);
    for(int i=1;i*i<=tot;i+=1){
        if(tot%i==0){
            cnt+=2;
            if(i*i==tot)    cnt-=1;
        }
    }
    if(cnt==0)  cnt=1;
    cout<<cnt;nl;
    for(int i=0;i<x;i+=1)
        cout<<"1 ";
    for(int i=0;i<y;i+=1)
        cout<<"-1 ";
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