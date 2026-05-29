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
        int n,k;
        cin>>n>>k;
        vector<ll> a(n),b(n);
        for(int i=0;i<n;i++)    cin>>a[i];
                int uu=(n*31);
        if(k>=uu){
            cout<<((1<<31)-1);
        }
        else{
        sort(all(a),std::greater<int>());
        b=a;
        int first=-1,last=30;
        
        for(auto q:a){
            if(k<=0) break;
            int max=0;
            if(q>0) max=((int)log2(q));
           // cout<<max<<' ';   
            while((k>=n)&&(last>max)){
                ll temp=(1LL<<last);
                for(auto &i:b){
                        i=(i|temp);
               }
               k=k-n;
               last--;
             //  cout<<k<<"ONE ";
            }
            
            if((k>0)){
                if(max!=first)
                {
                ll need=0,temp=(1LL<<max);
                for(int i=0;i<n;i++){
                    if((b[i]&temp)==0){
                        need++;
                    }
                }
               // cout<<k<<' '<<need;
                if(k>=need) {
                    k=k-need;
                    for(int i=0;i<n;i++)
                        b[i]=(b[i]|temp);
                }
            }
           // cout<<"TWO ";
        }
            first=max;
        }   
        int ans=b[0];
        for(auto q:b)   ans=(ans&q);
        cout<<ans<<'\n';
    
    }
}
    return 0;
}