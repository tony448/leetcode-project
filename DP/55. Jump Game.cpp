class Solution {
public:
    bool canJump(vector<int>& nums) {
        queue<pair<int,int>> input;
        pair<int,int> node;
        if(nums.size()==1)
            return true;
        input.push({0,nums[0]});
        return find(nums,input);
    }
    bool find(vector<int> &nums, queue<pair<int,int>> &input){
        if(input.size()==0)
            return false;
        bool result = false;
        int size = input.size();
        for(int j=0;j<size;j++){
            pair<int,int> temp = input.front();
            for(int i=1;i<temp.second+1;i++){
                if(nums[temp.first+i] < 0)
                    continue;
                if(temp.first+i>=nums.size()-1){
                    return true;
                }
                else{
                    input.push({temp.first+i,nums[temp.first+i]});
                    nums[temp.first+i] = -nums[temp.first+i];
                }
            }
            input.pop();
        }
        
        return find(nums,input);
    } 
};