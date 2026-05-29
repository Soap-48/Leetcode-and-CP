class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        bool added=false;
        vector<vector<int>> ans;
        int i=0;
        for(i=0;i<n;i+=1){
            if(intervals[i][0]<newInterval[0]){
                ans.push_back(intervals[i]);
            }
            else break;
        }
            int l=newInterval[0],r=newInterval[1];
            while(!ans.empty()&&ans.back()[1]>=l){
                l=ans.back()[0];
                r=max(ans.back()[1],r);
                ans.pop_back();
            }
            ans.push_back({l,r});
        for(;i<n;i+=1){
            if(ans.back()[1]<intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            else
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
        }
        return ans;
    }
};