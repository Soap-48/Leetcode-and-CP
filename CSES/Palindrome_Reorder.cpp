#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define all(v) (v).begin(),(v).end()
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    int c[26]={};
    int tc=s.size();
    for(char a:s){
        c[(int)(a-'A')]++;
    }
    int id=0;
    if(tc%2==0){
        for(int i=0;i<26;i++){
            if(c[i]%2!=0){
                cout<<"NO SOLUTION";
                return 0;
            }
            for(int k=c[i];k>0;k=k-2,id++){
                s[id]=s[tc-id-1]=(char)(i+(int)'A');
            }
        }
    }
    else{
        int odd=-1;
        for(int i=0;i<26;i++){
            if(c[i]%2==0){
                for(int k=c[i];k>0;k=k-2,id++){
                s[id]=s[tc-id-1]=(char)(i+(int)'A');
                }
            }
            else{
                if(odd==-1) {
                    odd=i;
                    c[i]--;
                    for(int k=c[i];k>0;k=k-2,id++){
                      s[id]=s[tc-id-1]=(char)(i+(int)'A');
                      }
                }
                else {cout<<"NO SOLUTION";return 0;}
            }
        }
        if(odd==-1) {cout<<"NO SOLUTION";return 0;}
        s[tc/2]=(char)(odd+(int)'A');
    }
    cout<<s;
    return 0;
}