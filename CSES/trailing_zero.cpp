#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define all(v) (v).begin(),(v).end()
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin>>n;
    ll ans=0;
    ll mul=5;
    while(n>=mul){
        ans=ans+(n/mul);
        mul=mul*5;
    }
    cout<<ans;
    return 0;
}