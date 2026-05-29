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
        int n;
        cin>>n;
        vi sheep;
        char c;
        for(int i=1;i<=n;i++){
            cin>>c;
            if(c=='*'){
                sheep.push_back(i);  
            }
        }
        if(sheep.size()<=1){cout<<"0\n";continue;}
        int median=(sheep.size()+1)/2-1;
        ll ans=0;
        for(int i=0;i<sheep.size();++i){
            if(i<=median){
                ans+=sheep[median]-sheep[i]-(median-i);
            }
            else{
                ans+=sheep[i]-sheep[median]-(i-median);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}