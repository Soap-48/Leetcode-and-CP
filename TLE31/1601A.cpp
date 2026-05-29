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
        int n;
        cin>>n;
        vi input(n),bits(30,0);
        for(int i=0;i<n;i++)    cin>>input[i];
        for(int i=0;i<30;i++){
            int val=(1<<i);
            for(auto k:input){
                if((k&val)!=0)  bits[i]+=1;
            }
        }
        int mi=INT_MAX;
        for(auto k:bits)
            if(k!=0&&k<mi)   mi=k;
        if(mi==INT_MAX){
            for(int i=1;i<=n;i++)   cout<<i<<" ";
            cout<<"\n";
            continue;
        }
            int cd=mi;
        for(auto k:bits)
            if(k>0)    cd=gcd(cd,k);
        
            cout<<"1 ";
        for(int i=2;i<=cd;i++)
             if(cd%i==0)    cout<<i<<" ";
        //if(cd>1) cout<<cd;
        cout<<"\n";
    }
    return 0;
}