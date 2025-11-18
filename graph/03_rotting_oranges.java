class Solution {
    public int orangesRotting(int[][] grid) {
      int m = grid.length;
      int n = grid[0].length;

      Queue<int[]> queue = new LinkedList<>();

      for(int i=0; i<grid.length; i++){
        for(int j=0; j<grid[i].length; j++){
          if(grid[i][j] == 2){
            queue.offer(new int[]{i, j});
          }
        }
      }


      int min = 0;
      while(!queue.isEmpty()){
        int size = queue.size();

        for(int i=0; i<size; i++){
          int[] cell = queue.poll();

          int x = cell[0], y = cell[1];

          if(isValid(x+1, y, m, n) && grid[x+1][y] == 1){
            grid[x+1][y] = 2;
            queue.offer(new int[]{x+1, y});
          } 
          if(isValid(x-1, y, m, n) && grid[x-1][y] == 1){
            grid[x-1][y] = 2;
            queue.offer(new int[]{x-1, y});
          } 
          if(isValid(x, y+1, m, n) && grid[x][y+1] == 1){
            grid[x][y+1] = 2;
            queue.offer(new int[]{x, y+1});
          } 
          if(isValid(x, y-1, m, n) && grid[x][y-1] == 1){
            grid[x][y-1] = 2;
            queue.offer(new int[]{x, y-1});
          }
        }

        if(!queue.isEmpty()) min++;
      }

      for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
          if(grid[i][j] == 1) return -1;
        }
      }

      return min;
    }

    private boolean isValid(int x, int y, int lenX, int lenY){
      if(x < 0 || x >= lenX || y < 0 || y >= lenY) return false;

      return true;
    }
}
