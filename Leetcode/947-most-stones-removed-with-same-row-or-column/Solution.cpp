class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        map<pair<int,int>,pair<int,int>> parent;
        map<pair<int,int>,int> rank;
        auto makeset=[&parent,&rank](int i,int j)->void{
            parent[{i,j}]={i,j};
            rank[{i,j}]=0;
        };
        auto find=[&parent](auto &self,int x,int y)->pair<int,int>{
            pair<int,int>t={x,y};
            if(parent[{x,y}]==t)
                return t;
            else
                return parent[{x,y}]=self(self,parent[{x,y}].first,parent[{x,y}].second);
        };
        auto chunion=[&](int a1,int a2,int b1,int b2)->void{
            pair<int,int>  x=find(find,a1,a2),y=find(find,b1,b2);
            if(x!=y){
                if(rank[x]<rank[y])
                    swap(x,y);
                parent[y]=x;
                if(rank[x]==rank[y])
                    rank[x]+=1;
            }
        };
        for(int i=0;i<n;i+=1)
            makeset(stones[i][0],stones[i][1]);
        sort(stones.begin(),stones.end());
        for(int i=1;i<n;i+=1)
            if(stones[i-1][0]==stones[i][0])
                chunion(stones[i-1][0],stones[i-1][1],stones[i][0],stones[i][1]);
        sort(stones.begin(),stones.end(),[](const vector<int> &a,const vector<int> &b)->bool{
            if(b[1]!=a[1])
                return b[1]>a[1];
            else
                return b[0]>a[0];
        });
        for(int i=1;i<n;i+=1)
            if(stones[i-1][1]==stones[i][1])
                chunion(stones[i-1][0],stones[i-1][1],stones[i][0],stones[i][1]);
        int c=0;
        for(int i=0;i<n;i+=1)
            if(find(find,stones[i][0],stones[i][1])==make_pair(stones[i][0],stones[i][1]))
                c+=1;
        return n-c;
    }
};