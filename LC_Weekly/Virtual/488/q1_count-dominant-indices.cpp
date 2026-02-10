class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int cnt = 0;
        
        int n = nums.size();
        vector<int> PreSum(n, 0);
        PreSum[n-1] = nums[n-1];

        for(int i=n-2; i>=0; i--){
            // int temp = nums[i];
            PreSum[i] = PreSum[i+1] + nums[i];
        }

        for(int i=0; i<n; i++){
            int cal = PreSum[i]/(n-i);
            if(nums[i] > cal) cnt++;
        }

        return cnt;
    }
};
