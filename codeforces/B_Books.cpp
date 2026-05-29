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
    int n,t;
    cin>>n>>t;
    vi a(n);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    vi b(n+1);
    b[0]=0;
    for(int i=1;i<=n;i+=1)
        b[i]=b[i-1]+a[i-1];
    int ans=0;
    for(int i=0;i<=n;i+=1){
        int k=t+b[i];
        auto l=(upper_bound(all(b),k));
        int j=(l-b.begin()-i-1);
        ans=max(ans,j);
    }
    cout<<ans;
    return 0;
}