#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1000000007;
typedef vector<ll> vi;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve(){
    int n;
    cin>>n;
    vi x(n),y(n);
    for(int i=0;i<n;i+=1){
        cin>>x[i]>>y[i];
    }
    vi c(n),k(n);
    for(int i=0;i<n;i+=1)
        cin>>c[i];
    for(int i=0;i<n;i+=1)
        cin>>k[i];
    vector<array<ll,3>> edges(n+1);
    for(int i=0;i<n;i+=1){
        edges.push_back({c[i],0,i+1});
    }
    for(int i=0;i<n;i+=1){
        for(int j=0;j<n;j+=1){
            edges.push_back({(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])),i+1,j+1});
        }
    }
    sort(all(edges));

    vi parent(n+1);
    for(int i=0;i<=n;i++) parent[i]=i;

    function<int(int)> find = [&](int v){
        return parent[v]==v ? v : parent[v]=find(parent[v]);
    };

    auto unite = [&](int a, int b){
        a = find(a);
        b = find(b);
        if(a!=b) parent[a]=b;
    };

    ll total_cost = 0;
    vi power;           // nodes connected to 0
    vector<pair<int,int>> con;   // other edges

    // Kruskal
    for(auto [w,u,v] : edges){
        if(find(u)!=find(v)){
            unite(u,v);
            total_cost += w;

            if(u==0) power.push_back(v);
            else if(v==0) power.push_back(u);
            else con.push_back({u,v});
        }
    }

    cout << total_cost << "\n"<<power.size()<<"\n";
    for(auto v: power) cout << v << " ";
    cout << "\n";

    cout << con.size() << "\n";
    for(auto [u,v]: con){
        cout << u << " " << v << "\n";
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}