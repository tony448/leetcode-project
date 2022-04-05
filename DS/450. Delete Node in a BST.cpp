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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return NULL;
        else
            if(key > root->val){
                root->right = deleteNode(root->right,key);
            }
        else
            if(key < root->val){
                root->left = deleteNode(root->left,key);
            }
        else
            if(key == root->val){
                if(root->left == NULL && root->right == NULL){
                    return NULL;
                }
                else
                    if(root->left != NULL && root->right !=NULL){
                        TreeNode *min = root->right;
                        while(min->left != NULL){
                            min = min->left;
                        }
                        root->val = min->val;
                        root->right = deleteNode(root->right,min->val);
                    }
                else
                    if(root->left == NULL || root->right == NULL){
                        if(root->left != NULL)
                            return root->left;
                        else
                            return root->right;
                    }
            }
        return root;
    }
};