class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int hold = 0;
        int n = nums.size();

        for(int i=1; i<n; i++){
            if(nums[i] != nums[hold]){
                hold++;
                nums[hold] = nums[i];
            }
        }

        return hold+1;
    }
};
