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
        string s;
        cin>>s;
        cout<<"1 "<<s.size()<<" ";
        auto i=s.find('0');
        if(i==s.npos){
            cout<<"1 1\n";
        }
        else{
            int q=1;
            i=i+1;
            for(int j=i;j<s.size() && s[j]=='0';j+=1)
                q+=1;
            int start = i-min(q,(int)i-1);
            cout<<start<<" "<<start+(s.size())-((int)i)<<"\n";
        }
        
    }
    return 0;
}