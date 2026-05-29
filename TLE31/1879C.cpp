

#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
using namespace std;

ll fact(int x){
    ll ans=1;
    for(ll i=1;i<=x;i++){
        ans=(ans*i);
        ans=ans%998244353ll;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
      //  cout<<s<<'|';
        ll c=0,n=s.size();
        ll bc=1;
        ll hehe[2]={1,0};
        ll curr=1,last=s[0]-'0';
        ll mulcount=1,lc=0;
        for(;curr<n;curr++){
            if((s[curr]-'0')!=last){
                last=hehe[last];
               // cout<<last<<'|';
                if(lc!=0){
                    c=c+(lc);
                    mulcount=mulcount*(lc+1);
                    mulcount=mulcount%998244353;
                    lc=0;
                }
            }
            else{
                lc++;
            }
        }
        if(lc!=0){
            c=c+(lc);
            mulcount=mulcount*(lc+1);
            mulcount=mulcount%998244353;
        }
        bc=fact(c);
        bc=bc%998244353;
        if(mulcount==0) mulcount=1;
        bc=bc*(mulcount);
        cout<<c<<' '<<(bc%998244353)<<'\n';
    }
    return 0;
}

/*
Falltu ka probablity mei galti kar raha tha. Product ke jagah sum 
le raha tha. waise simple hai kisi bhi do same (1 ya 0) ke bich ke 
n numbers me se n-1 eliminate karne hai to count mei n-1 hatnege.
 Number of ways to choose this number is (nCn-1). inte tareko se 
 inka set bansakta hai, multiply karke total sets bananene ka terka
  milega. Phir total jitne hatenge unke factorial se multiply karna 
  padega.
  */