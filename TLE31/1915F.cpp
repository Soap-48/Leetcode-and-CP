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
        vector<pair<int,int>> a(n);
        vi b(n);
        for(int i=0;i<n;i+=1){
            cin>>a[i].first>>a[i].second;
            b[i]=a[i].second;
        }
        if(n==1){
            cout<<"0\n";
            continue;
        }
        sort(all(a));
        sort(all(b));
        ll ans=0;
        for(int i=0;i<n;i+=1){
            auto it=lower_bound(all(b),a[i].second);
            ans+=it-b.begin();
            b.erase(it);
        }
        cout<<ans<<"\n";
    }
    return 0;
}