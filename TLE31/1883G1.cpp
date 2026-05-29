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
        int n,m;
        cin>>n>>m;
        vi  a(n),b(n);
        a[0]=1;
        for(int i=1;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        sort(all(a));sort(all(b));
        int i=0,ans=0;
        while(i<a.size()&&i>=0){
            if(a[i]>=b[i]){
                a.erase(a.end()-1);
                b.erase(b.begin());
                ans++;;
            }
            else{
                ++i;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}