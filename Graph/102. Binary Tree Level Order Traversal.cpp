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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        queue<TreeNode *> input;
        vector<int> add;
        int level=0;
        input.push(root);
        if(root==0)
            return ans;
        else{
            ans.push_back(add);
            print(input,ans,level);
        }
            
        return ans;
    }
    int print(queue<TreeNode *> input,vector<vector<int> > &ans,int level){
        vector<int> add;
        TreeNode *temp;
        queue<TreeNode *> child;
        while(input.empty()!=1){
            temp=input.front();
            ans[level].push_back(temp->val);
            if(temp->left!=0)
                child.push(temp->left);
            if(temp->right!=0)
                child.push(temp->right);
            input.pop();
        }
        level++;
        if(child.empty())
            return 0;
        else{
            ans.push_back(add);
            print(child,ans,level);
        }
        
        return 0;
    }
    
};