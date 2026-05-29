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
        vi a(n),d(k);
        ll cost=0;
        for(int i=0;i<n;i++)    {cin>>a[i];cost+=a[i];}
        for(int i=0;i<k;i++)    cin>>d[i];
        sort(a.rbegin(),a.rend());sort(all(d));
        //for(auto i:a)cout<<i<<"|";cout<<endl;for(auto i:d)cout<<i<<"|";cout<<endl;
        int j=0;
        for(auto i:d){
            j+=i;
            if(j<=n) cost-=a[j-1];
            else break;
            //cout<<a[j-1]<<" - ";
        }
        cout<<cost<<"\n";
    }
    return 0;
}