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
        int n,c;
        cin>>n>>c;
        vector<unsigned int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            a[i]=a[i]+i+1;
        }
        sort(all(a));
        unsigned ans=0;
        for(int i=0;i<n;i++){
            if(c>=a[i]){
                ans++;
                c=c-a[i];
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}