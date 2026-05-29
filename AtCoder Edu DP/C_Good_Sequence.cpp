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
        int n;
        cin>>n;
    map<int,int> m;
        int t;
    for(int i=0;i<n;i+=1){
        cin>>t;
        m[t]+=1;
    }
    int ans=0;
    for(auto &[i,j]:m)
        if(j>=i)
            ans+=(j-i);
        else
            ans+=j;
    cout<<ans;
    return 0;
}