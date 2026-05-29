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
        for(int i=0;i<n;i+=1){
            cin>>a[i];
        }
        string out="YES";
        for(int i=0;i<n-2;i+=1){
            vi b;
            for(int j=0;j<3;j+=1)
                if(a[i+j]!=-1)
                    b.push_back(a[i+j]);
            if(!b.empty()){
            sort(all(b));
            b.erase(unique(all(b)),b.end());
                if(b[0]==0 or b.size()>1){
                    out="NO";
                    break;
                }
                else{
                    for(int j=0;j<3;j+=1)
                      if(a[i+j]==-1)
                        a[i+j]=b[0];
                }
            }
        }
        cout<<out<<"\n";
    }
    return 0;
}