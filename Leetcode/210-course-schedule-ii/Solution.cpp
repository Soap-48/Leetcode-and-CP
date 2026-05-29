class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i+=1){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> ans;
        vector<int> indeg(numCourses,0);
        for(int i=0;i<prerequisites.size();i+=1)
            indeg[prerequisites[i][0]]+=1;
        queue<int> q;
        for(int i=0;i<numCourses;i+=1){
            if(indeg[i]==0)
                q.push(i);
        }
        int num=0;
        while(!q.empty()){
            int i=q.front();q.pop();
            ans.push_back(i);
            num+=1;
            for(auto &j:adj[i]){
                indeg[j]-=1;
                if(indeg[j]==0)
                    q.push(j);
            }
        }
        vector<int> temp;
        if(num==numCourses){
            return ans;
        }
        else
            return temp;
    }
};