#include <bits/stdc++.h>
using ll=long long;
#define vi vector<int>
#define all(v) (v).begin(),(v).end()
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    const long mod = 1000000007;
    cin.tie(nullptr);
    int n;
    cin>>n;
    int t=1;
    for(int i=0;i<n;i++)
        t=(t<<1)%mod;
    cout<<t;
    return 0;
}