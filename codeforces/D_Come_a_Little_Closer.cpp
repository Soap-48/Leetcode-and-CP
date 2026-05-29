#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define nl cout<<'\n'
const int MOD = 1000000007;
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> a(n),b;
    multiset<int> x,y;
    for(int i=0;i<n;i+=1){
        cin>>a[i].first>>a[i].second;
        x.insert(a[i].first);y.insert(a[i].second);
    }
    b=a;
    sort(all(a));//x sorting
    sort(all(b),[](pair<int,int> x1,pair<int,int> y1){
        if(x1.second>y1.second)   return true;
        if(x1.second<y1.second)   return false;
        return x1.first>y1.first;
    }); //y sorting
    ll ans=(a.back().first-a[0].first+1)*(b.back().second-b[0].second+1);
    if(x.count(a[0].first)==1){
        int y1=b.back().second,y2=b.back().first;
        if()
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}