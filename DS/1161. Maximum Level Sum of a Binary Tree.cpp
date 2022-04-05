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
    int maxLevelSum(TreeNode* root) {
        int max=0;
        int level=1;
        queue<TreeNode *> sum;
        sum.push(root);
        return findmax(sum,max,level,level);
    }
    int findmax(queue<TreeNode *> &sum,int &max,int level,int maxlevel){
        int temp=0;
        queue<TreeNode *> levelsum;
        while(sum.empty()==0){
            TreeNode *tempnode = sum.front();
            if(tempnode!=NULL){
                temp+=tempnode->val;
                if(tempnode->left!=NULL)
                    levelsum.push(tempnode->left);
                if(tempnode->right!=NULL)
                    levelsum.push(tempnode->right);
            }
            sum.pop();
        }
        if(temp > max || level==1){
            max = temp;
            maxlevel = level;
        }
        if(levelsum.empty()==1)
            return maxlevel;
        return findmax(levelsum,max,++level,maxlevel);
    }
};