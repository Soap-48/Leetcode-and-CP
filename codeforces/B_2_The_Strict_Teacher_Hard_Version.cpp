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
        int n,m,q;
        cin>>n>>m>>q;
        vi t(m);
        for(int i=0;i<m;i+=1)
            cin>>t[i],t[i]-=1;
        sort(all(t));
        vi a(q),ans(q);
        for(int i=0;i<q;i+=1)
            cin>>a[i],a[i]-=1;
        for(int i=0;i<q;i+=1){
            auto it=lower_bound(all(t),a[i]);
            if(it==t.begin())
                ans[i]=t[0];
            else if(it==t.end())
                ans[i]=(n-1)-t[m-1];
            else    
                ans[i]=(((*it)-(*(it-1)))/2);
        }
        for(int i=0;i<q;i+=1)
            cout<<ans[i]<<"\n";
    }
    return 0;
}