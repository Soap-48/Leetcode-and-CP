class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i=0;i<n;i+=1)
            parent[i]=i;
        auto find=[&](auto &self,int a)->int{
            if(parent[a]==a)
                return a;
            else
                return parent[a]=self(self,parent[a]);
        };
        auto chunion=[&](int a,int b){
            a=find(find,a);
            b=find(find,b);
            if(a!=b){
                if(rank[a]<rank[b])
                    swap(a,b);
                parent[b]=a;
                if(rank[a]==rank[b])
                    rank[a]+=1;
            }
        };      
        map<string,int> m;
        for(int i=0;i<n;i+=1)
            for(int j=1;j<accounts[i].size();j+=1){
                if(m.contains(accounts[i][j])){
                    chunion(i,m[accounts[i][j]]);
                }
                else
                    m[accounts[i][j]]=i;
            }
        int c=0;
        unordered_map<int,int> conv;
        for(int i=0;i<n;i+=1)
            if(find(find,i)==i){
                conv[i]=c;
                c+=1;
            }
        vector<vector<string>> ans(c);
        for(auto &[i,j]:m){
            if(ans[conv[find(find,j)]].empty())
                ans[conv[find(find,j)]].push_back(accounts[find(find,j)][0]);
            ans[conv[find(find,j)]].push_back(i);
        }
        return ans;
    }
};