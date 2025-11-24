/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<TreeNode> generateTrees(int n) {
        if(n == 0) return new ArrayList<>();
        List<TreeNode>[][] memo = new ArrayList[n+1][n+1];

        return generateBST(1, n, memo);
    }

    private List<TreeNode> generateBST(int start, int end, List<TreeNode>[][] memo){
        List<TreeNode> ans = new ArrayList<>();
        if(start > end){
            ans.add(null);
            return ans;
        }

        if(memo[start][end] != null) return memo[start][end];

        for(int i=start; i<=end; i++){
            List<TreeNode> leftTree = generateBST(start, i-1, memo);
            List<TreeNode> rightTree = generateBST(i+1, end, memo);

            for(TreeNode left:leftTree){
                for(TreeNode right:rightTree){
                    TreeNode root = new TreeNode(i);
                    root.left = left;
                    root.right = right;

                    ans.add(root);
                }
            }
        }

        memo[start][end] = ans;

        return ans;
    }
}
