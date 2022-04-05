class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==1)
            return 1;
        vector<int> ans(nums.size(),0);
        ans[nums.size()-1] = 1;
        int current_max = 0;
        for(int i=nums.size()-2;i>=0;i--){
            find(nums,i,current_max,ans);
        }
        return current_max;
    }
    
    int find(vector<int> &nums,int &i,int &current_max,vector<int> &ans){     // i is index 
        int large = i;
        bool find = false;
        for(int k=i;k<nums.size();k++){
            if(nums[k] > nums[i]){
                if(ans[k]>ans[large]){
                    find = true;
                    large = k;
                }
            }
        }
        if(find == false)
            ans[i] = 1;
        else
            ans[i] = ans[large] + 1;
        if(current_max < ans[i])
            current_max = ans[i];
        return 0;
    }
    
    int print(vector<int> temp){
        for(int i=0;i<temp.size();i++){
            cout<<temp[i]<<" ";
        }
        cout<<endl;
        return 0;
    }
};