class Solution {
public:
    static inline void GetPosFromIdx(int& i, int& j, int index, int n) {
        // question, if n > m?
        i = index / n;
        j = index % n;
    }
    
    bool BianrySearch(vector<vector<int>>& matrix, int s, int e, int tgt){
        int mid = (s+e)  /2;
        int i, j;
        GetPosFromIdx(i, j, mid, matrix.at(0).size());
        if(matrix[i][j] == tgt){
            return true;
        }
        if(s>=e){
            return false;
        }
        // GetPosFromIdx(i, j, , <#int n#>)
        if(matrix[i][j] > tgt){
            return BianrySearch(matrix, s, mid - 1, tgt);
        } else {
            return BianrySearch(matrix, mid + 1, e, tgt);
        }
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int len = m * n;
        return BianrySearch(matrix, 0, len-1, target);
        return false;
    }
};