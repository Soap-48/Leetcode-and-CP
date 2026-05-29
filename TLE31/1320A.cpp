#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    while(t--){
        int n;
        cin>>n;
        vi b(n);
        for(int i=0;i<n;i+=1)
            cin>>b[i];
        map<int,ll> anss;
        for(int i=0;i<n;i+=1){
            anss[i+1-b[i]]+=b[i];
        }
        ll ans=0;
        for(auto &[i,j]:anss)
            ans=max(ans,j);
        cout<<ans<<"\n";
    }
    return 0;
}