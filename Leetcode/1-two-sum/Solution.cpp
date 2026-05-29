class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> out;
        for(int i=0;i<nums.size();++i){
            if(m.find(target-nums[i])!=m.end()){
                out.push_back(m[target-nums[i]]);out.push_back(i);
                return out;
            }
            else{
                m[nums[i]]=i;
            }
        }
        return out;
    }
};