class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
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

        // return dfs(0, visiting, visited, graph);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!dfs(i, visiting, visited, graph)) return false;
            }
        }
        return true;
    }

    boolean dfs(int node, boolean[] visiting, boolean[] visited, HashMap<Integer, List<Integer>> graph){
        visiting[node] = true;

        for(int n:graph.getOrDefault(node, new ArrayList<>())){
            if(visiting[n] == true) return false;
            if(visited[n] == false){
                if(dfs(n, visiting, visited, graph) == false) return false;
            }
        }

        visiting[node] = false;
        visited[node] = true;

        return true;
    }
}
