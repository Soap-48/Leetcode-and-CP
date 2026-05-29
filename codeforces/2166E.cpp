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
        int n,q;
        cin>>n>>q;
        vi a(n);
        for(int i=0;i<n;i+=1)
            cin>>a[i];
        sort(all(a));
        int c;
        for(int i=0;i<q;i+=1){
            cin>>c;
            vi ans(n);
            
        }
    }
    return 0;
}