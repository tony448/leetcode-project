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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<int> left;
        vector<int> right;
        int start = 0,max = 0,end = 0;
        for(int i=0;i<nums.size();i++){
            if(max<nums[i]){
                max=nums[i];
                end = i;
            }
        }
        left = copy(nums,start,end);
        start = end;
        end = nums.size()-1;
        right = copy(nums,start,end);
        return buildtree(nums);
    }
    TreeNode *buildtree(vector<int> input){
        if(input.empty())
            return NULL;
        TreeNode *root=new TreeNode();
        int max=0,end=0,start=0;
        vector<int> templeft;
        vector<int> tempright;
        for(int i=0;i<input.size();i++){
            if(max<input[i]){
                max=input[i];
                end = i;
            }
        }
        root->val = max;
        templeft=copy(input,start,end);
        start = end+1;
        end = input.size();
        tempright=copy(input,start,end);
        input.clear();
        root->left = buildtree(templeft);
        root->right = buildtree(tempright);
        return root;
    } 
    vector<int> copy(vector<int> input,int start,int end){
        vector<int> temp;
        for(int i=start;i<end;i++){
            temp.push_back(input[i]);
        }
        return temp;
    }
};