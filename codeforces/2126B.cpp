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
    int n,k,a;
    while(t--){
        int ans=0;
        cin>>n>>k;
        bool b=false;
        int hike=0;
        for(int i=0;i<n;i++){
            cin>>a;
            if(b==true){    b=false;}
            else if(a==1) {hike=0;}
            else if(a==0)   {
                hike++;
                if(hike==k){hike=0;ans++;b=true;}
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}