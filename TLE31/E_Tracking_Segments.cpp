// #include <bits/stdc++.h>

// using ll=long long;
// #define vi vector<int>
// #define vll vector<ll>
// #define all(v) (v).begin(),(v).end()
// #define rall(v) (v).rbegin(),(v).rend()
// #define nl cout<<'\n'
// const int MOD = 1000000007;
// using namespace std;

// void solve(){
//     int n,m;
//     cin>>n>>m;
//     vi re(m);
//     vector<vi> p(n+1);
//     int l,r;
//     for(int i=0;i<m;i+=1){
//         cin>>l>>r;
//         for(int j=l;j<=r;j+=1)
//             p[j].push_back(i);
//         re[i]=1+((r-l+1)/2);
//     }
//     int q,i=0,j;
//     cin>>q;
//     for(;i<q;){
//         i+=1;
//         cin>>j;
//         bool flag=false;
//             for(auto k:p[j]){
//                 re[k]-=1;
//                 if(re[k]==0){
//                     flag=true;
//                     break;
//                 }
//             }
//             if(flag)    break;
//     }
//     if(i==q)    cout<<-1;
//     else{
//         cout<<i+1;
//         for(;i<q;i+=1)
//             cin>>n;
//     }
//     nl;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin>>t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }

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
    int n,m;
    cin>>n>>m;
    set<pair<int,int>> seg;
    int l,r;
    for(int i=0;i<m;i+=1){
        cin>>l>>r;
        seg.insert({l,r});
    }
    int q;cin>>q;vi qu(q);
    for(int i=0;i<q;i+=1){
        cin>>qu[i];
    }
    int ans=-1;
    l=0,r=q+1;
    while(r-l>1){
        int mid=(l+r)/2;
        bool flag=false;
        vi a(n+1,0);
        for(int i=0;i<mid;i+=1)
            a[qu[i]]=1;
        for(int i=1;i<=n;i+=1)
            a[i]+=a[i-1];
        for(auto &[i,j]:seg){
            int req=((j-i+1)/2);
            if(a[j]-a[i-1]>req){
                ans=mid;
                flag=true;
                break;
            }
        }
        if(flag)    r=mid;
        else l=mid;
    }
    cout<<ans;nl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr);int t;cin>>t;while(t--){solve();}return 0;
}