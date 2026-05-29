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
            long int a,b,max,min,ans;
    while(t--){
        cin>>a>>b;
        if(b==1){

        }
        else{
            if(a>=b){
                max=a;min=b;
            }
            else{
                max=b;min=a;
            }
            if(max%min==0){
                a=log2(max/min);
                ans=a/3;
                a=a%3;
                ans+=a/2;
                a=a%2;
                ans+=a;
                cout<<ans<<'\n';
            }
            else{
                cout<<"-1\n";
            }
        }
    }
    return 0;
}