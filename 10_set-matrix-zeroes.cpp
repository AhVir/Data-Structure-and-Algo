class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();


        vector<int> rowZero(row, 0);
        vector<int> colZero(column, 0);


        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                if(matrix[i][j] == 0){
                    rowZero[i] = 1;
                    colZero[j] = 1;
                }
            }
        }



        for(int i=0; i<row; i++){
            if(rowZero[i] == 1){
                for(int j=0; j<column; j++){
                    matrix[i][j] = 0;
                }
            }
        }


        for(int i=0; i<column; i++){
            if(colZero[i] == 1){
                for(int j=0; j<row; j++){
                    matrix[j][i] = 0;
                }
            }
        }
    }
};
