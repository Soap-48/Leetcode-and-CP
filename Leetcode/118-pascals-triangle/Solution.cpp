class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i+=1){
            long long val=1;
            vector<int> temp={1};
            for(int j=1;j<=i;j+=1){
                val=val*(i-j+1);
                val=val/j;
                temp.push_back(val);
            }   
            ans.push_back(temp);
        }
        return ans;
    }
};