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
        string s;
        cin>>s;
        vi ans;
        for(int i=0;i<n;i+=1)
            if(s[i]=='0'){
                ans.push_back(i+1);
            }
        cout<<ans.size()<<"\n";
        for(auto k:ans)
            cout<<k<<" ";
        cout<<"\n";
    }
    return 0;
}