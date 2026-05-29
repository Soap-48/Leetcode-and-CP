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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        ll ans=0;
        map<char,int>        m;
        for(char c:s)
            m[c]+=1;
        for(char c='a';c<='z';c+=1){
            ans+=min(m[c],m[c-'a'+'A']);
            int more=(max(m[c],m[c-'a'+'A'])-min(m[c],m[c-'a'+'A']))/2;
            ans+=min(more,k);
            k-=min(more,k);
        }
        cout<<ans<<"\n";
    }
    return 0;
}