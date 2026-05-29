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
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char,int> m;
    for(int i=1;i<n-1;i+=1)
        m[s[i]]+=1;
    for(auto &[i,j]:m){
        if(j>1||i==s[0]||i==s.back()){
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
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