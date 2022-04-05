class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        int middle=0;
        if(nums.size()==0)
            return 0;
        while(left<right){
            middle=left+(right-left)/2;
            if(nums[right]>nums[middle]){
                right=middle;
            }
            else
                if(nums[left]<=nums[middle])
                    left=middle+1;
            cout<<left<<" "<<middle<<" "<<right;
        }
        return nums[left];
    }
};