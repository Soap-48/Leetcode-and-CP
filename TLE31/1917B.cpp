// #include <bits/stdc++.h>

// using ll=long long;
// #define vi vector<int>
// #define pb push_back
// #define all(v) (v).begin(),(v).end()
// using namespace std;

// int c=0000000;
// unordered_set<string> a;

// void solve(string& s){
//     if(s.empty()){
//         return;
//     }
//     c++;
//     string t1=string(s.begin()+1,s.end());
//     if(!t1.empty()){
//         if(a.find(t1)==a.end()){
//         a.insert(t1);
//         solve(t1);
//         }
    
//     if((s.begin()+2)<s.end()){
//         string t2=string(s.begin()+2,s.end());
//     t2=s[0]+t2;
    
//         if(a.find(t2)==a.end()){
//             a.insert(t2);
//         solve(t2);
//     //    a.erase(a.find(t2));
//         }
//     }
//    // a.erase(a.find(t1));
// }

// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         c=0;a.erase(all(a));
//         string g;
//         int k;
//         cin>>k;
//         cin>>g;
//        // a.insert(g);
//         //cout<<k<<g<<endl;
//         solve(g);
//         set<char> yy;
//         for(auto i:g)   yy.insert(i);
//         cout<<c+yy.size()-1<<'\n';
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
    int n;string s;
    cin>>n>>s;
    long long ans=0;
    set<char> fr;{
        for(int i=1;i<=s.size();i+=1){
            fr.insert(s[i-1]);
            ans+=fr.size();
        }
    }
    cout<<ans;nl;
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