/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode *final = new TreeNode(val);
            return final;
        }
        else{
            if(val > root->val){
                root->right = insertIntoBST(root->right,val);
            }
            else{
                root->left = insertIntoBST(root->left, val);
            }
            return root;
        }
    }
};