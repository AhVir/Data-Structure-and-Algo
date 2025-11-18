class Solution {
    public int firstMissingPositive(int[] nums) {
        int len = nums.length;
        if(len == 0) return 1;

        for(int i=0; i<len; i++) if(nums[i] < 0) nums[i] = 0;

        for(int i=0; i<len; i++){
            int idx = Math.abs(nums[i])-1;

            if(idx < 0 || idx >= len) continue;

            if(nums[idx] > 0) nums[idx] *= -1;
            else if(nums[idx] == 0) nums[idx] = -(len+5);    // abs(-(len+5)) will go out of bound after converting it to IDX
        }
        
        // for(int x:nums){
        //     System.out.println(x + " ");
        // }

        // final iteration, to get the first missing positive
        for(int i=1; i<=len; i++){
            if(nums[i-1] >= 0) return i;
        }

        return len+1;
    }
}
