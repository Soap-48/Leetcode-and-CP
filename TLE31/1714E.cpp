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
        int n,temp;
        cin>>n;
        set<int> a,a0;
        for(int i=0;i<n;i++){
            cin>>temp;
            if(temp%5==0) {
                if(temp%10==0)              a0.insert(temp);
                else        a0.insert(temp+5);
            }
            else{
                if(temp%2==0)                   a.insert(temp);
                else               a.insert(temp+(temp%10));                
            }
        }
        if(!a0.empty()){
            if(!a.empty())                cout<<"No\n";
            else if(a0.size()>1)                cout<<"No\n";
            else cout<<"Yes\n";
        }
        else{
            bool flag=true;
            while(a.size()>1){
                int val1=(*a.begin()),val2=(*next(a.begin()));
                int d1=val1%10,d2=val2%10;
                while(d1!=d2){
                    val1+=(val1%10);
                    d1=val1%10;
                }
                if(abs(val1-val2)%20==0){
                    a.erase(next(a.begin()));
                    a.erase(a.begin());
                    a.insert(val1);
                }
                else{
                    flag=false;
                    break;
                }
            }  
           if(flag) cout<<"Yes\n";
           else cout<<"No\n";
        }
    }
    return 0;
}