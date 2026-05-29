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
        int k;
        vector<vector<int>> adj(n,vector<int>{});
        for(int i=0;i<m;i+=1){
            cin>>k;
            set<int> a;int w;
            for(int j=0;j<k;j+=1)
                cin>>w,a.insert(w);
            for(int j=0;j<k;j+=1){

            }
        }
    }
    return 0;
}