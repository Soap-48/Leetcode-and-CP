class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        if(matrix.size()==0) return v;
        int top=0,bottom=matrix.size()-1,right=matrix[0].size()-1,left=0;
        while(top<=bottom&&right>=left){
            for(int i=left;i<=right;i+=1){
                v.push_back(matrix[top][i]);
            }
            top+=1;
            if(top<=bottom) for(int i=top;i<=bottom;i+=1){
                v.push_back(matrix[i][right]);
            }
            right-=1;
            if(right>=left&&top<=bottom) for(int i=right;i>=left;i-=1){
                v.push_back(matrix[bottom][i]);
            }
            bottom-=1;
            if(top<=bottom&&right>=left) for(int i=bottom;i>=top;i-=1){
                v.push_back(matrix[i][left]);
            }
            left+=1;
        }
       // v.push_back(1);
        return v;
    }
};