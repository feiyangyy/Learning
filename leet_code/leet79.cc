class Solution {
public:
    bool dfs2(int i, int j, int cnt, vector<vector<char>>& board, string& word){
        int m = board.size();
        int n = board.at(0).size();
        // cut off
        if(i < 0 || i>=m || j <0 || j>=n || board[i][j] != word[cnt]){
            return false;
        }
        ++cnt;
        if(cnt == word.length()){
            return true;
        }
        // 防止重复访问(下面的递归可能会回溯到本位置，但是此位置已经用过了!!!!)
        // 参考生成排列组合的题目
        board[i][j] = 0;
        bool res =  dfs2(i-1, j, cnt, board, word) | dfs2(i+1, j, cnt, board, word) | dfs2(i, j-1, cnt, board, word) | dfs2(i, j + 1, cnt, board, word);
        board[i][j] = word[cnt-1];
        return res;

    }
    bool exist(vector<vector<char>>& board, string word) {
        bool res=false;
        int cnt = 0;
        for(int idx = 0; idx<board.size(); ++idx){
            for(int j = 0; j< board[0].size(); ++j){
                if(dfs2(idx, j, 0, board, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};