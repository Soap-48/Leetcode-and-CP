#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const int MOD = 1000000007;
using namespace std;

ll bestcost(ll x,ll k){
    vll dp(x+1,0);
    vll f,c;
    ll t=x;
    for(int i=2;i*i<=x;i+=1){
        if(t%i==0){
            f.push_back(i);
            c.push_back(1);
            t=t/i;
            while(t%i==0){
                t=t/i;
                c.back()+=1;
            }
        }
        if(i*i!=x){
            ll j=x/i;
            if(t%j==0){
                f.push_back(j);
                c.push_back(1);
                t=t/j;
                while(t%j==0){
                    t=t/j;
                    c.back()+=1;
                }
            }
        }
    }
    map<ll,pair<ll,vll>> m;
    m[1]={0,c};
    queue<int> q;q.push(1);
    while(!q.empty()){
        int i=q.front();
        q.pop();
    }
}

void solve(){
    ll x,y,k;
    cin>>x>>y>>k;
    ll d=gcd(x,y);
    x=x/d;y=y/d;
    cout<<bestcost(x,k)+bestcost(y,k);
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