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
        int tc=0,cc=0;char c;
        int ans=-1;
        for(int i=0;i<n;++i){
            cin>>c;
            if(c=='#')  cc=0;
            else{
                tc++;cc++;
                if(cc>=3)   ans=2;
            }
        }
        if(ans==-1) ans=tc;
        cout<<ans<<"\n";
    }
    return 0;
}