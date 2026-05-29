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
        int n,k;
        cin>>n>>k;
        vector<ll> a(n);
        for(int i=0;i<n;i++)    cin>>a[i];
        int last=(1<<30);
        while((k>0)&&(last>0)){
            int need=0;
            for(int i=0;i<n;i++){
                if((a[i]&last)==0){
                    need++;
                }
            }
            if(k>=need){
                for(int i=0;i<n;i++)    a[i]=(a[i]|last);
                k=k-need;
            }
            last=last/2;
 
        }
        ll ans=a[0];
        for(auto i:a)   ans=(ans&i);
        cout<<ans<<'\n';
    }
    return 0;
}