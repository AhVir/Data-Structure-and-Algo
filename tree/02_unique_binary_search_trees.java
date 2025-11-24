class Solution {
    public int numTrees(int n) {
        long[] bstCount = new long[n+1];
        bstCount[0] = 1;


        for(int i=1; i<=n; i++){
            long count = 0L;
            for(int root=1; root<=i; root++){
                count += bstCount[root-1] * bstCount[i-root];
            }

            bstCount[i] = count;
        }

        return (int)bstCount[n];
    }
}
