class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        List<List<int[]>> graph = new ArrayList<>();

        for(int i=0; i<=n; i++){
            graph.add(new ArrayList<>());
        }

        for(int[] t:times){
            int u = t[0], v = t[1], wt = t[2];

            graph.get(u).add(new int[]{v, wt});
        }

        int[] dist = new int[n+1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[k] = 0;

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);
        pq.offer(new int[]{k, 0});

        // Dijkstra
        while(!pq.isEmpty()){
            int[] top = pq.poll();

            int node = top[0];
            int time = top[1];

            if(time > dist[node]) continue;

            for(int[] edge:graph.get(node)){
                int nextNode = edge[0];
                int wt = edge[1];

                int newDist = dist[node] + wt;
                if(newDist < dist[nextNode]){
                    dist[nextNode] = newDist;

                    pq.offer(new int[]{nextNode, newDist});
                }
            }
        }

        for(int i=1; i<=n; i++){
            if(dist[i] == Integer.MAX_VALUE) return -1;
        }

        int ans = 0;
        for(int i=1; i<=n; i++) ans = Math.max(ans, dist[i]);

        return ans;
    }
}
