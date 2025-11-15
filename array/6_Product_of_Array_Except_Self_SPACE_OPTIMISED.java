class Solution {
    public int[] productExceptSelf(int[] nums) {
        int len = nums.length;
        int[] ans = new int[len];
        ans[0] = 1;

        int postfixProduct = 1;

        // prefix
        for(int i=1; i<len; i++){
            ans[i] = ans[i-1] * nums[i-1];
        }

        // postfix
        for(int i=len-2; i>=0; i--){
            int postfixCal = postfixProduct * nums[i+1];
            postfixProduct = postfixCal;
            ans[i] *= postfixCal;
        }

        return ans;
    }
}
