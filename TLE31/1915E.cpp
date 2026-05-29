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
        vector<int> a(n);
        vector<ll> b(n);
        bool flag=true;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(flag){
                flag=false;
            }
            else{
                a[i]=-a[i];
                flag=true;
            }
        }
        b[0]=a[0];
        for(int i=1;i<n;i++)    b[i]=b[i-1]+a[i];
        sort(all(b));
        if(find(all(b),0)!=b.end()){
            cout<<"YES\n";
        }
        else{
            b.erase((unique(all(b))),b.end());
            if(b.size()==n){
                cout<<"NO\n";
            }
            else{
                cout<<"YES\n";
            }
        }
    }
    return 0;
}