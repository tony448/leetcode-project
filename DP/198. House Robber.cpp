class Solution {
public:
    int rob(vector<int>& nums) {
        int length = nums.size();
        vector<int> dp(nums.size(),0);
        if(nums.size()==1)
            return nums[0];
        else
            if(nums.size()==2)
                return max(nums[0],nums[1]);
        dp[0] = nums[0];
        dp[1] = nums[1];
        for(int i=2;i<nums.size();i++){
            for(int j=i;j<i-1;j++){
                dp[i] = max(dp[i],dp[j] + nums[i]);
            }
        }
        return max(dp[length-1],dp[length-2]);
    }
    int print(vector<int> &temp){
        for(int i=0;i<temp.size();i++){
            cout<<temp[i]<<" ";
        }
        cout<<endl;
        return 0;
    }
};