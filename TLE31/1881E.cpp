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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi a(n);
        for(int i=0;i<n;i+=1)
            cin>>a[i];
        vi ans(n+1);
        ans[n]=0;
        for(int i=n-1;i>=0;i-=1){
            ans[i]=min(ans[i+1]+1,((i+a[i]+1<=n)?ans[i+a[i]+1]:INT_MAX));
        }
        cout<<ans[0]<<"\n";
    }
    return 0;
}