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
        int n;
        cin>>n;
        int tmep;
        vi num,indices;
        for(int i=1;i<=n;i++){
            cin>>tmep;
            if(tmep<(i)){
                num.push_back(tmep);
                indices.push_back(i);
            }
        }
        sort(num.rbegin(),num.rend());sort(indices.rbegin(),indices.rend());
        vi sol;
        vector<int>::iterator it=num.begin();
        ll count=0;
        for(auto k:indices){
            while(it<num.end()&&k<*it){
                sol.push_back(*it);
                it+=1;
            }
            count+=sol.size();
        }
        cout<<count<<"\n";
    }
    return 0;
}