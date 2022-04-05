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
    int maxPathSum(TreeNode* root) {
        int _max = -1001;        // record the max for the left + root->val + right
        int rootmax = -1001;
        count(root,_max,rootmax);
        return max(_max,rootmax);
    }
    int count(TreeNode *root, int &_max, int &rootmax){
        int tempmax = 0;
        if(root->left == NULL && root->right==NULL){
            if(rootmax < root->val)
                rootmax = root->val;
            return 0;
        }
        if(root->left!=NULL)
            count(root->left,_max,rootmax);
        if(root->right!=NULL)
            count(root->right,_max,rootmax);
        int templeft = 0;
        int tempright = 0;
        if(root->left != NULL)
            templeft = root->left->val;
        if(root->right != NULL)
            tempright = root->right->val;
        if(_max < root->val + templeft + tempright)
            _max = root->val + templeft + tempright;
        tempmax = max(templeft,tempright);
        if(tempmax>0)
            root->val = tempmax + root->val;
        if(rootmax < root->val)
            rootmax = root->val;
        return 0;
    }
};