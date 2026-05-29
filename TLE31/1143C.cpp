#include <bits/stdc++.h>

using ll=long long;
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;

typedef struct NODE{
    int p;
    int c;
    int nc=0;
    int r=0;
} node;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        int n;
        cin>>n;
        node ver[n+1];
        for(int i=1;i<=n;i+=1){
            cin>>ver[i].p;
            cin>>ver[i].c;
            if(ver[i].p!=-1){
                ver[ver[i].p].nc+=1;
                if(ver[i].c==0) ver[ver[i].p].r+=1;
            }
        }
        vi ans;
        for(int i=1;i<=n;i+=1){
            if(ver[i].c==1&&ver[i].r==0){
                ans.push_back(i);
            }
        }
        if(!ans.empty()){
        sort(all(ans));
        for(int i:ans)
            cout<<i<<" ";
        }
        else cout<<"-1";
        cout<<"\n";
    return 0;
}