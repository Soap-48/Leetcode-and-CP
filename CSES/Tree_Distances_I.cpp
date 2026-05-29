#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200001];
int h[200001];
int p[200001];

int solve(int i){
    int val=-1;
    for(int j:adj[i]){
        if(j!=p[i]){
            p[j]=i;
            val=max(val,solve(j));
        }
    }
    return h[i]=val+1;
}

void it2(vector<int> &ph,int i){
    int v1=-1,v2=-1,in=-1;
    for(int j:adj[i]){
        if(j!=p[i]){if(h[j]>=v1){
            v2=v1;
            v1=h[j];
            in=j;
        }
        else if(h[j]>v2)
            v2=h[j];}
    }
    for(int j:adj[i]){
        if(j!=p[i]){
            p[j]=i;
            if(p[i]!=-1)
                ph[j]=ph[i]+1;
            ph[j]=max(ph[j],((j==in)?v2:v1)+2);
            it2(ph,j);
        }
    }
}

int main() {
	// your code goes here
    int n;
    cin>>n;
    int u,v;
    for(int i=1;i<n;i+=1){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solve(1);
    vector<int> ph(n+1,0);
    for(int i=1;i<=n;i+=1)
        p[i]=-1;
    it2(ph,1);
    for(int i=1;i<=n;i+=1)
        cout<<max(h[i],ph[i])<<' ';
    return 0;
}
