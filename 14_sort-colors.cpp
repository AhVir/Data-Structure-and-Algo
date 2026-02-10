class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0, ones = 0, twos = nums.size()-1;

        while(ones <= twos){
            if(nums[ones] == 0){
                // swap(ones, zeros);
                int temp = nums[zeros];
                nums[zeros] = 0;
                nums[ones] = temp;
                zeros++;
                ones++;
            }
            else if(nums[ones] == 1){
                ones++;
            }
            else{
                // swap(ones, twos);
                int temp = nums[twos];
                nums[twos] = nums[ones];
                nums[ones] = temp;
                twos--;
            }
        }
    }
};
