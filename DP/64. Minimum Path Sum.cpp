class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> temp(grid[0].size(),INT_MAX);
        vector<vector<int> > dp(grid.size(),temp);
        dp[0][0] = grid[0][0];
        // print(dp);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0 && j==0)
                    continue;
                else
                    if(i-1>=0 && j-1<0)
                        dp[i][j] = dp[i-1][j] + grid[i][j];
                else
                    if(i-1<0 && j-1>=0)
                        dp[i][j] = dp[i][j-1] + grid[i][j];
                else
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
            }
        }
        // print(dp);
        return dp[grid.size()-1][grid[0].size()-1];
    }
    int print(vector<vector<int>> &temp){
        for(int i=0;i<temp.size();i++){
            for(int j=0;j<temp[0].size();j++){
                cout<<temp[i][j]<<" ";
                if(j==temp[0].size()-1)
                    cout<<endl;
            }
        }
        return 0;
    }
};