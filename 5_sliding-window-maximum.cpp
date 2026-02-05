class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++){
            if(!dq.empty() && nums[i] >= nums[dq.back()]){
                while(!dq.empty() && nums[i] >= nums[dq.back()]){
                    dq.pop_back();
                }
            }

            if(!dq.empty() && dq.front() <= i-k){
                while(!dq.empty() && dq.front() <= i-k){
                    dq.pop_front();
                }
            }


            dq.push_back(i);

            if(i+1 >= k) ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};
