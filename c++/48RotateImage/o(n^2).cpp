class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mid=(n+1)/2,mid_=n/2;
        for(int i=0;i<mid;i++){
            for(int j=0;j<mid_;j++){
                int tem=matrix[i][j];
                matrix[i][j]=matrix[n-j-1][i];
                matrix[n-j-1][i]=matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1]=matrix[j][n-i-1];
                matrix[j][n-i-1]=tem;
            }
        }
    }
};