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
        int n,m,k;
        cin>>n>>m>>k;
        vi a(n);
        for(int i=0;i<n;i+=1)
            cin>>a[i];
        ll ans=a[n-1]-a[0]+1;
        vi b(n-1);
        for(int i=0;i<n-1;i+=1)
            b[i]=a[i+1]-a[i]-1;
        sort(rall(b));
        for(int j=0;j<k-1;j+=1){
            ans-=b[j];
        }
        cout<<ans<<"\n";
    return 0;
}