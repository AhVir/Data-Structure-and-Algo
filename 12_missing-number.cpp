class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int arr[10001] = {0};

        for(int i=0; i<nums.size(); i++){
            arr[nums[i]] = 1;
        }

        // bool found = false;
        int ans = -1;
        for(int i=0; i<nums.size(); i++){
            if(arr[i] == 0){
                ans = i;
            }
        }


        if(ans != -1) return ans;
        else return nums.size();
    }
};
