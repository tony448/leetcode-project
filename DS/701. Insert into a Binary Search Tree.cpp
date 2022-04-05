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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* in=new TreeNode();
        in->val=val;
        in->left=NULL;
        in->right=NULL;
        if(root==NULL){
            root=in;
            in->val=val;
        }
        else
            insert(root,val,in);
        return root;
    }
    void insert(TreeNode* root,int val,TreeNode* &in){
        if(val>root->val){
            if(root->right!=0)
                insert(root->right,val,in);
            else
                root->right=in;
        }
        else{
            if(root->left!=0)
                insert(root->left,val,in);
            else
                root->left=in;
        }
    }
};