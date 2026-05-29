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
        unsigned int n;
        int coins;
        cin>>n>>coins;
        vector<unsigned> a(n,1);
        vector<pair<unsigned,unsigned>> b(n),c(n);
        unsigned input;
        for(unsigned i=0;i<n;i++){
            cin>>input;
            b[i]=(pair(input+i+1,i));
            c[i]=(pair(input+n-i,i));
        }
        if(n==1){
            cout<<coins/(input+1)<<'\n';
            continue;
        }
        sort(all(b));sort(all(c));
     
        unsigned ans=0,i=1,j=0;
        
        if(coins<b[0].first){
            cout<<"0\n";
            continue;
        }
        else{
            int cost=0,i2=0,j2=0;
            if(b[0].second!=c[0].second){
                cost=b[0].first+
            }

        }
        while(i<n||j<n){
            if(b[i].first<=c[j].first){
                if(a[b[i].second]){
                coins=coins-b[i].first;
                if(coins<0) break;
                                    ans++;
                a[b[i].second]=0;
                }
                i++;
            }
            else{
                if(a[c[j].second]){
                    coins=coins-c[j].first;
                    if(coins<0) break;
                                        ans++;

                    a[c[j].second]=0;
                }
                j++;
            }
        }
        cout<<ans<<"\n";
    } 
    return 0;
}