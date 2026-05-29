/*#include <bits/stdc++.h>

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
        int n,x,y;
        cin>>n>>x>>y;
        unordered_map<int,vi> mx;
        vi b(n);
        int deviants=0;
        for(int i=0;i<n;i++){
            cin>>b[i];
            int k1=b[i]%x;
            mx[k1].pb(i);            
        }
        ll count=0;
        for(auto &[a,q]:mx){
            if(!(mx[x-a].empty())){
                for(auto i:q){
                    for(auto j:mx[x-a]){
                        if((i-j)%y==0){
                            count++;
                        }
                    }
                }
            }
        }
        cout<<count/2<<'\n';
    }
    return 0;
}
*/

/*
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
        int n,x,y;
        cin>>n>>x>>y;
        vi a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        ll count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(((a[i]+a[j])%x==0)&&((a[i]-a[j])%y==0)){
                    count++;
                }
            }
        }
        cout<<count<<'\n';
    }
    return 0;
}
*/

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
        int n,x,y;
        cin>>n>>x>>y;
        vi a(n);
        for(int i=0;i<n;i++)    cin>>a[i];
        sort(all(a));
        for(int i=0;i<n;i++){
            int magic=(
        }
    }
    return 0;
}

/*
Isko solve karna hai.
Ye realize karna chahiye tha ki agar map loop mei build karu to hamesa usse pahle wale elemebts hi bas aayennge to alag se check ya half nahi karna padega.
*/