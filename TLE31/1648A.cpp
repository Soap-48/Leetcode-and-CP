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
        int n,m,c;
        cin>>n>>m;
        vector<vi> cx(10e5),cy(10e5);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c;
                c-=1;
                cx[c].push_back(i);cy[c].push_back(j);
            }
        }
        for(auto &i:cx) sort(all(i));
        for(auto &i:cy) sort(all(i));
        ll ans=0,sum,counter;
        for(auto p:cx){ 
            counter=0;sum=0;
            for(auto k:p){
                counter++;
                sum+=k;
                ans+=(counter*k-sum);
            }
        }
        for(auto p:cy){ 
            sum=0;counter=0;
            for(auto k:p){
                counter++;
                sum+=k;
                ans+=(counter*k-sum);
            }
        }
        cout<<ans<<"\n";
    return 0;
}