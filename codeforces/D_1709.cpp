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
    vi a(n),b(n);
    vector<string> ans;
    for(int i=0;i<n;i+=1)   cin>>a[i];
    for(int i=0;i<n;i+=1)   cin>>b[i];
    for(int i=0;i<n;i+=1){
        if(a[i]>b[i]){
            string s="3 "+to_string(i+1);
            ans.push_back(s);
            swap(a[i],b[i]);
        }
    }
    for(int i=1;i<n;i+=1){
        for(int j=0;j<n-i;j+=1){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                string s="1 "+to_string(j+1);
                ans.push_back(s);
            }
        }
    }
    for(int i=1;i<n;i+=1){
        for(int j=0;j<n-i;j+=1){
            if(b[j]>b[j+1]){
                swap(b[j],b[j+1]);
                string s="2 "+to_string(j+1);
                ans.push_back(s);
            }
        }
    }
    cout<<ans.size();nl;
    for(int i=0;i<ans.size();i+=1)
        cout<<ans[i]<<'\n';
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