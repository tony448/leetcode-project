class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int _min = prices[0];
        vector<int> dp(prices.size(),0);
        for(int i=1;i<prices.size();i++){
            profit = max(prices[i]-_min,profit); 
            if(_min > prices[i])
                _min = prices[i];
        }
        return profit;
    }
};