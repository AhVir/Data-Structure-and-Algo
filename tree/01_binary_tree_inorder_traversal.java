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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> inOrder = new ArrayList<>();
        inorderTraversal(inOrder, root);

        return inOrder;   
    }

    void inorderTraversal(List<Integer> inOrder, TreeNode root){
        if(root == null) return;

        inorderTraversal(inOrder, root.left);
        inOrder.add(root.val);
        inorderTraversal(inOrder, root.right);
    }
}
