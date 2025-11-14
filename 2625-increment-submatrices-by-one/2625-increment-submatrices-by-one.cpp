class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        for(auto itr : queries){
            int row1 = itr[0];
            int col1 = itr[1];
            int row2 = itr[2];
            int col2 = itr[3];
            for(int r=row1; r<=row2; r++){
                for(int c=col1; c<=col2; c++)
                    matrix[r][c]++;
            }
        }
        return matrix;
    }
};