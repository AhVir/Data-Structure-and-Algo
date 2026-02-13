class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        // vector<int> prefix(n, 0);

        // for(int i=0; i<n; i++) if(nums[i] == 0) nums[i] = -1;

        // prefix[0] = nums[0];
        // for(int i=1; i<n; i++){
        //     prefix[i] = prefix[i-1] + nums[i];
        // }


        // for(int i:prefix) cout << i << " ";
        // cout << endl;

        int sum = 0;
        int maxLen = 0;

        mp[0] = -1;

        for(int i=0; i<n; i++){
            if(nums[i] == 0) nums[i] = -1;

            sum += nums[i];

            if(mp.find(sum) != mp.end()) {
                maxLen = max(maxLen, i - mp[sum]);
            } else {
                mp[sum] = i;  // store first occurrence only
            }
        }

        return maxLen;
    }
};
