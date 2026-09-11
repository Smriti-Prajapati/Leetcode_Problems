/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameter=0;
    int height(TreeNode* node){
        if(node==nullptr){
            return -1;
        }
        int leftHeight=height(node->left);
        int rightHeight=height(node->right);
        diameter= max(diameter, leftHeight+rightHeight+2);
        return max(leftHeight, rightHeight)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};