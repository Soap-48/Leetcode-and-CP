/*
    two pass travesal (either bfs or dfs)
    
    1. First we calculate for each node no of nodes in its subtree (including itself)
       and sum distance of all nodes in its subtree from itself. ie we calculate for parent
       using child data

    2. Next for each node we calculate sum of distances of nodes whose path goes through its parent
        so we calulate for child using parent data

    for that we maintain for each node a pair (sum of dist, no on nodes in subtree)
    in first travesal dp= sum of dchild + no of nodes in subtree, ci=sum of cchild +1
    in second travesal dchild+=(dp-dchild-cchild)+(n-cchild)
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200001];
vector<pair<long long,long long>> d(200001);
vector<int> p(200001);
int n;

void b1(int i){
    d[i].second=1;
    for(int j:adj[i]){
        if(j!=p[i]){
            p[j]=i;
            b1(j);
            d[i].first+=d[j].first+d[j].second;
            d[i].second+=d[j].second;
        }
    }
}

void b2(int i){
    for(int j:adj[i]){
        if(j!=p[i]){
            d[j].first+=(d[i].first-d[j].first-d[j].second+n-d[j].second);
            b2(j);
        }
    }
}

int main() {
	// your code goes here
    //lets do hardcore study
    cin>>n;
    int u,v;
    for(int i=1;i<n;i+=1){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    b1(1);b2(1);
    for(int i=1;i<=n;i+=1)
        cout<<d[i].first<<' ';
    return 0;
}
