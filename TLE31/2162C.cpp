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
        int a,b;
        cin>>a>>b;
        int c=a^b;
        if(a==b){
            cout<<"0\n";
        }
        else{
            int msb=(31-__builtin_clz(c));
            if((1<<msb)>a){
                cout<<"-1\n";
            }
            else{
                cout<<__builtin_popcount(c)<<"\n";
                for(int i=0;i<=msb;i+=1){
                    if(c&(1<<i)){
                        cout<<(1<<i)<<" ";
                    }
                }
                cout<<"\n";
            }
        }
    }
    return 0;
}