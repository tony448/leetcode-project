class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0,right=nums.size(),middle=0;
        if(target>nums[nums.size()-1])
            return nums.size();
        else
            if(target<nums[0])
                return 0;
        while(left<=right){
            middle=left+(right-left)/2;
            if(nums[middle]==target)
                return middle;
            else
                if(nums[middle]>target)
                    right=middle-1;
            else
                left=middle+1;
        }
        if(nums[left]>target)
            return left;
        else
            if(nums[right]<target)
                return right+1;
        return left;
    }
};