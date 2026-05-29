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
        vi a(n);
        char c;
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>c;
            if(c=='(') a[i]=1;
            else a[i]=-1;
            sum+=a[i];
        }
        if(n%2==1||sum!=0){
            cout<<"-1\n";
        }
        else{
            int d=0;
            bool flag=true;
            vi ans(n+1,0);
            ans[n]=1;
            for(int i=0;i<n;++i){
                d+=a[i];
                if(flag){
                    if(d>=0){
                        ans[i]=(1);
                    }
                    else{
                        d=-1;
                        ans[i]=(2);
                        flag=false;
                        ans[n]=2;
                    }
                }
                else{
                    if(d<=0){
                        ans[i]=(2);
                    }
                    else{
                        d=1;
                        ans[i]=(1);
                        flag=true;
                    }
                }
            }
            if(ans[0]==2){
                bool flag=true;
                for(int i=0;i<n;++i)   {if(ans[i]==1) flag=false;
                    ans[i]=3-ans[i];
                }
                if(flag){
                    ans[n]=1;
                }
            }
            cout<<ans[n]<<"\n";
            for(int i=0;i<n;++i)
                cout<<ans[i]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}