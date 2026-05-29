#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    for(int k=1;k<=t;k++){
        long int n=k*k;
        long long int ans=(n*(n-1)/2)-4*(k-1)*(k-2);
        cout<<ans<<'\n';
    }
    return 0;
}