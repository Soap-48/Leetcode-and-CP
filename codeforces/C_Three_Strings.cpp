#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const int MOD = 1000000007;
using namespace std;

int lcs(string a,string b,vi &lc){
    vector<vi> dp(a.length()+1,vi(b.length()+1,0));
    for(int i=1;i<=a.length();i+=1){
        for(int j=1;j<=b.length();j+=1){
            if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    int i=a.length(),j=b.length();
    while(i>0&&j>0){
        if(a[i-1]==b[j-1]){
            lc.push_back(j-1);
            i-=1;j-=1;
        }
        else if(dp[i][j]==dp[i][j-1])
            j-=1;
        else
            i-=1;
    }
    reverse(all(lc));
    return dp[a.length()][b.length()];
}

// int count(string a,string c,vi lc){
//     int i=0,j=0,it=0;
//     int count=0;
//     for(int p=0;p<c.size();p+=1){
//         if(lc[it]==p){
//             it+=1;
//         }
//         else
//     }
// }

void solve(){
    //cout<<"-----------------------";nl;
    string a,b,c;
    cin>>a>>b>>c;
    vi lcs1,lcs2;
    int l=lcs(a,c,lcs1),r=lcs(b,c,lcs2);

    // for(auto i:lcs1)
    //     cout<<i<<' ';
    // nl;
    // for(auto i:lcs2)
    //     cout<<i<<' ';
    // nl;
    nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}