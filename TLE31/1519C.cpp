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
        vi uni(n);vector<ll> skill(n);
        for(int i=0;i<n;++i)
            cin>>uni[i],
            uni[i]-=1;
        for(int i=0;i<n;++i)
            cin>>skill[i];
        int m=(*max_element(all(uni)))+1;
        vector<vector<ll>> help(m);
        for(int i=0;i<n;++i)
            help[uni[i]].push_back(skill[i]);
        for(int i=0;i<m;++i)
            sort(rall(help[i]));
        for(int i=0;i<m;i++)
            for(int j=1;j<help[i].size();++j)
                help[i][j]+=help[i][j-1];
        vector<ll> ans(n+1,0);
        for(int i=0;i<m;++i)
            for(int j=1;j<=help[i].size();++j)
                ans[j]+=help[i][help[i].size()-(help[i].size()%j)-1];
        for(int i=1;i<=n;++i)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}