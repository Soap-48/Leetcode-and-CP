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
        vi a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int temp;
        for(int i=0;i<n;i++){
            cin>>temp;
            //cout<<a[i]<<',';
            a[i]-=temp;
            //cout<<temp<<','<<a[i]<<'|';
        }//cout<<endl;
        int max=a[0],c=1;
        vi indices;
        indices.push_back(0);
        for(int i=1;i<n;i++){
            if(a[i]>max){
                max=a[i];
                c=1;
                indices.clear();
                indices.push_back(i);
            }
            else if(a[i]==max){
                c++;
                indices.push_back(i);
            }
        }
        cout<<c<<'\n';
        for(auto a:indices) cout<<a+1<<' ';
        cout<<'\n';
    }
    return 0;
}



/*
Jo cheez notice karna tha ki hamlog hamesa upar se niche jate hai
 (a-b) ki values ke hisab se. To agar hamara vertice manlo max a-b 
 wala nahi hai to max a-b wala vertice kabhi nahi pahooch sakte
*/