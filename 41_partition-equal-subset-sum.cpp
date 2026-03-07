class Solution {
public:
    bool EqualPartition(vector<int>& nums, vector<vector<int>>& dp, int i, int w){
        if(w == 0) return true;

        if(i == 0){
            if(w == nums[i]) return true;
            else return false;
        }

        // memo
        if(dp[i][w] != -1) return dp[i][w];


        bool skip = EqualPartition(nums, dp, i-1, w);
        bool take = false;

        if(nums[i] <= w){
            take = EqualPartition(nums, dp, i-1, w-nums[i]);
        }

        return dp[i][w] = skip || take;
    }


    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int x:nums) total += x;

        if(total%2 != 0) return false;

        int w = total/2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(w+1, -1));

        return EqualPartition(nums, dp, n-1, w);
    }
};
