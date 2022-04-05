class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)
            return -1;
        int left=0,right=nums.size()-1,middle=left+(right-left)/2;
        while(left<right){
            if(nums[middle]>nums[right]){
                left=middle+1;
                middle=left+(right-left)/2;
            }
            else
            {
                right=middle;
                middle=left+(right-left)/2;
            }
        }
        cout<<left;
        int start=left;
        left=0;
        right=nums.size()-1;
        if(nums[start]<=target && target<=nums[right]){
            left=start;
        }
        else
            right=start;
        while(left<=right){
            middle=left+(right-left)/2;
            if(nums[middle]==target)
                return middle;
            else
                if(nums[middle]>target){
                    right=middle-1;
                }
            else
                left=middle+1;
        }
        return -1;
    }
};