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
    int n,q;string s;
    cin>>n>>q;
    cin>>s;
    set<int> ba,bc,ca,cb;
    char u,v;
    for(int i=1;i<=q;i+=1){
        cin>>u>>v;
        if(u=='b'){
            if(v=='a') ba.insert(ba.end(),i);
            else if(v=='c') bc.insert(bc.end(),i);
        }
        else if(u=='c'){
            if(v=='a')  ca.insert(ca.end(),i);
            else if(v=='b') cb.insert(cb.end(),i);
        }
    }
    for(auto &c:s){
        if(c=='b'){
            if(!ba.empty()){
                ba.erase(ba.begin());
                c='a';
            }
            else if(!bc.empty()&&!ca.empty()){
                auto it=ca.lower_bound(*bc.begin());
                if(it!=ca.end()){
                    ca.erase(it);bc.erase(bc.begin());
                    c='a';
                }
            }
        }
        else if(c=='c'){
            if(!ca.empty()){
                ca.erase(ca.begin());
                c='a';
            }
            else if(!cb.empty()){
                c='b';
                auto it=ba.lower_bound(*cb.begin());
                if(it!=ba.end()){
                    ba.erase(it);
                    c='a';
                }
                cb.erase(cb.begin());
            }
        }
    }
    cout<<s;nl;
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