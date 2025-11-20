class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        HashMap<Integer, List<Integer>> graph = new HashMap<>();

        for(int[] preq:prerequisites){
            int x = preq[0], y = preq[1];

            if(!graph.containsKey(x)) graph.put(x, new ArrayList<>());
            graph.get(x).add(y);
        }
        // Grpah is built

        boolean[] visiting = new boolean[numCourses];
        boolean[] visited = new boolean[numCourses];

        Arrays.fill(visiting, false);
        Arrays.fill(visited, false);

        List<Integer> path = new ArrayList<>();

        // return dfs(0, visiting, visited, graph);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!dfs(i, visiting, visited, graph, path)) return new int[0];
            }
        }
        return path.stream().mapToInt(i -> i).toArray();
    }
    boolean dfs(int node, boolean[] visiting, boolean[] visited, HashMap<Integer, List<Integer>> graph, List<Integer> path){
        visiting[node] = true;

        for(int n:graph.getOrDefault(node, new ArrayList<>())){
            if(visiting[n] == true) return false;
            if(visited[n] == false){
                if(dfs(n, visiting, visited, graph, path) == false) return false;
            }
        }

        visiting[node] = false;
        visited[node] = true;
        path.add(node);

        return true;
    }
}
