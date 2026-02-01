class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int lr = 0, rr = n-1;
        

        while(lr <= rr){
            int mid = (lr+rr)/2;
            int temp = matrix[mid][0];

            if(temp > target){
                rr = mid - 1;
            }
            else if(temp == target) return true;
            else{
                lr = mid + 1;
            }
        }

        if(target <= matrix[0][0]) rr = 0;
        else if(target >= matrix[n-1][0]) rr = n-1;

        // so, the selected row is matrix[rr]
        int lc = 0, rc = m-1;

        while(lc <= rc){
            int mid = (lc+rc)/2;
            int val = matrix[rr][mid];

            if(val == target) return true;
            else if(val > target){
                rc = mid - 1;
            }
            else{
                lc = mid + 1;
            }
        }

        return false;
    }
};