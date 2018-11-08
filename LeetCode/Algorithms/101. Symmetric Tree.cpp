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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isSame(root->left,root->right);
    }
    
    bool isSame(TreeNode* r1, TreeNode* r2){
        if(r1 == NULL && r2 == NULL) return true;
        else if(r1 != NULL && r2 == NULL) return false;
        else if(r1 == NULL && r2 != NULL) return false;
        else{
            if(r1->val != r2->val) return false;
            else{
                return isSame(r1->left,r2->right) && isSame(r1->right,r2->left);
            }
        }
    }
};