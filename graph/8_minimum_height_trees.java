class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        if(n == 1) return new ArrayList<>(List.of(0));


        List<List<Integer>> tree = new ArrayList<>();

        for(int i=1; i<=n; i++) tree.add(new ArrayList<>());

        for(int[] e:edges){
            int i = e[0], j = e[1];

            tree.get(i).add(j);
            tree.get(j).add(i);
        }

        int[] edge_cnt = new int[n];

        Queue<Integer> leaves = new LinkedList<>();

        for(int i=0; i<n; i++){
            if(tree.get(i).size() == 1) leaves.offer(i);

            edge_cnt[i] = tree.get(i).size();
        }


        while(leaves.size() > 0){
            if(n <= 2) return new ArrayList<>(leaves);
            
            int len = leaves.size();
            for(int i=0; i<len; i++){
                int x = leaves.poll();
                List<Integer> temp = tree.get(x);
                n--;

                for(int ele:temp){
                    edge_cnt[ele]--;

                    if(edge_cnt[ele] == 1) leaves.offer(ele);
                }
            }
        }

        return new ArrayList<>(leaves);
    }
}
