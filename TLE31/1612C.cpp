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
    while(t--){
        ll k,x;
        cin>>k>>x;
        if(x>=k*k){
            cout<<2*k-1<<"\n";
        }
        else{
            bool flag=false;
            if(x>(k*(k+1)/2)){
                x=x-(k*(k+1)/2);
                x=(k*(k-1)/2)-x;
                flag=true;
            }
                ll l=1,r=k,curr=(k+1)/2,var;
                while(l<=r){
                    var=(curr)*(curr+1)/2;
                    if(x>var){
                        l=curr+1;
                    }
                    else if(x<var){
                        r=curr-1;
                    }
                    else{
                        break;
                    }
                    curr=(l+r)/2;
                    if(curr>k||curr<1) break;
                }
                if(flag==false){
                    if(x!=var)  curr++;
                }
            if(flag){
                ll ans=(k-1)+(k-curr);
                cout<<ans<<"\n";
            }
            else{
                cout<<curr<<"\n";
            }
            
        }
    }
    return 0;
}