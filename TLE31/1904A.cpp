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
        int a,b,kx,ky,qx,qy;
        cin>>a>>b>>kx>>ky>>qx>>qy;
        set<pair<int, int>> king,queen,ans;

    vector<pair<int, int>> deltas = {
        {a, b}, {a, -b}, {-a, b}, {-a, -b},
        {b, a}, {b, -a}, {-b, a}, {-b, -a}
    };

    for (auto [dx, dy] : deltas) {
        int nx = kx - dx;
        int ny = ky - dy;
            king.insert({nx, ny});
    }

    for (auto [dx, dy] : deltas) {
        int nx = qx - dx;
        int ny = qy - dy;
            queen.insert({nx, ny});
    }

    set_intersection(all(king),all(queen),inserter(ans,ans.begin()));
    cout<<ans.size()<<'\n';
    }
    return 0;
}