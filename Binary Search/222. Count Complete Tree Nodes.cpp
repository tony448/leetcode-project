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
    int countNodes(TreeNode* root) {
        queue<TreeNode *> amount;
        int numbernode=0;
        if(root!=NULL)
            amount.push(root);
        else
            return 0;
        return count(amount,++numbernode);
    }
    int count(queue<TreeNode *> &amount , int &numbernode){
        if(amount.empty()==1)
            return numbernode;
        queue<TreeNode *> check;
        while(amount.empty()!=1){
            if(amount.front()->left != NULL){
                check.push(amount.front()->left);
                numbernode++;
            }
            if(amount.front()->right != NULL){
                check.push(amount.front()->right);
                numbernode++;
            }
            amount.pop();
        }
        return count(check,numbernode);
    }
};