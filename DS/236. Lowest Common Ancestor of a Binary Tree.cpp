/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *child;
        TreeNode *child1;
        bool one = false;
        bool two = false;
        
        if(root->val==p->val || root->val==q->val)
            return root;
        child=find(root->left,p,q,one,two);
        child1=find(root->right,p,q,one,two);
        //cout<<child->val;
        if(child!=NULL && child1!=NULL)
            return root;
        else
            if(child==NULL)
                return child1;
        return child;
    }
    TreeNode *find(TreeNode *&root,TreeNode *&p,TreeNode *&q,bool &one ,bool &two){
        TreeNode *child;
        TreeNode *child1;
        if(root==NULL)
            return NULL;
        cout<<root->val<<endl;
        if(root->val == p->val || root->val == q->val)
            return root;
        else
        {
            child = find(root->left,p,q,one,two);
            child1 = find(root->right,p,q,one,two);
        }
        if(child != NULL && child1 != NULL)
            return root;
        if(child != NULL && child1 == NULL)
            return child;
        else
            if(child == NULL && child1 != NULL)
                return child1;
        return NULL;
    }
};