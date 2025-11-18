class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        if(n == 1 || edges.length == 0) return true;

        List<List<Integer>> list = new ArrayList<>();

        for(int i=0; i<n; i++){
            list.add(new ArrayList<>());
        }

        for(int[] e:edges){
            int x = e[0], y = e[1];

            list.get(x).add(y);
            list.get(y).add(x);
        }

        int[] visited = new int[n];
        Arrays.fill(visited, 0);

        Queue<Integer> que = new LinkedList<>();
        que.offer(source);
        visited[source] = 1;

        while(!que.isEmpty()){
            int top = que.poll();

            for(int node:list.get(top)){
                if(node == destination) return true;
                if(visited[node] == 0){
                    visited[node] = 1;
                    que.offer(node);
                }
            }
        }


        return false;
    }
}
