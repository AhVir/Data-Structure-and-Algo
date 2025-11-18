class Solution {
    private int DFS(int[][] map, int x, int y){
        int len = map.length;

        if(x < 0 || x >= len || y < 0 || y >= map[x].length || map[x][y] == 0) return 0;

        //marking it visited
        map[x][y] = 0;
        int count = 1;

        count += DFS(map, x+1, y);
        count += DFS(map, x-1, y);
        count += DFS(map, x, y+1);
        count += DFS(map, x, y-1);

        return count;
    }

    public int maxAreaOfIsland(int[][] grid) {
        int len = grid.length;

        if(len == 0) return 0;

        int ans = 0;
        for(int i=0; i<len; i++){
            for(int j=0; j<grid[i].length; j++){
                if(grid[i][j] == 1){
                    int temp = DFS(grid, i, j);

                    ans = Math.max(temp, ans);
                }
            }
        }

        return ans;
    }
}
