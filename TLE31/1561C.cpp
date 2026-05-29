#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
using namespace std;

bool comp(pair<int,int> a,pair<int,int> b){
    if (a.first != b.first)
            return a.first < b.first;    
        return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        int k;
        cin>>n;
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;i++){
            cin>>k;
            int maxp=INT_MIN,in;
            for(int j=0;j<k;j++){
                cin>>in;
                in-=j;
                if(in>maxp) maxp=in;
            }
            a[i].first=maxp;
            a[i].second=k;
        }
        sort(all(a),comp);
        int max=a[0].first,val=0;
        for(int i=1;i<n;i++){
            val+=a[i-1].second;
            if((a[i].first-val)>max)    max=(a[i].first)-val;
        }
        cout<<max+1<<"\n";
    }
    return 0;
}