class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),INT_MAX-1);
        dp[0] = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=1;j<=nums[i];j++){
                if(i+j<nums.size())
                    dp[i+j] = min(dp[i+j],dp[i]+1);
                else
                    break;
            }
        }
        // print(dp);
        return dp[nums.size()-1];
    }
    int print(vector<int> &temp){
        for(int i=0;i<temp.size();i++){
            cout<<temp[i]<<" ";
        }
        cout<<endl;
        return 0;
    }
};