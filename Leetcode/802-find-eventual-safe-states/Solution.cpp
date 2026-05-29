class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> g2(n);
        for(int i=0;i<n;i+=1)
            for(int j:graph[i])
                g2[j].push_back(i);
        vector<int> topo;
        vector<int> indeg(n,0);
        for(int i=0;i<n;i+=1)
            for(int &j:graph[i])
                indeg[i]+=1;
        queue<int> q;
        for(int i=0;i<n;i+=1){
            if(indeg[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int i=q.front();q.pop();
            topo.push_back(i);
            for(auto &j:g2[i]){
                indeg[j]-=1;
                if(indeg[j]==0)
                    q.push(j);
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};