#pragma GCC optimize("O0")
#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
using namespace std;

int dummy=INT_MIN;

int height(vector<vector<int>> &mp,vi &wb,vi &balance,int x){
        int g=wb[x];
        for(auto &i:mp[x]){
            g+=height(mp,wb,balance,i);
        }
        balance[x]=g;
        return g;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> mp(n);
        vi wb(n),balance(n,dummy);
        int temp;
        for(int i=1;i<n;i++){
            cin>>temp;
            mp[temp-1].push_back(i);
        }
        char ch;
        for(int i=0;i<n;i++){
            cin>>ch;
            wb[i]=((ch=='W')?1:-1);
        }
        int c=0;
        height(mp,wb,balance,0);
        for(int i=0;i<n;i++){
          //  if(balance[i]==INT_MIN) height(mp,wb,balance,i);
            if(balance[i]==0)   c+=1;
        }        
        cout<<c<<"\n";
    }
    return 0;
}