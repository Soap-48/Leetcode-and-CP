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
    string val="1100";
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int q;
        cin>>q;
        int i,j;
        bool last=false;
        int pos=-1;
        if(s.find(val)!=string::npos)   {last=true;pos=s.find(val);}
        while(q--){
            cin>>i>>j;
            if(j==1){   
                s[i-1]='1';
            }
            else{
                s[i-1]='0';
            }
            if(last==true&&(i<pos+1||i>pos+4)){
                cout<<"YES\n";
            }
            else{
                if(j==1){
                    if(i+2<s.length()&&s[i-1]=='1'&&s[i]=='1'&&s[i+1]=='0'&&s[i+2]=='0'){
                        cout<<"YES\n";
                        last=true;
                        pos=i-1;
                    }
                    else if(i+1<s.length()&&i>=2&&s[i-2]=='1'&&s[i-1]=='1'&&s[i]=='0'&&s[i+1]=='0'){
                        cout<<"YES\n";
                        last=true;
                        pos=i-2;
                    }
                    else{
                        cout<<"NO\n";
                        last=false;
                    }
                }
                else{
                    if(i<s.length()&&i>=3&&s[i-3]=='1'&&s[i-2]=='1'&&s[i-1]=='0'&&s[i]=='0'){
                        cout<<"YES\n";
                        last=true;
                        pos=i-3;
                    }
                    else if(i>=4&&s[i-4]=='1'&&s[i-3]=='1'&&s[i-2]=='0'&&s[i-1]=='0'){
                        cout<<"YES\n";
                        last=true;
                        pos=i-4;
                    }
                    else{
                        cout<<"NO\n";
                        last=false;
                    }
                }
            }
        }
    }
    return 0;
}