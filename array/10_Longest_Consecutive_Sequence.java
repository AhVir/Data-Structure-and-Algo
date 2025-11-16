class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length == 0) return 0;

        HashSet<Integer> numbers = new HashSet<>();
        for(int x:nums){
            numbers.add(x);
        }

        int lcs = 1;

        for(int num:numbers){
            if(numbers.contains(num-1)) continue;

            int currentLCS = 1;
            int currentNum = num;
            while(numbers.contains(currentNum+1)){
                currentLCS++;
                currentNum++;
            }

            lcs = Math.max(lcs, currentLCS);
        }

        return lcs;
    }
}
