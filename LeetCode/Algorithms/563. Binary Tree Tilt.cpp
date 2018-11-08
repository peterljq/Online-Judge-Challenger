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
    int findTilt(TreeNode* root) {
        if (root == NULL) return 0;
        else if(root->left == NULL && root->right == NULL) return 0;
        else{
            int sumLeft = sum(root->left);
            int sumRight = sum(root->right);
            int gap = abs(sumLeft - sumRight);
            return gap + findTilt(root->left) + findTilt(root->right);
        }
    }
    
    int sum(TreeNode* root){
        if(root == NULL) return 0;
        else{
            return root->val + sum(root->left) + sum(root->right);
        }
    }
};
