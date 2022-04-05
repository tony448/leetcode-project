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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        bool l=false;
        bool r=false;
        TreeNode *ans = new TreeNode();
        ans = root;
        trim(root,low,high,l,r,ans);
        return root;
    }
    TreeNode* trim(TreeNode *root,int low,int high,bool &l,bool &r,TreeNode *ans){
        bool left=false;
        bool right =false;
        if(root==NULL)
            return NULL;
        if(root->val<low){
            l = true;
            return root->right;
        }
        else
            if(root->val>high){
                r = true;
                return root->left;
            }
        root->left = trim(root->left,low,high,left,right,ans);
        root->right = trim(root->right,low,high,left,right,ans);
        // l = left;
        // r = right;
        // if(left == true && right == true){
        //     ans = root;
        //     // ans->left = root->left;
        //     // ans->right = root->right;
        //     // cout<<ans->val;
        //     // cout<<ans->left->val;
        //     // // cout<<ans->right->val;
        // }
            
        return root;
    }
};