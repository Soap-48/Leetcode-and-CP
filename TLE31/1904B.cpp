#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<unsigned int,unsigned int>> a(n); 
        vector<unsigned int> ans(n);       
        for(int i=0;i<n;i++){
            cin>>(a[i].first);
            a[i].second=i;
        }
        sort(all(a));
        //for(auto u:a)   cout<<'('<<u.first<<' '<<u.second<<") ";cout<<'\n';
        unsigned long long sum=0;int last=-1,count=-1;
        for(int i=0;i<n;i++){
            if(i<=last){
                ans[a[i].second]=count;
            }
            else{
                int j=i+1;
                sum=sum+a[i].first;
                count++;
                while(j<n){
                    if(a[j].first<=sum){
                        sum=sum+a[j].first;
                        j++;
                        count++;
                    }
                    else break;
                }
                last=j-1;
                ans[a[i].second]=count;
            }
        }
        for(auto h:ans) cout<<h<<' ';
        cout<<'\n';
        }   
    
    return 0;
}