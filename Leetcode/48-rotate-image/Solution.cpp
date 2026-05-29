class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==0)    return;
        for(int i=n-1;i>=0;i-=1){
            for(int j=0;j<=i;j+=1){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
         for(vector<int>& v:matrix){
            reverse(v.begin(),v.end());
        }
    }
};