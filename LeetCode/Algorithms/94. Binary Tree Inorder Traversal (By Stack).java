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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<Integer>();
        Stack<TreeNode> s = new Stack<TreeNode>();
        TreeNode ptr = root;
        while(!s.isEmpty() || ptr != null){
            while(ptr != null){
                s.push(ptr);
                ptr = ptr.left;
            }
            ptr = s.pop();
            result.add(ptr.val);
            ptr = ptr.right;
        }
        return result;
    }
    
}