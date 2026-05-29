#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
using namespace std;
vector<string> vs;


void solve(unordered_map<char,int> q,string z){
    bool flag=false;
    for(char u='a';u<='z';u++)
    {
        if(q[u]!=0){
            q[u]--;
            solve(q,z+u);
            flag=true;
            q[u]++;
        }
    }
    if(flag==false) vs.pb(z);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    unordered_map<char,int> a;
    for(char p='a';p<='z';p++)
         a[p]=0;
    for(auto &r:s)
        a[r]++;
    string t;
    solve(a,t);
        cout<<vs.size()<<'\n';
    for(string &m:vs)
        cout<<m<<'\n';
    return 0;
}