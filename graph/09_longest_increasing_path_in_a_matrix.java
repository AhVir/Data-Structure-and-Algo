class Solution {
    public int longestIncreasingPath(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;

        int[][] memo = new int[m][n];
        // Arrays.fill(memo, 0);

        // dfs
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans = Math.max(ans, dfs(matrix, i, j, memo));
            }
        }
        return ans;
    }

    int dfs(int[][] mat, int i, int j, int[][] memo){
        if(memo[i][j] != 0) return memo[i][j];
        int m = mat.length, n = mat[0].length;

        int maxVal = 1;
        
        int[] direcX = {0, 0, -1, 1};
        int[] direcY = {-1, 1, 0, 0};

        for(int a=0; a<4; a++){
            int x = i + direcX[a], y = j + direcY[a];
            if(isValid(x, y, m, n) && mat[x][y]>mat[i][j]){
                maxVal = Math.max(maxVal, 1 + dfs(mat, x, y, memo));
            }
        }

        memo[i][j] = maxVal;
        return maxVal;
    }

    boolean isValid(int i, int j, int m, int n){
        if(i >= 0 && i < m && j >= 0 && j < n) return true;
        return false;
    }
}
