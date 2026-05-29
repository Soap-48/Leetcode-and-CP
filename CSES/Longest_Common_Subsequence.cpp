#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const int MOD = 1000000007;
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i+=1)
        cin>>a[i];
    for(int i=0;i<m;i+=1)
        cin>>b[i];    
    vector<vi> dp(n+1,vi(m+1,0));
    for(int i=1;i<=n;i+=1)
        for(int j=1;j<=m;j+=1)
            if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    int x=n,y=m;
    vector<int> ans;
    while(x>0&&y>0){
        if(a[x-1]==b[y-1]){
            x-=1;y-=1;
            ans.push_back(a[x]);
        }
        else if(dp[x][y]==dp[x-1][y])
            x-=1;
        else
            y-=1;
    }
    reverse(all(ans));
    cout<<ans.size();
    nl;
    for(int &i:ans)
        cout<<i<<' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}

//this is such a standard that i didnt even need to 
//think but i am fired up now