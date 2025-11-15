class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        if(k == nums.length) return nums;

        Map<Integer, Integer> freq = new HashMap<>();

        for(int x:nums){
            if(!freq.containsKey(x)){
                freq.put(x, 1);
            }
            else{
                freq.put(x, freq.get(x)+1);
            }
        }

        // Priority Queue (Min Heap)
        Queue<Integer> heap = new PriorityQueue<>((a, b) -> freq.get(a) - freq.get(b));

        for(int x:freq.keySet()){
            heap.add(x);

            if(heap.size() > k) heap.poll();
        }

        int[] ans = new int[k];
        int i = 0;
        while(!heap.isEmpty()){
            ans[i++] = heap.poll();
        }


        return ans;
    }
}
