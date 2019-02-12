/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public void levelOrder(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        TreeNode current = new TreeNode(0);
        q.add(root);
        while(!q.isEmpty()){
            current = q.remove();
            System.out.println(current.val);
            if(current.left != null){q.add(current.left);}
            if(current.right != null){q.add(current.right);}
        }
    }
}