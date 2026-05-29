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
        int n,x;
        cin>>n>>x;
        vi arr(n);char c;
        for(int i=0;i<n;i+=1){
            cin>>c;
            if(c=='.')
                arr[i]=0;
            else    arr[i]=1;
        }
        int a=0,b=0,a1=(x-1),b1=n-x;
        int count=0;
        for(int i=0;i<=x-2;i+=1){
            count+=1;
            if(arr[i]==1){
                a+=count;
                count=0;
            }
        }  
        count=0;
        for(int i=n-1;i>=x;i-=1){
            count+=1;
            if(arr[i]==1){
                b+=count;
                count=0;
            }
        }
        cout<<(max(min(a1,b),min(a,b1)))+1<<"\n";
    }
    return 0;
}