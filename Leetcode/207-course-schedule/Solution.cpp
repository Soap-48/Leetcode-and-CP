class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i+=1){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
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
            num+=1;
            for(auto &j:adj[i]){
                indeg[j]-=1;
                if(indeg[j]==0)
                    q.push(j);
            }
        }
        if(num==numCourses)
            return true;
        else
            return false;
    }
};