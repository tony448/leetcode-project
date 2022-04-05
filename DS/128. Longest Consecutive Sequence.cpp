class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return 1;
        sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size();i++){
        //     cout<<nums[i]<<" ";
        // }
        cout<<endl;
        int counter = 0 ;
        int max = 0;
        bool hold = false; 
        for(int i=0;i<nums.size()-1;i++){
            // cout<<counter<<" ";
            if(nums[i+1]-nums[i]==1 || nums[i+1]-nums[i]==0){
                if(nums[i+1]-nums[i]==0)
                    continue;
                counter++;
            }
            else
                if(counter>max){
                    max = counter;
                    counter = 0;
                }
            else
                counter = 0;
            // cout<<counter<<" ";
        }
        if(counter>max){
            max = counter+1;
            return max;
        }
            
        return max+1;
    }
};