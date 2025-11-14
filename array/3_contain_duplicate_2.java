class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        HashSet<Integer> set = new HashSet<>();

        for(int i=0; i<nums.length; i++){
            if(set.contains(nums[i])) return true;
            else{
                set.add(nums[i]);
            }

            int setSize = set.size();
            if(setSize > k){
                set.remove(nums[i-k]);
            }
        }

        return false;
    }
}
