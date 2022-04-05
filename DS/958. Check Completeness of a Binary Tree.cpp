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
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL || (root->left == NULL && root->right == NULL))
            return true;
        queue<TreeNode *> check;
        int number = 1;
        check.push(root);
        return checkcomplete(check,number);
    }
    bool checkcomplete(queue<TreeNode *> &temp, int number){
        queue<TreeNode *> check;
        bool notchild = false;
        while(temp.empty()==0){
            TreeNode *t;
            if(temp.front()!= NULL)
                t = temp.front();
            if(t->left == NULL && t->right != NULL){
                return false;
            }
            if(t->left!= NULL){
                if(notchild == true)
                    return false;
                else
                    check.push(t->left);
            }
            else
                notchild = true;
                
            if(t->right!= NULL){
                if(notchild == true)
                    return false;
                else
                    check.push(t->right);
            }
            else
                notchild = true;
            temp.pop();
        }
        cout<<check.size();
        if(check.size()==0)
            return true;
        if(check.size() != number*2){
            while(check.empty()==0){
                TreeNode *t;
                if(check.front()!= NULL)
                    t = check.front();
                if(t->left == NULL && t->right == NULL)
                    check.pop();
                else
                    return false;
            }
        }
        return checkcomplete(check,number*2);
    }
};