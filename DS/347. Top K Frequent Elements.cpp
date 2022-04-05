class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> ans;
        unordered_map<int,int>::iterator iter;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            iter = ans.find(nums[i]);
            if(iter != ans.end()){
                iter->second++;
            }
            else
            {
                ans.insert(pair<int,int>(nums[i],1));
            }
        }
        priority_queue<pair<int,int>> pq;
        for(iter = ans.begin();iter!= ans.end();iter++){
            pq.push(make_pair(iter->second,iter->first));
        }
        for(int i=0;i<k;i++){
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        return result;
    }
};