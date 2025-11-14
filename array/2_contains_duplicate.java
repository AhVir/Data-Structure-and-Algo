class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> freq = new HashSet<Integer>();

        for(int i=0; i<nums.length; i++){
            int target = nums[i];

            if(freq.contains(target)){
                return true;
            }
            else freq.add(target);
        }

        return false;
    }
}
