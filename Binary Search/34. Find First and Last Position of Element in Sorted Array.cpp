class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        binarysearch(nums,target,ans);
        return ans;
    }
    int find(int middle,vector<int> &nums,vector<int>&ans){
        int left = middle;
        int right = middle;
        while(left-1>=0 && nums[left]==nums[left-1]){
            left--;
        }
        if(left<0)
            ans.push_back(0);
        else
            ans.push_back(left);
        while(right+1<=nums.size()-1 && nums[right]==nums[right+1]){
            right++;
        }
        if(right>=nums.size())
            ans.push_back(nums.size()-1);
        else
            ans.push_back(right);
        return 0;
    }
    int binarysearch(vector<int>&nums,int target,vector<int>&ans){
        int left,right,middle;
        left = 0;
        right = nums.size()-1;
        while(left<=right){
            middle = (left + right)/2;
            cout<<nums[middle];
            if(nums[middle]==target){
                find(middle,nums,ans);
                return 0;
            }
            else
                if(nums[middle] > target)
                    right = middle-1;
                else
                    if(nums[middle] < target)
                        left = middle +1;
        }
        ans.push_back(-1);
        ans.push_back(-1);
        return 0;
    }
};