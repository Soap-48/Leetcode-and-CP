#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const int MOD = 1000000007;
using namespace std;

bool check(ll a){
    for(int i=2;i*i<=a;i+=1){
        if(a%i==0)  return false;
    }
    return true;
}

int main() {
    ll cnt=0;
    ll n=1e16;
    for(int i=1;i<=n;i+=1){
        if(check(i)){
            cout<<i<<' ';
        }
    }
    nl;
    cout<<cnt;
    return 0;
}