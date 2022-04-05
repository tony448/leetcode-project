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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1;
        vector<int> tree2;
        vector<int> ans;
        int tree1counter=0;
        int tree2counter=0;
        if(root1 != NULL)
            traversal(root1,tree1);
        if(root2 != NULL)
            traversal(root2,tree2);
        for(int i=0;i<tree2.size();i++){
            cout<<tree2[i];
        }
        while(1){
            if(tree1counter==tree1.size() || tree2counter==tree2.size())
                break;
            if(tree1[tree1counter]<=tree2[tree2counter]){
                ans.push_back(tree1[tree1counter]);
                    tree1counter++;
            }
            else
            {
                ans.push_back(tree2[tree2counter]);
                    tree2counter++;
            }
        }
        cout<<tree1counter<<" "<<tree2counter;
        if(tree1counter<tree1.size())
            while(tree1counter<tree1.size()){
                ans.push_back(tree1[tree1counter]);
                    tree1counter++;
            }
        else
            if(tree2counter<tree2.size())
                while(tree2counter<tree2.size()){
                    ans.push_back(tree2[tree2counter]);
                        tree2counter++;
                }
        
        return ans;
    }
    void traversal(TreeNode *root ,vector<int> &tree){
        if(root->left != NULL)
            traversal(root->left,tree);
        tree.push_back(root->val);
        if(root->right != NULL)
            traversal(root->right,tree);
    }
};