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
        int n,m,k;
        cin>>n>>m>>k;
        char c;
        vi a(n+2);
        a[0]=1;
        a[n+1]=1;
        for(int i=1;i<=n;i+=1){
            cin>>c;
            switch(c){
            case 'W':a[i]=0;
                    break;
            case 'C':a[i]=-1;
                    break;
            case 'L':a[i]=1;
                    break;
            };
        }
        vi b(n+2,0);
        b[0]=1;
        vi st(n+2,0);
        for(int i=1;i<=n+1;i+=1){
            if(a[i]==-1)    b[i]=0;
            else{
                bool croc=false;
                for(int j=1;j<=i&& j<=m;j+=1){
                    if(a[i-j]==-1){
                        croc=true;
                    }
                    else if(b[i-j]==1){
                        if(a[i-j]==0 && croc==false && j+st[i-j]<=k){
                            b[i]=1;
                            if(st[i]!=0)   st[i]=min(st[i],st[i-j]+j);
                            else st[i]=st[i-j]+j;
                            
                        }
                        else if(a[i-j]==1){
                            if(j<=m){
                                b[i]=1;
                                st[i]=st[i-j];
                                break;
                            }
                            else if(croc==false && j+st[i-j]<=k){
                                b[i]=1;
                                if(st[i]!=0)    st[i]=min(st[i],st[i-j]+j);
                                else st[i]=st[i-j]+j;
                            }
                        }
                    }
                }
            }
        }
        cout<<(b[n+1]?"YES":"NO")<<"\n";
    }
    return 0;
}