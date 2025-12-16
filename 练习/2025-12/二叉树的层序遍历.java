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
    public List<List<Integer>> levelOrder(TreeNode root) {
        ArrayDeque<TreeNode> queue = new ArrayDeque<>();
        List<List<Integer>> ans = new ArrayList<>();

        if(root == null) {
            return ans;
        }

        queue.addLast(root);
        int sz = 1;
        while(!queue.isEmpty()) {
            List<Integer> level = new ArrayList<>();
            while(sz > 0) {
                sz--;
                TreeNode node = queue.removeFirst();
                level.add(node.val);
                if(node.left != null) {
                    queue.addLast(node.left);
                }
                if(node.right != null) {
                    queue.addLast(node.right);
                }
            }
            ans.add(level);
            sz = queue.size();
        }

        return ans;
    }
}