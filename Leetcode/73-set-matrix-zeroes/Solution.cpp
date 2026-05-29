class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size();
       if(r==0) return;
        int c=matrix[0].size();
        vector<int> rows(r,0);
        vector<int> cols(c,0);
           for(int i=0;i<r;i+=1){
            for(int j=0;j<c;j+=1){
                if(matrix[i][j]==0){
                    rows[i]=1;
                    cols[j]=1;
                }
            }
        }
        for(int i=0;i<r;i+=1){
            if(rows[i]==1){
                for(int k=0;k<c;k+=1)
                    matrix[i][k]=0;
            }
        }
        for(int i=0;i<c;i+=1){
            if(cols[i]==1){
                for(int k=0;k<r;k+=1)
                    matrix[k][i]=0;
            }
        }
    }
};