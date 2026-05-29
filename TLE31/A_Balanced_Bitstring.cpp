#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define vll vector<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
const int MOD = 1000000007;
using namespace std;

inline int ind(char c){
    if(c=='1')   return 1;
    if(c=='0')  return 0;
    return 2;
}

void solve(){
    int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        s='0'+s;
       // cerr<<s<<"\n";
        int ch=k/2;
        int c[3]={0,0,0};
        for(int i=0;i<k;i+=1){
            c[ind(s[i])]+=1;
        }
        for(int i=k;i<s.length();i+=1){
            c[ind(s[i-k])]-=1;c[ind(s[i])]+=1;
            if(c[0]>ch||c[1]>ch){
                cout<<"NO\n";
                return;
            }
            else if(c[0]==ch){
                for(int j=0;j<k;j+=1)
                    if(s[i-j]=='?'){
                        s[i-j]='1';
                        c[1]+=1;c[2]-=1;
                    }
            }
            else if(c[1]==ch){
                for(int j=0;j<k;j+=1)
                    if(s[i-j]=='?'){
                        s[i-j]='0';
                        c[0]+=1;c[2]-=1;
                    }
            }
        }
        c[0]=0;c[1]=0;c[2]=0;
        for(int i=0;i<k;i+=1){
            c[ind(s[i])]+=1;
        }
        for(int i=k;i<s.length();i+=1){
            c[ind(s[i-k])]-=1;c[ind(i)]+=1;
            if(c[0]>ch||c[1]>ch){
                cout<<"NO\n";
                return;
            }
        }
        cout<<"YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
                            solve                   (                      );
    }
    return 0;
}