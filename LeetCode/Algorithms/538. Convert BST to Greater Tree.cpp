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
private:
    int sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL) return root;
        else{
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
            return root;
        }
    }
    //reverse of In-order traversal on BST tree.
};