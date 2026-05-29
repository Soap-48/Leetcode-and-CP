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
    string s;
    cin>>s;
    if(s.size()==1){
        cout<<"1\n";return;
    }
    if(s[0]!='<'&&s.back()!='>'){
        cout<<"-1\n";return;
    }
    ll ans=0,curr=1;char last=s[0];
    for(int i=1;i<s.size();i+=1){
        if(last=='<'){
            if(s[i]=='<')
                curr+=1;
            else if(s[i]=='>'){
                ans=max(ans,curr);
                curr=1;
            }
            else if (s[i]=='*'){
                    curr+=1;
                    if(i+1<s.size()&&s[i+1]=='>'){
                        ans=max(ans,curr);
                        curr=1;
                    }
            }
        }
            else if(last=='>'){
                if(s[i]=='>')
                    curr+=1;
                else if(s[i]=='<'){
                    cout<<"-1\n";return;
                }
                else if(s[i]=='*'){
                    cout<<"-1\n";return;
                }
            }
            else if(last=='*'){
                if(s[i]=='*'||s[i]=='<'){
                    cout<<"-1\n";return;
                }
                else{
                    curr+=1;
                }
            }
        last=s[i];
    }
    ans=max(ans,curr);
    cout<<ans;nl;
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