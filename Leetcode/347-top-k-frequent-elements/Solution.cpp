class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i:nums)
            m[i]+=1;
        vector<pair<int,int>> v;
        for(auto &[i,j]:m)
            v.push_back(pair(j,i));
        sort(v.rbegin(),v.rend());
        vector<int> ans;
        for(int i=0;i<k;i+=1)
            ans.push_back(v[i].second);
        return ans;
    }
};