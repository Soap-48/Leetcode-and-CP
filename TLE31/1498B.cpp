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
        int n,W,count=1,temp;
        cin>>n>>W;
        int layer=W;
        multiset<int> a;
        for(int i=0;i<n;i++)    {cin>>temp;a.insert(temp);}
        while(!a.empty()){
            int curr=*(a.rbegin());
            if(layer>=curr){
                layer=layer-curr;
                a.erase(prev(a.end()));
            }
            else{
                auto j=a.upper_bound(layer);
                if(j==a.begin()){
                    count++;
                    layer=W;
                }
                else{
                    j--;
                    layer=layer-(*j);
                    a.erase(j);
                }
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}