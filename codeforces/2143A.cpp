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
        for(int i=0;i<n;i++)    cin>>a[i];
        int i=0,j=n-1,curr=1;
        bool flag=false;
        while(i<j){
            if(a[i]==curr){
                ++i;
            }
            else if(a[j]==curr){
                --j;
            }
            else{
                flag=true;
                break;
            }
            curr+=1;
        }
        cout<<((flag)?"NO\n":"YES\n");
    }
    return 0;
}