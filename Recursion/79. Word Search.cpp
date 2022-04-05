class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<int> _temp(board[0].size(),0);
        vector<vector<int>> record(board.size(),_temp);
        int counter = 0;
        bool find = false;
        for(int i=0;i<record.size();i++){
            for(int j=0;j<record[0].size();j++){
                 find = dfs(board,record,i,j,counter,word);
                if(find == true)
                    return find;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, vector<vector<int>> &record,int i,int j,int counter,string &word){
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        bool finish = false;
        if(counter == word.size()-1 && board[i][j] == word[counter])
            return true;
        if(board[i][j] == word[counter]){
            record[i][j] = 1;
            for(int k=0;k<4;k++){
                int newx = i+dir[k][0];
                int newy = j+dir[k][1];
                if(newx>=0 && newx<board.size() && newy>=0 && newy<board[0].size() && record[newx][newy]==0)
                    finish = dfs(board,record,newx,newy,counter+1,word);
                if(finish == true)
                    return true;
            }
        }
        record[i][j] = 0;
        return false;
    }
};