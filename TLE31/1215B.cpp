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

        ll n;
        cin>>n;
        vi a(n);
        for(int i=0;i<n;i+=1)
            cin>>a[i];
        vi b(n+1,0);
        for(int i=0;i<n;i+=1){
            b[i+1]=b[i];
            if(a[i]<0)  b[i+1]+=1;
        }
        ll o=0,e=0;
        for(int i=0;i<=n;i+=1)
            if(b[i]%2==0)   e+=1;
            else o+=1;
        cout<<(o*e)<<" "<<(((n*(n+1ll))/2ll)-(o*e));
    
    return 0;
}