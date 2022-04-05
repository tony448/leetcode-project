class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int start = -1;
        int end = nums.size()-1;
        vector<int> empty;
        vector<vector<int> > ans;
        if(nums.size()==0)
            return ans;
        ans.push_back(empty);
        perm(nums,start,end,ans,empty);
        if(ans[ans.size()-1].size()==0)
            ans.pop_back();
        return ans;
    }
    int perm(vector<int>nums,int start ,int end, vector<vector<int> > &ans,vector<int>empty){
        start++;
        if(start > end){
            for(int i=0;i<nums.size();i++)
                cout<<nums[i];
            ans[ans.size()-1] = nums;
            ans.push_back(empty);
            return 0;
        }
        for(int i=start;i<=end;i++){
            swap(nums[start],nums[i]);
            perm(nums,start,end,ans,empty);
            swap(nums[start],nums[i]);
        }
        return 0;
    }
};