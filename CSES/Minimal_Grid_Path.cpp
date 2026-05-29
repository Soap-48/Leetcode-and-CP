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
//     ll n;
//     cin>>n;
//     vector<string> s(n);
//     vector<vector<int>> vis(n,vi(n,0));
//     vis[0][0]=1;
//     for(int i=0;i<n;i+=1)
//         cin>>s[i];
//     string ans;
//     vector<pair<char,pair<int,int>>> q;
//     q.push_back({s[0][0],{0,0}});
//     int dx[]={1,0},dy[]={0,1};
//     while(!q.empty()){
//         int siz=q.size();
//         char c='Z';
//         for(auto i:q){
//             c=min(c,i.first);
//         }
//         ans+=c;
//         vector<pair<char,pair<int,int>>> q2;
//         for(int i=0;i<siz;i+=1){
//             auto j=q[i];
//             if(j.first==c){
//                 int x=j.second.first,y=j.second.second;
//                 for(int k=0;k<2;k+=1){
//                     int xx=x+dx[k],yy=y+dy[k];
//                     if(xx<n&&yy<n&&vis[xx][yy]==0){
//                         vis[xx][yy]=1;
//                         q2.push_back({s[xx][yy],{xx,yy}});
//                     }
//                 }
//             }
//         }
//         q=q2;
//     }
//     cout<<ans;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//         solve();
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
    ll n;
    cin>>n;
    vector<string> s(n);
    vector<vi> vis(n,vi(n,0));
    vis[0][0]=1;
    for(int i=0;i<n;i+=1)
        cin>>s[i];
    string ans;
    priority_queue<pair<char,pair<int,int>>,vector<pair<char,pair<int,int>>>,greater<pair<char,pair<int,int>>>> q;
    q.push({s[0][0],{0,0}});
    int dx[]={1,0},dy[]={0,1};
    while(!q.empty()){
        auto ttt=q.top();
        ans+=ttt.first;
        char c=ttt.first;
        int siz=q.size();
        priority_queue<pair<char,pair<int,int>>,vector<pair<char,pair<int,int>>>,greater<pair<char,pair<int,int>>>> q2;
        for(int i=0;i<siz;i+=1){
            auto j=q.top();
            q.pop();
            if(j.first==c){
                int x=j.second.first,y=j.second.second;
                for(int k=0;k<2;k+=1){
                    int xx=x+dx[k],yy=y+dy[k];
                    if(xx<n&&yy<n&&vis[xx][yy]==0){
                        vis[xx][yy]=1;
                        q2.push({s[xx][yy],{xx,yy}});
                    }
                }
            }
            else break;
        }
        q=q2;
    }
    cout<<ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        solve();
    return 0;
}