#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
const int MOD = 1000000007;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi w(n);
        ll sum=0;
        for(int i=0;i<n;i+=1){
            cin>>w[i];sum+=w[i];
        }
        vector<pair<int,int>> deg;
        int u,v;
        vi d(n,0);
        for(int i=1;i<n;i+=1){
            cin>>u>>v;
            u-=1;v-=1;
            d[u]+=1;d[v]+=1;
        }
        for(int i=0;i<n;i+=1){
           if(d[i]>1) deg.push_back(make_pair(w[i],d[i]));
        }
        sort(rall(deg));
        cout<<sum;
        int it=0;int m=deg.size();
        for(int i=2;i<n;i+=1){
            if(it<m){
                sum+=deg[it].first;
                if(deg[it].second<=2){
                    it+=1;
                }
                else
                    deg[it].second-=1;
            }
            cout<<" "<<sum;
        }
        cout<<"\n";
    }
    return 0;
}