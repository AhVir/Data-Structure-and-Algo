class Solution {
public:
    long long recur(int i, int n, vector<int>& nums, vector<int>& colors, vector<long long>& memo){
        if(i == n-1){
            return nums[i];
        }
        if(i > n-1) return 0;

        if(memo[i] != -1) return memo[i];

        if(i+1 < n && colors[i] == colors[i+1]){
            long long a1 = recur(i+1, n, nums, colors, memo);
            long long a2 = nums[i] + recur(i+2, n, nums, colors, memo);

            // cout << "max: " << max(a1, a2) << endl;
            // cout << "nums[i]: " << nums[i] << endl;
            // cout << 
        
            return memo[i] = max(a1, a2);
        }
        else{
            return memo[i] = nums[i] + recur(i+1, n, nums, colors, memo);
        }
    }

    
    long long rob(vector<int>& nums, vector<int>& colors) {
        vector<long long> memo(nums.size(), -1);
        long long final_ans = recur(0, nums.size(), nums, colors, memo);
        

        cout << final_ans << endl;

        return final_ans;
    }
};