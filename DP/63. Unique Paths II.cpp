class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int width = obstacleGrid[0].size();
        const int length = obstacleGrid.size();
        vector<int> temp(obstacleGrid[0].size(),0);
        vector<vector<int> > dp(obstacleGrid.size(),temp);
        if(obstacleGrid[0][0] == 1)
            return 0;
        dp[0][0] = 1;
        for(int i=0;i<length;i++){
            for(int j=0;j<width;j++){
                if(i==0 && j==0)
                    continue;
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    if(i-1>=0 && j-1>=0)
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                else
                    if(i-1>=0 && j-1<=0)
                        dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        // print(dp);
        return dp[length-1][width-1];
    }
    int print(vector<vector<int> >&temp){
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