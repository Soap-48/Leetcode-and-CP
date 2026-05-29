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
        int val;
        bool flag=false;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;++j){
                cout<<i<<" "<<j<<endl;
                cin>>val;
                if(val==1){
                    flag=true;
                    break;
                }
                else if(val==-1)    return 99;
            }
                            if(flag)    break;

        }
        cout<<endl;
    }
    return 0;
}