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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode *> input;
        int level=0;
        if(root!=NULL)
            input.push(root);
        return leveltraversal(level,input);
    }
    bool leveltraversal(int level,queue<TreeNode *> &input){
        if(input.empty()){
            return true;
        }
        queue<TreeNode *>temp;
        if(level%2==0){       //even tree condition
            while(input.empty()!=1){
                int frontnum = input.front()->val;
                if(frontnum%2!=1)
                    return false;
                if(input.front()->left != NULL)
                    temp.push(input.front()->left);
                if(input.front()->right != NULL)
                    temp.push(input.front()->right);
                input.pop();
                if(input.empty()==1)
                    return leveltraversal(++level,temp);
                if(frontnum >= input.front()->val)
                    return false;
            }
        }
        else
            if(level%2!=0){
                while(input.empty()!=1){
                    int frontnum = input.front()->val;
                    if(frontnum%2 != 0)
                        return false;
                    if(input.front()->left != NULL)
                        temp.push(input.front()->left);
                    if(input.front()->right != NULL)
                        temp.push(input.front()->right);
                    input.pop();
                if(input.empty())
                    return leveltraversal(++level,temp);
                if(frontnum <= input.front()->val)
                    return false;
                }
            }
        return true;
    }
};