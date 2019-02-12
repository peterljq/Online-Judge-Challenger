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
        iOT(root, result);
        return result;
    }
    
    public void iOT(TreeNode root, List<Integer> list){
        if(root == null){
            
        }
        else if(root.left == null && root.right == null){
            list.add(root.val);
        }
        else{
            iOT(root.left, list);
            list.add(root.val);
            iOT(root.right, list);
        }
    }
}