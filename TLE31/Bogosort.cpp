#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.rbegin(),a.rend());
        for(auto k:a) cout<<k<<' ';
        cout<<"\n";
    }
    return 0;
}